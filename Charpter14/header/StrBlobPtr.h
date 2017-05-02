/*
 * StrBlobPtr.h
 *
 *  Created on: 2016年9月15日
 *      Author: songx
 */

#ifndef STRBLOBPTR_H_
#define STRBLOBPTR_H_

#include <vector>
#include "StrBlob.h"
class StrBlobPtr {
	friend StrBlobPtr operator+(const StrBlobPtr & ,size_t inc);
	friend StrBlobPtr operator-(const StrBlobPtr & ,size_t dec);
public:
	using sizeType = vector<string>::size_type;
	StrBlobPtr() :
			currIndex(0) {
	}
	StrBlobPtr(StrBlob &sb, sizeType sz = 0) :
			wptr(sb.data), currIndex(sz) {
	}
	string & deref() const { //代替运算符*，解引用
		auto sp = check(currIndex, "dereference past end");
		return (*sp)[currIndex]; //对指向vector的指针进行下标运算，先解引用，括号外面加下标
	}
	StrBlobPtr & inc() {
		check(currIndex, "increment past end of StrBlobPtr");
		currIndex++;
		return *this;
	}
	bool operator!=(const StrBlobPtr& p) {
		return p.currIndex != currIndex;
	}
	string & operator[](size_t n);
	const string & operator[](size_t n)const;
	
	StrBlobPtr & operator++();
	StrBlobPtr & operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	string & operator*();
	string * operator->();
	
	
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


#endif /* STRBLOBPTR_H_ */
