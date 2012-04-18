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

/**
 * @file sym64-table-decoders.hpp
 * @author Andrew Cooper
 */

#ifndef _SYM64_TABLE_DECODERS_HPP
#define _SYM64_TABLE_DECODERS_HPP


#include "table-decoder-protos.hpp"

/**
 * Symbol table decoder for 64bit CORE files
 */
class x64Sym64TabDecoder: public Sym64TabDecoder
{
public:
    /// Constructor
    x64Sym64TabDecoder();
    /// Destructor
    virtual ~x64Sym64TabDecoder();

    /**
     * Decode a raw table in memory.
     * @param buff pointer to the start of the raw table
     * @param len size of the raw table
     * @returns boolean indicating success or failure
     */
    virtual bool decode(const char * buff, const size_t len);

    /// Number of entries in the table
    virtual size_t length() const;

    /**
     * Get function
     * @param index Index into the table
     * @returns char pointer from table, or NULL if out of range or not present
     */
    virtual const uint64_t & get(const size_t index) const;

    /**
     * is_valid function
     * @param index Index into the table
     * @returns boolean indicating whether the value was present in the crash notes
     */
    virtual bool is_valid(const size_t index) const;

protected:
    /// Actual table
    uint64_t * table;
    /// Bitmap of validity of table entries
    Bitmap * valid;
    /// Number of table entries
    size_t nr_entries;
};

#endif /* _SYM64_TABLE_DECODERS_HPP */

/*
 * Local variables:
 * mode: C++
 * c-set-style: "BSD"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */
