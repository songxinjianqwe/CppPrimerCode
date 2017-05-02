/*
 * StrVec.cpp
 *
 *  Created on: 2016年9月13日
 *      Author: songx
 */

//当定义一个类的时候，要将类的声明，包括成员变量、成员函数的声明和部分函数定义放在头文件中，将没有定义的成员函数的定义放在同名的.cpp文件中


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

//写一个类似于vector的类型，但仅存储string元素
//vector的添加元素的函数会检查是否有空间容纳更多的元素，如果有，成员函数会在下一个可用位置构造一个对象。如果没有可用空间，vector就会重新分配空间：
//它获得新的空间，将已有元素移动到新空间中，释放旧空间，并添加新元素
//使用allocator获得原始内存，使用construc创建对象，使用destory销毁元素
//每个StrVec有三个指针：elements指向首元素；firstFree实际元素的尾后指针；cap指向分配的内存末尾之后的位置
//持有一个alloc静态成员，分配内存有4个工具函数：
//alloc_n_copy 会分配内存，并拷贝指定范围中的元素
//free会销毁构造的元素并释放内存
//check_n_copy 保证StrVec至少有容纳一个新元素的空间，如果空间不足，会调用reallocate来分配更多内存
//reallocate在内存用完时为StrVec分配内存

//const成员函数：无论对象是const还是不是const，都可以调用const成员函数；对象是const只能调用const成员函数；如果不修改数据成员，那么应该定义为const的。
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
//begin和end原本是返回迭代器，在这里返回的是指针


#endif 
