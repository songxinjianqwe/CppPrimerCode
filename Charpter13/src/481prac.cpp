/*
 * 481prac.cpp
 *
 *  Created on: 2016��9��14��
 *      Author: songx
 */

#include <stddef.h>
#include <string>

using namespace std;

class HasPtr4 {
	friend void swap(HasPtr4 &, HasPtr4 &);
public:
	HasPtr4(const string & s = string()) :
			ps(new string(s)), i(0), count(new size_t(1)) {
	}
	HasPtr4(const HasPtr4 & orig) :
			ps(new string(*orig.ps)), i(orig.i), count(orig.count) {
		--*count;
	}
	HasPtr4& operator=(const HasPtr4 & hp) {
		//��Ҫ�����Ը�ֵ�����⣺�ȵ����Ҳ��������ļ��������ٵݼ����
		++*hp.count;
		--*count;
		if (*count == 0) {
			if (ps) {
				delete ps;
				ps = nullptr;
			}
			delete count;
			count = nullptr;
		}
		ps = hp.ps;
		i = hp.i;
		count = hp.count;
		return *this;
	}
	HasPtr4(HasPtr4 &&) noexcept;
	HasPtr4&operator=(HasPtr4 &&) noexcept;
	~HasPtr4() {
		--*count;
		if (*count == 0) {
			if (ps) {
				delete ps;
				ps = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}
private:
	string * ps;
	int i;
	size_t *count; //������
};

HasPtr4::HasPtr4(HasPtr4 &&rhs) noexcept:ps(rhs.ps),i(rhs.i),count(rhs.count) {
	rhs.ps = nullptr;
	rhs.count = nullptr;
}

HasPtr4& HasPtr4::operator=(HasPtr4 &&rhs) noexcept {
	if (&rhs != this) {
		if(ps){
			delete ps;
			ps = nullptr;
		}
		ps = rhs.ps;
		i = rhs.i;
		count = rhs.count;
	}
	rhs.ps = nullptr;
	rhs.count = nullptr;
	return *this;
}

