/*
 *  This file is part of the Xen Crashdump Analyser.
 *
 *  The Xen Crashdump Analyser is free software: you can redistribute
 *  it and/or modify it under the terms of the GNU General Public
 *  License as published by the Free Software Foundation, either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  The Xen Crashdump Analyser is distributed in the hope that it will
 *  be useful, but WITHOUT ANY WARRANTY; without even the implied
 *  warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the Xen Crashdump Analyser.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 *  Copyright (c) 2011,2012 Citrix Inc.
 */

#ifndef _TABLE_DECODER_PROTOS_HPP_
#define _TABLE_DECODER_PROTOS_HPP_

/**
 * @file table-decoder-protos.hpp
 * @author Andrew Cooper
 */

#include <cstring>
#include <stdint.h>
#include "bitmap.hpp"

/**
 * Table decoder.
 * Interface for all Xen Crashnote2 table decoders
 */
class TableDecoder
{
public:
    /// Constructor.
    TableDecoder(){};
    /// Destructor.
    virtual ~TableDecoder(){};

    /**
     * Decode a raw table in memory.
     * @param buff pointer to the start of the raw table
     * @param len size of the raw table
     * @returns boolean indicating success or failure
     */
    virtual bool decode(const char * buff, const size_t len) = 0;

    /// Number of entries in the table
    virtual size_t length() const = 0;
};

/// String table decoder
class StringTabDecoder: public TableDecoder
{
public:
    StringTabDecoder(){};
    virtual ~StringTabDecoder(){};

    /**
     * Decode a raw table in memory.
     * @param buff pointer to the start of the raw table
     * @param len size of the raw table
     * @returns boolean indicating success or failure
     */
    virtual bool decode(const char * buff, const size_t len) = 0;

    /// Number of entries in the table
    virtual size_t length() const = 0;

    /**
     * Get function
     * @param index Index into the table
     * @returns char pointer from table, or NULL if out of range or not present
     */
    virtual const char * get(const size_t index) const = 0;

    /**
     * is_valid function
     * @param index Index into the table
     * @returns boolean indicating whether the value was present in the crash notes
     */
    virtual bool is_valid(const size_t index) const = 0;
};

/// Value table decoder for 64bit values
class Val64TabDecoder: public TableDecoder
{
public:
    Val64TabDecoder(){};
    virtual ~Val64TabDecoder(){};

    /**
     * Decode a raw table in memory.
     * @param buff pointer to the start of the raw table
     * @param len size of the raw table
     * @returns boolean indicating success or failure
     */
    virtual bool decode(const char * buff, const size_t len) = 0;

    /// Number of entries in the table
    virtual size_t length() const = 0;

    /**
     * Get function
     * @param index Index into the table
     * @returns integer from table, or invalid if out of range or not present
     */
    virtual const uint64_t & get(const size_t index) const = 0;

    /**
     * is_valid function
     * @param index Index into the table
     * @returns boolean indicating whether the value was present in the crash notes
     */
    virtual bool is_valid(const size_t index) const = 0;
};

/// Symbol table decoder for 64bit symbols
class Sym64TabDecoder: public TableDecoder
{
public:
    Sym64TabDecoder(){};
    virtual ~Sym64TabDecoder(){};

    /**
     * Decode a raw table in memory.
     * @param buff pointer to the start of the raw table
     * @param len size of the raw table
     * @returns boolean indicating success or failure
     */
    virtual bool decode(const char * buff, const size_t len) = 0;

    /// Number of entries in the table
    virtual size_t length() const = 0;

    /**
     * Get function
     * @param index Index into the table
     * @returns integer from table, or 0 if out of range or not present
     */
    virtual const uint64_t & get(const size_t index) const = 0;

    /**
     * is_valid function
     * @param index Index into the table
     * @returns boolean indicating whether the value was present in the crash notes
     */
    virtual bool is_valid(const size_t index) const = 0;
};

#endif /* _TABLE_DECODER_PROTOS_HPP_ */

/*
 * Local variables:
 * mode: C++
 * c-set-style: "BSD"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */
