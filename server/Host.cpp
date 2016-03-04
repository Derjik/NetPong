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

#include "Host.hpp"

using namespace std;


/*
 * Default constructor
 */
Host::Host()
{}

/*
 * Main constructor (copies the arguments)
 */
Host::Host(sockaddr_storage const address, int const socket) :
	_address(address),
	_socket(socket)
{}

/*
 * Basic destructor
 */
Host::~Host()
{}

/*
 * Comparison operator (for use with std::map, std::set &co)
 */
bool Host::operator < (Host const & remote) const
{
	return (strncmp((char*)(this),
			(char*)(&remote),
			sizeof(sockaddr_storage))) < 0;
}
