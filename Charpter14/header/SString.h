/*
 * String.h
 *
 *  Created on: 2016Äê9ÔÂ15ÈÕ
 *      Author: songx
 */

#ifndef SSTRING_H_
#define SSTRING_H_
#include <string.h>
#include <ext/new_allocator.h>
#include <stddef.h>
#include <iostream>
#include <memory>
#include <utility>

using namespace std;

class String {
	friend ostream & operator<<(ostream &os, const String &str);
	friend istream & operator>>(istream &is,String & str);
	friend bool operator==(const String & lhs,const String & rhs);
	friend bool operator!=(const String & lhs,const String & rhs);
	friend bool operator<(const String & lhs,const String & rhs);
public:
	String() :
			elements(nullptr), firstFree(nullptr), cap(nullptr) {
	}
	String(const char * str) {
		elements = alloc.allocate(strlen(str));
		cap = firstFree = uninitialized_copy_n(str, strlen(str), elements);
	}
	String(const String &);
	String & operator=(const String &);
	String(String &&) noexcept;
	String & operator=(String &&) noexcept;
	char & operator[](size_t n);
	const char & operator[](size_t n) const;
	
	
	~String();
	char * begin() const {
		return elements;
	}
	char * end() const {
		return firstFree;
	}
	size_t size() const {
		return firstFree - elements;
	}
private:
	allocator<char> alloc;
	char * elements;
	char * firstFree;
	char * cap;
	pair<char *, char *> alloc_copy(const char *, const char *);
	void free();
};






#endif /* SSTRING_H_ */
