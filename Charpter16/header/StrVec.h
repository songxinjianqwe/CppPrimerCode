/*
 * StrVec.cpp
 *
 *  Created on: 2016��9��13��
 *      Author: songx
 */

//������һ�����ʱ��Ҫ�����������������Ա��������Ա�����������Ͳ��ֺ����������ͷ�ļ��У���û�ж���ĳ�Ա�����Ķ������ͬ����.cpp�ļ���


#ifndef STRVEC_H
#define STRVEC_H
#include <ext/new_allocator.h>
#include <stddef.h>
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <utility>

using namespace std;

class StrVec {
	friend bool operator==(const StrVec & lhs,const StrVec & rhs);
	friend bool operator!=(const StrVec & lhs,const StrVec & rhs);
	friend bool operator<(const StrVec & lhs,const StrVec & rhs);
public:
	StrVec() :
			elements(nullptr), firstFree(nullptr), cap(nullptr) {
	}
	StrVec(initializer_list<string> list) {
		elements = alloc.allocate(list.size());
		cap = firstFree = uninitialized_copy(list.begin(), list.end(),
				elements);
	}
	StrVec(const StrVec &);
	StrVec & operator=(const StrVec &);
	~StrVec();

	StrVec(StrVec &&) noexcept;
	StrVec & operator=(StrVec &&) noexcept;
	StrVec & operator=(StrVec );
	StrVec & operator=(initializer_list<string> list);
	string & operator[](size_t n);
	const string & operator[](size_t n)const;
	
	
	size_t size() const {
		return firstFree - elements;
	}
	size_t capacity() const {
		return cap - elements;
	}
	void push_back(const string &);
	void push_back(string &&);
	string *begin() const {
		return elements;
	}
	string *end() const {
		return firstFree;
	}
	void resize(size_t size, const string&);
	void reserve(size_t);
	template <typename ...Args>
	void emplace_back(Args&&...);
private:
	allocator<string> alloc;
	string * elements;
	string * firstFree;
	string * cap;

	void check_n_copy() {
		if (size() == capacity()) {
			auto newCapacity = size() != 0 ? 2 * size() : 1;
			reallocate(newCapacity);
		}
	}
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate(size_t);
};

template <typename ...Args>
void StrVec::emplace_back(Args&&...args){
	check_n_copy();
	alloc.construct(firstFree++,forward<Args>(args)...);
}


#endif 
