/*
 * StrBlobPtr.cpp
 *
 *  Created on: 2016Äê9ÔÂ15ÈÕ
 *      Author: songx
 */

#include "StrBlobPtr.h"

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, data->size());
}

string & StrBlobPtr::operator[](size_t n) {
	auto p = check(n, "Index out of bounds:" + n);
	return (*p)[n];
}
const string & StrBlobPtr::operator[](size_t n) const {
	auto p = check(n, "Index out of bounds:" + n);
	return (*p)[n];
}

StrBlobPtr & StrBlobPtr::operator++() {
	check(currIndex, "Index out of bounds:" + currIndex);
	++currIndex;
	return *this;
}
StrBlobPtr & StrBlobPtr::operator--() {
	--currIndex;
	check(currIndex, "Index out of bounds:" + currIndex);
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
	auto ret = *this;
	++currIndex;
	return *this;
}
StrBlobPtr StrBlobPtr::operator--(int) {
	auto ret = *this;
	--currIndex;
	return *this;
}

StrBlobPtr operator+(const StrBlobPtr & ptr, size_t inc) {
	StrBlobPtr ret = ptr;
	ret.currIndex += inc;
	return ret;
}
StrBlobPtr operator-(const StrBlobPtr & ptr, size_t dec) {
	StrBlobPtr ret = ptr;
	ret.currIndex -= dec;
	return ret;
}


string & StrBlobPtr::operator*(){
	auto p = check(currIndex,"dereference past end");
	return (*p)[currIndex];
}

string * StrBlobPtr::operator->(){
	return & this->operator*();
}

void test10(){
	StrBlobPtr p;
	p = p+4;
}
