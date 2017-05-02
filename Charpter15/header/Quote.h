/*
 * Quote.h
 *
 *  Created on: 2016年9月18日
 *      Author: songx
 */

#ifndef QUOTE_H_
#define QUOTE_H_

#include <stddef.h>
#include <string>
#include <iostream> 
using namespace std;
class Quote{
	friend bool operator!=(const Quote &lhs,const Quote & rhs);
public:
	Quote() = default;
	Quote(const string & book,double salesPrice):bookNo(book),price(salesPrice){}
	//拷贝构造函数
	Quote(const Quote & q):bookNo(q.bookNo),price(q.price){
//		cout<<"Quote拷贝构造函数"<<endl;
	}
	//拷贝赋值运算符
	Quote & operator=(const Quote & q){
		bookNo = q.bookNo;
		price = q.price;
//		cout<<"Quote拷贝赋值运算符"<<endl;
		return *this;
	}
	//移动构造函数
	Quote(Quote && q)noexcept:bookNo(move(q.bookNo)),price(move(q.price)){
//		cout<<"Quote移动构造函数"<<endl;
	}
	//移动赋值运算符
	Quote & operator=(Quote && q)noexcept{
		if(*this != q){
			bookNo = move(q.bookNo);
			price = move(q.price);
		}
//		cout<<"Quote移动赋值运算符"<<endl;
		return *this;
	}
	
	string isbn()const{
		return bookNo;
	}
	virtual double netPrice(size_t n) const{
		return n*price;
	}
	virtual Quote * clone()const &{//当前对象是左值时，调用此方法
		return new Quote(*this);
	}
	virtual Quote * clone() && {//当前对象是右值时，调用此方法
		return new Quote(move(*this));
	}
	virtual ~Quote(){
//		cout<<"Quote析构函数"<<endl;
	}
private:
	string bookNo;
protected:
	double price = 0 ;
};




double printTotal(ostream & os,const Quote & item,size_t n);

#endif /* QUOTE_H_ */
