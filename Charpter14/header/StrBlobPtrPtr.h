/*
 * StrBlobPtrPtr.h
 *
 *  Created on: 2016��9��16��
 *      Author: songx
 */

#ifndef STRBLOBPTRPTR_H_
#define STRBLOBPTRPTR_H_

class StrBlobPtrPtr{
public:
	StrBlobPtrPtr():ptr(nullptr){}
	StrBlobPtrPtr(StrBlobPtr * p):ptr(p){}
	StrBlobPtr & operator*();
	StrBlobPtr * operator->();
private:
	StrBlobPtr * ptr;
};

StrBlobPtr & StrBlobPtrPtr::operator*(){
	return *ptr;
}
StrBlobPtr * StrBlobPtrPtr::operator->(){
	return ptr;
}

#endif /* STRBLOBPTRPTR_H_ */
