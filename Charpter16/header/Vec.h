/*
 * Vec.h
 *
 *  Created on: 2016年9月28日
 *      Author: songx
 */

#ifndef VEC_H_
#define VEC_H_

#include <stddef.h>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>

using namespace std;
template<typename T>class Vec;
template <typename T>
bool operator==(const Vec<T> & lhs,const Vec<T> & rhs);

template <typename T>
bool operator!=(const Vec<T> & lhs,const Vec<T> & rhs);

template <typename T>
bool operator< (const Vec<T> & lhs,const Vec<T> & rhs);


template <typename T>class Vec {
	friend bool operator==<T>(const Vec<T> & lhs,const Vec<T> & rhs);
	friend bool operator!=<T>(const Vec<T> & lhs,const Vec<T> & rhs);
	friend bool operator< <T>(const Vec<T> & lhs,const Vec<T> & rhs);
public:
	Vec() :
			elements(nullptr), firstFree(nullptr), cap(nullptr) {
	}
	Vec(initializer_list<T> list) {
		elements = alloc.allocate(list.size());
		cap = firstFree = uninitialized_copy(list.begin(), list.end(),
				elements);
	}
	Vec(const Vec &);
	Vec & operator=(const Vec &);
	~Vec();

	Vec(Vec &&) noexcept;
	Vec & operator=(Vec &&) noexcept;
	Vec & operator=(Vec );
	Vec & operator=(initializer_list<T> list);
	T & operator[](size_t n);
	const T & operator[](size_t n)const;
	
	
	size_t size() const {
		return firstFree - elements;
	}
	size_t capacity() const {
		return cap - elements;
	}
	void push_back(const T &);
	void push_back(T &&);
	T *begin() const {
		return elements;
	}
	T *end() const {
		return firstFree;
	}
	void resize(size_t size, const T&);
	void reserve(size_t);
private:
	allocator<T> alloc;
	T * elements;
	T * firstFree;
	T * cap;

	void check_n_copy() {
		if (size() == capacity()) {
			auto newCapacity = size() != 0 ? 2 * size() : 1;
			reallocate(newCapacity);
		}
	}
	pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
	void reallocate(size_t);
};

//implement********************************************************************************************
template <typename T>
void Vec<T>::push_back(const T & e) {
	check_n_copy();
	alloc.construct(firstFree++, e);
	//第一个参数是指针，指向微构造的内存空间，剩余参数确定用哪个构造函数来构造对象(这里调用的是T的拷贝构造)
}
template <typename T>
void Vec<T>::push_back(T &&e) {
	check_n_copy();
	alloc.construct(firstFree++, move(e));
}

template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T *begin,
		const T *end) {
	auto start = alloc.allocate(end - begin);
	return {start,uninitialized_copy(begin,end,start)}; //拷贝函数返回尾后指针
}
template <typename T>
void Vec<T>::free() {
	if (elements) {
		for_each(elements, firstFree,
				[this]( T & ptr) {alloc.destroy(&ptr);});
		/*for (auto ptr = firstFree; ptr != elements;) {
		 alloc.destroy(--ptr);
		 }*/
		alloc.deallocate(elements, cap - elements); //第一个参数是当时创建返回的指针，第二个参数是分配的元素个数
	}
}
template <typename T>
Vec<T>::Vec(const Vec & vec) {
	auto newData = alloc_n_copy(vec.begin(), vec.end());
	elements = newData.first;
	firstFree = cap = newData.second;
}
template <typename T>
Vec<T>::~Vec() {
	free();
}

template <typename T>
Vec<T> & Vec<T>::operator =(const Vec & vec) {
	auto newData = alloc_n_copy(vec.begin(), vec.end());
	free();
	elements = newData.first;
	firstFree = cap = newData.second;
	return *this;
}
template <typename T>
void Vec<T>::resize(size_t newSize, const T & s) {
	reallocate(newSize);
	if (newSize > size()) {
		auto addedSize = newSize - size();
		for (size_t i = 0; i != addedSize; i++) {
			alloc.construct(firstFree++, s);
		}
	} else if (newSize < size()) {
		while (firstFree != elements + newSize) {
			alloc.destroy(--firstFree);
		}
	}
}
template <typename T>
void Vec<T>::reserve(size_t newSize) {
	if (newSize > capacity()) {
		reallocate(newSize);
	}
}
template <typename T>
Vec<T>::Vec(Vec && vec) noexcept :elements(vec.elements),firstFree(vec.firstFree),cap(vec.cap) {
	vec.elements = vec.cap = vec.firstFree = nullptr;
	cout<<"call Vec(Vec && vec)"<<endl;
}
template <typename T>
Vec<T> &Vec<T>::operator=(Vec && vec) noexcept {
	if (&vec != this) {
		free();
		elements = vec.elements;
		firstFree = vec.firstFree;
		cap = vec.cap;
		vec.elements = vec.firstFree = vec.cap = nullptr;
	}
	return *this;
}

template <typename T>
void Vec<T>::reallocate(size_t newCapacity) {
	auto newData = alloc.allocate(newCapacity);
	/*for (size_t i = 0; i != size() && i != newCapacity; i++) {
	 alloc.construct(newStart++, std::move(*oldStart++));
	 }*/
	auto newEnd = uninitialized_copy(make_move_iterator(begin()),
			make_move_iterator(end()), newData);
	free();
	elements = newData;
	firstFree = newEnd;
	cap = elements + newCapacity;
}
template <typename T>
bool operator==(const Vec<T> & lhs, const Vec<T> & rhs) {
	if (lhs.size() == rhs.size()) {
		for (auto beginL = lhs.begin(), beginR = rhs.begin();
				beginL != lhs.end(); beginL++, beginR++) {
			if (*beginL != *beginR) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}

template <typename T>
bool operator!=(const Vec<T> & lhs, const Vec<T> & rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vec<T> & lhs, const Vec<T> & rhs) {
	size_t i = 0;
	for (auto beginL = lhs.begin(), beginR = rhs.begin();
			i != lhs.size() && i != rhs.size(); beginL++, beginR++, i++) {
		if (*beginL < *beginR) {
			return true;
		}
	}
	if (i == lhs.size()) {
		return true;
	} else {
		return false;
	}
}
template <typename T>
Vec<T> & Vec<T>::operator=(initializer_list<T> list){
	auto pair = alloc_n_copy(list.begin(),list.end());
	free();
	elements = pair.first;
	cap = firstFree = pair.second;
	return *this;
}
template <typename T>
T & Vec<T>::operator[](size_t n){
	return elements[n];
}
template <typename T>
const T & Vec<T>::operator[](size_t n)const{
	return elements[n];
}



#endif /* VEC_H_ */
