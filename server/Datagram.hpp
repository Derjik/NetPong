/*
 * Copyright (c) 2016 Julien "Derjik" Laurent <julien.laurent@engineer.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef DATAGRAM_HPP_INCLUDED
#define DATAGRAM_HPP_INCLUDED

#include "Host.hpp"


class Datagram
{
	private:
		/* Message origin */
		Host _sender;

		/* Message length */
		size_t _length;

		/* Message content */
		uint8_t* _data;

	public:
		/* Constructors */
		Datagram();
		Datagram(uint8_t const *,
				size_t const,
				sockaddr_storage const *,
				int const);
		/* Copy constructor */
		Datagram(Datagram const &);
		/* Destructor */
		virtual ~Datagram();
		/* Assign operator */
		Datagram & operator = (Datagram const &);

		/* Getters */
		inline Host const & sender() const;
		inline size_t length() const;
		inline uint8_t const * data() const;
		inline uint8_t operator [] (unsigned const) const;
};

inline Host const & Datagram::sender() const
{
	return _sender;
}

inline size_t Datagram::length() const
{
	return _length;
}

inline uint8_t const * Datagram::data() const
{
	return _data;
}

inline uint8_t Datagram::operator [] (unsigned const index) const
{
	return _data[index];
}

#endif // DATAGRAM_HPP_INCLUDED