/*
 * ConstStrBlobPtr.cpp
 *
 *  Created on: 2016��9��16��
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

ConstStrBlobPtr StrBlob::cbegin() const { //�������const
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::cend() const { //�������const
	return ConstStrBlobPtr(*this, data->size());
}
