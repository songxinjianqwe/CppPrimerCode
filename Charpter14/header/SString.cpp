/*
 * String.cpp
 *
 *  Created on: 2016Äê9ÔÂ15ÈÕ
 *      Author: songx
 */

#include <SString.h>
#include <algorithm>

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
ostream & operator<<(ostream &os, const String &str) {
	auto begin = str.elements;
	while (begin != str.firstFree) {
		os << *begin++;
	}
	return os;
}
istream & operator>>(istream &is, String & str) {
	char * p = nullptr;
	is >> p;
	if (is) {
		str = String(p);
	} else {
		str = String();
	}
	return is;
}

bool operator==(const String & lhs, const String & rhs) {
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
bool operator!=(const String & lhs, const String & rhs) {
	return !(lhs == rhs);
}
bool operator<(const String & lhs, const String & rhs) {
	size_t i = 0;
	for (auto beginL = lhs.begin(), beginR = rhs.begin(); i != lhs.size() && i != rhs.size();
			beginL++, beginR++,i++) {
		if (*beginL < *beginR) {
			return true;
		}
	}
	if(i == lhs.size()){
		return true;
	}else{
		return false;
	}
}

char & String::operator[](size_t n){
	return elements[n];
}
const char & String::operator[](size_t n) const{
	return elements[n];
}
	

