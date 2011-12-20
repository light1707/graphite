/*  GRAPHITE2 LICENSING

    Copyright 2010, SIL International
    All rights reserved.

    This library is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation; either version 2.1 of License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should also have received a copy of the GNU Lesser General Public
    License along with this library in the file named "LICENSE".
    If not, write to the Free Software Foundation, 51 Franklin Street,
    Suite 500, Boston, MA 02110-1335, USA or visit their web page on the
    internet at http://www.fsf.org/licenses/lgpl.html.

Alternatively, the contents of this file may be used under the terms of the
Mozilla Public License (http://mozilla.org/MPL) or the GNU General Public
License, as published by the Free Software Foundation, either version 2
of the License or (at your option) any later version.
*/
// JSON pretty printer for graphite font debug output logging.
// Created on: 15 Dec 2011
//     Author: Tim Eves

#pragma once

#include <cassert>
#include <cstdio>

namespace graphite2 {

class json
{
	typedef void (*_context_t)(json &);
	class _null_t {};

	FILE * const 	_stream;
	char 			_contexts[128],
				  * _context,
				  * _flatten;

	void context(const char current) throw();
	void indent(const int d=0) throw();
	void push_context(const char, const char) throw();
	void pop_context() throw();

public:
	typedef const char *	string;
	typedef double			number;
	typedef int				integer;
	typedef bool			boolean;
	static const _null_t	null;

	static void flat(json &) throw();
	static void close(json &) throw();
	static void object(json &) throw();
	static void array(json &) throw();

	json(FILE * stream) throw();
	~json() throw ();

	json & operator << (string) throw();
	json & operator << (number) throw();
	json & operator << (integer) throw();
	json & operator << (boolean) throw();
	json & operator << (_null_t) throw();
	json & operator << (_context_t) throw();
};


inline
json::json(FILE * stream) throw()
: _stream(stream), _context(_contexts), _flatten(0)
{
	assert(stream != 0);
	*_context = '\0';
	fflush(_stream);
	setbuf(_stream, 0);
}

} // namespace graphite2
