/*
 * ConstStrBlobPtr.cpp
 *
 *  Created on: 2016年9月16日
 *      Author: songx
 */

#include "ConstStrBlobPtr.h"

#include <vector>



const string & ConstStrBlobPtr::operator*() const {
	auto p = check(currIndex,"dereferences past the end");
	return (*p)[currIndex];
}

const string * ConstStrBlobPtr::operator->() const {
	return & this->operator*();
}

ConstStrBlobPtr StrBlob::cbegin() const { //这里加了const
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::cend() const { //这里加了const
	return ConstStrBlobPtr(*this, data->size());
}
