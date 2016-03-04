/*
 * Copyright (c) 2016 Julien "Derjik" Laurent
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

#include "Datagram.hpp"

using namespace std;


Datagram::Datagram() : _length(0), _data(nullptr)
{}

Datagram::Datagram(uint8_t const * data,
			size_t const length,
			sockaddr_storage const * address,
			int const socket) :
	_sender(*address, socket),
	_length(length),
	_data(new uint8_t [length])
{
	memcpy(_data, data, length);
}

Datagram::Datagram(Datagram const & message) :
	_sender(message._sender),
	_length(message._length),
	_data(new uint8_t [message._length])
{
	memcpy(_data, message._data, message._length);
}

Datagram::~Datagram()
{
	delete [] _data;
}

Datagram & Datagram::operator = (Datagram const & message)
{
	if(&message != this)
	{
		delete[] _data;
		_data = new uint8_t[message._length];

		_sender = message._sender;
		_length = message._length;
		memcpy(_data, message._data, message._length);
	}

	return (*this);
}
