/*
 * DiskQuote.h
 *
 *  Created on: 2016年9月23日
 *      Author: songx
 */

#ifndef DISKQUOTE_H_
#define DISKQUOTE_H_

#include <Quote.h>
#include <stddef.h>
#include <string>

using namespace std;
class DiskQuote:public Quote{
	friend bool operator!=(const DiskQuote & lhs,const DiskQuote &rhs);
public:
	DiskQuote() = default;
	DiskQuote(const string & book,double salesPrice,size_t qty,double disc):
		Quote(book,salesPrice),qty(qty),discount(disc){}
	DiskQuote(const DiskQuote & rhs):Quote(rhs),qty(rhs.qty),discount(rhs.discount){
//		cout<<"DiskQuote拷贝构造函数"<<endl;
	}
	
	DiskQuote & operator=(const DiskQuote & rhs){
		//派生类的赋值运算符中首先显式调用基类的赋值运算符
		Quote::operator =(rhs);
		qty = rhs.qty;
		discount = rhs.discount;
//		cout<<"DiskQuote拷贝赋值运算符"<<endl;
		return *this;
	}
	
	DiskQuote(DiskQuote && rhs)noexcept:Quote(move(rhs)),qty(move(rhs.qty)),discount(rhs.discount){
//		cout<<"DiskQuote移动构造函数"<<endl;
	}
	DiskQuote & operator=(DiskQuote && rhs)noexcept{
		if(*this != rhs){
			Quote::operator =(rhs);
			qty = move(rhs.qty);
			discount = move(rhs.discount);
		}
//		cout<<"DiskQuote移动赋值运算符"<<endl;
		return *this;
	}
	double netPrice(size_t quentity)const = 0;
	~DiskQuote(){
//		cout<<"DiskQuote析构函数"<<endl;
	}
protected:
	size_t qty = 0;
	double discount = 0;
};




#endif /* DISKQUOTE_H_ */
