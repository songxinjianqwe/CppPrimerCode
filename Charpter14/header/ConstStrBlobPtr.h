/*
 * ConstStrBlobPtr.h
 *
 *  Created on: 2016��9��16��
 *      Author: songx
 */

#ifndef CONSTSTRBLOBPTR_H_
#define CONSTSTRBLOBPTR_H_

#include "StrBlob.h"

class ConstStrBlobPtr {

public:
	using sizeType = vector<string>::size_type;
	ConstStrBlobPtr() :
			currIndex(0) {
	}
	ConstStrBlobPtr(const StrBlob &sb, sizeType sz = 0) ://�������const
			wptr(sb.data), currIndex(sz) {
	}
	const string & deref() const { //�������const
		auto sp = check(currIndex, "dereference past end");
		return (*sp)[currIndex]; 
	}
	ConstStrBlobPtr & inc() {
		check(currIndex, "increment past end of StrBlobPtr");
		currIndex++;
		return *this;
	}
	bool operator!=(const ConstStrBlobPtr& p) {
		return p.currIndex != currIndex;
	}
	const string & operator*()const;
	const string * operator->()const;
private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(sizeType i, const string & msg) const {
		auto ret = wptr.lock();
		if (!ret) {
			throw runtime_error("Unbound StrBlobPtr");
		}
		if (ret->size() <= i) {
			throw out_of_range(msg);
		}
		return ret;
	}
	sizeType currIndex;
};





#endif /* CONSTSTRBLOBPTR_H_ */
