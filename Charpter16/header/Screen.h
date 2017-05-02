/*
 * Screen.h
 *
 *  Created on: 2016年9月28日
 *      Author: songx
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <stddef.h>
#include <string>
using namespace std;
template<size_t W,size_t H> class Screen;
template<size_t W,size_t H>
ostream & operator<<(ostream & os,const Screen<W,H> &);

template<size_t W,size_t H>
istream & operator>>(istream & is,Screen<W,H> & );


template<size_t W, size_t H> class Screen {
	friend ostream & operator<< <W,H>(ostream & os,const Screen<W,H> &);
	friend istream & operator>> <W,H>(istream & is,Screen<W,H> & );
public:
	using sizeType = string::size_type;
	Screen() = default;
	Screen(char c) :
			contents(H * W, c) {
	}
	char get() const {
		return contents[cursor];
	}
	char get(sizeType row, sizeType col) const {
		return contents[row * width + col]; //返回给出的行列的字符，显式内联
	}
	Screen & set(char ch) { //设置光标处的字符
		contents[cursor] = ch;
		return *this;
	}
	Screen & set(sizeType row, sizeType col, char ch) { //设置指定行列的字符
		contents[row * width + col] = ch;
		return *this;
	}
	Screen & move(sizeType row, sizeType col){
		cursor = row*width + col;
			return *this;//返回引用就是让返回值可以作为左值
	}
private:
	sizeType width = W;
	sizeType height = H;
	string contents;
	sizeType cursor = 0;
};

template<size_t W, size_t H>
ostream & operator<<(ostream & os,const Screen<W,H> & s){
	os<<s.contents;
	return os;
}
template<size_t W, size_t H>
istream & operator>>(istream & is,Screen<W,H> & s){
	char ch;
	is>>ch;
	string str(H*W,ch);
	s.contents = str;
	return is;
}
#endif /* SCREEN_H_ */
