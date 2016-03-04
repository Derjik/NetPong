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

#ifndef HOST_HPP_INCLUDED
#define HOST_HPP_INCLUDED

#include <Mach/NetComponent.hpp>


/* Network*/
class Host
{
	private:
		/* IP address (v6 or v4)*/
		sockaddr_storage _address;

		/* Socket file descriptor */
		int _socket;

	public:
		/* Constructors & destructor */
		Host();
		Host(sockaddr_storage const, int const);
		virtual ~Host();

		/* Order operator (used for ordered mapping) */
		bool operator < (Host const &) const;

		/* Getters */
		inline sockaddr_storage const & address() const;
		inline int socket() const;
};

/*
 * Address getter
 */
inline sockaddr_storage const & Host::address() const
{
	return _address;
}

/*
 * Socket file descriptor getter
 */
inline int Host::socket() const
{
	return _socket;
}

#endif // HOST_HPP_INCLUDED
