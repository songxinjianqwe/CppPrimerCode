/*
 * BlobPtr.h
 *
 *  Created on: 2016年9月27日
 *      Author: songx
 */

#ifndef BLOBPTR_H_
#define BLOBPTR_H_

#include <stddef.h>
#include <memory>
#include <string>
#include <vector>

using namespace std;
template<typename T>
class BlobPtr;

template<typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);

template<typename T>
bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);

template<typename T>
bool operator!=(const BlobPtr<T>&, const BlobPtr<T> &);



template<typename T> class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
	friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
	friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T> &);
public:
	BlobPtr() :
			curr(0) {
	}
	BlobPtr(Blob<T> & b, size_t sz = 0) :
			wptr(b.data), curr(sz) {
	}
	T& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	BlobPtr & operator++();
	BlobPtr & operator--();
	//前置运算符
private:
	shared_ptr<vector<T>> check(size_t, const string &) const;

	weak_ptr<vector<T>> wptr;
	size_t curr;
};

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i , const string & msg) const {
	auto ret = wptr.lock();
	if (!ret) {
		throw runtime_error("Unbound StrBlobPtr");
	}
	if (ret->size() <= i) {
		throw out_of_range(msg);
	}
	return ret;

}
template<typename T>
BlobPtr<T> & BlobPtr<T>::operator++() {
	check(curr, "++");
	++curr;
	return *this;
}
template<typename T>
bool operator==(const BlobPtr<T> & lhs, const BlobPtr<T> & rhs) {
	if (lhs.wptr != rhs.wptr) {
		throw runtime_error("ptrs to different Blobs!");
	}
	return lhs.curr == rhs.curr;
}

template<typename T>
bool operator<(const BlobPtr<T> & lhs, const BlobPtr<T> & rhs) {
	if (lhs.wptr != rhs.wptr) {
		throw runtime_error("ptrs to different Blobs!");
	}
	return lhs.curr < rhs.curr;
}
template<typename T>
bool operator!=(const BlobPtr<T>& lhs , const BlobPtr<T> & rhs) {
	return lhs.curr != rhs.curr;
}
#endif /* BLOBPTR_H_ */
