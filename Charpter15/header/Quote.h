/*
 * Quote.h
 *
 *  Created on: 2016��9��18��
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
	//�������캯��
	Quote(const Quote & q):bookNo(q.bookNo),price(q.price){
//		cout<<"Quote�������캯��"<<endl;
	}
	//������ֵ�����
	Quote & operator=(const Quote & q){
		bookNo = q.bookNo;
		price = q.price;
//		cout<<"Quote������ֵ�����"<<endl;
		return *this;
	}
	//�ƶ����캯��
	Quote(Quote && q)noexcept:bookNo(move(q.bookNo)),price(move(q.price)){
//		cout<<"Quote�ƶ����캯��"<<endl;
	}
	//�ƶ���ֵ�����
	Quote & operator=(Quote && q)noexcept{
		if(*this != q){
			bookNo = move(q.bookNo);
			price = move(q.price);
		}
//		cout<<"Quote�ƶ���ֵ�����"<<endl;
		return *this;
	}
	
	string isbn()const{
		return bookNo;
	}
	virtual double netPrice(size_t n) const{
		return n*price;
	}
	virtual Quote * clone()const &{//��ǰ��������ֵʱ�����ô˷���
		return new Quote(*this);
	}
	virtual Quote * clone() && {//��ǰ��������ֵʱ�����ô˷���
		return new Quote(move(*this));
	}
	virtual ~Quote(){
//		cout<<"Quote��������"<<endl;
	}
private:
	string bookNo;
protected:
	double price = 0 ;
};




double printTotal(ostream & os,const Quote & item,size_t n);

#endif /* QUOTE_H_ */
