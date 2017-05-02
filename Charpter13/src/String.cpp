/*
 * String.cpp
 *
 *  Created on: 2016年9月14日
 *      Author: songx
 */

#include <ext/new_allocator.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

using namespace std;

class String {
	friend void print(ostream &os, const String &str);
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
pair<char *, char *> String::alloc_copy(const char *begin, const char *end) {
	auto newData = alloc.allocate(end - begin);
	return {newData,uninitialized_copy(begin,end,newData)};
}
String::String(const String & str) {
	auto newData = alloc_copy(str.begin(), str.end());
	elements = newData.first;
	cap = firstFree = newData.second;
	cout << "call String(const String & str)" << endl;
}
void String::free() {
	if (elements) {
		for_each(elements, firstFree,
				[this](const char& ch) {alloc.destroy(&ch);});
		alloc.deallocate(elements, cap - elements);
	}
}
String &String::operator=(const String &str) {
	auto newData = alloc_copy(str.begin(), str.end());
	free();
	elements = newData.first;
	cap = firstFree = newData.second;
	cout << "call String & operator=(const String & str)" << endl;
	return *this;
}
String::~String() {
	free();
}
String::String(String && str) noexcept :elements(str.elements),firstFree(str.firstFree),cap(str.cap) {
	str.elements = str.firstFree = str.cap = nullptr;
	cout<<"call String(String && str)"<<endl;
}
String & String::operator =(String && str) noexcept {
	if (&str != this) {
		free();
		elements = str.elements;
		firstFree = str.firstFree;
		cap = str.cap;
	}
	return *this;
}
void print(ostream &os, const String &str) {
	auto begin = str.elements;
	while (begin != str.firstFree) {
		os << *begin++;
	}
}
void test2333() {
	String str("HelloWorld");
	print(cout, str);
}
void test2334() {
	vector<String> sVec;
	sVec.push_back("111");
	sVec.push_back("222");
	sVec.push_back("333");
	//调用了6次拷贝构造函数(如果有移动构造函数，那么会调用6次移动构造函数)
}
