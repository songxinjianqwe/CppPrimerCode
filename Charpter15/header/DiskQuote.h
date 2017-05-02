/*
 * DiskQuote.h
 *
 *  Created on: 2016��9��23��
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
//		cout<<"DiskQuote�������캯��"<<endl;
	}
	
	DiskQuote & operator=(const DiskQuote & rhs){
		//������ĸ�ֵ�������������ʽ���û���ĸ�ֵ�����
		Quote::operator =(rhs);
		qty = rhs.qty;
		discount = rhs.discount;
//		cout<<"DiskQuote������ֵ�����"<<endl;
		return *this;
	}
	
	DiskQuote(DiskQuote && rhs)noexcept:Quote(move(rhs)),qty(move(rhs.qty)),discount(rhs.discount){
//		cout<<"DiskQuote�ƶ����캯��"<<endl;
	}
	DiskQuote & operator=(DiskQuote && rhs)noexcept{
		if(*this != rhs){
			Quote::operator =(rhs);
			qty = move(rhs.qty);
			discount = move(rhs.discount);
		}
//		cout<<"DiskQuote�ƶ���ֵ�����"<<endl;
		return *this;
	}
	double netPrice(size_t quentity)const = 0;
	~DiskQuote(){
//		cout<<"DiskQuote��������"<<endl;
	}
protected:
	size_t qty = 0;
	double discount = 0;
};




#endif /* DISKQUOTE_H_ */
