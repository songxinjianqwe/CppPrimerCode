/*
 * BulkQuote.h
 *
 *  Created on: 2016��9��18��
 *      Author: songx
 */

#ifndef BULKQUOTE_H_
#define BULKQUOTE_H_

#include <DiskQuote.h>
#include <stddef.h>
#include <string>

using namespace std;

/*class BulkQuote:public Quote{
public:
	BulkQuote() = default;
	BulkQuote(const string &,double,size_t,double);
	double netPrice(size_t ) const override;
private:
	size_t minQty = 0;
	double discount = 0;
};*/

class BulkQuote:public DiskQuote{
public:
	BulkQuote() = default;
	BulkQuote(const string & book,double salesPrice,size_t qty,double disc):DiskQuote(book,salesPrice,qty,disc){}
	BulkQuote(const BulkQuote & rhs):DiskQuote(rhs){
//		cout<<"BulkQuote�������캯��"<<endl;
	}
	BulkQuote & operator=(const BulkQuote & rhs){
		DiskQuote::operator =(rhs);
//		cout<<"BulkQuote������ֵ�����"<<endl;
		return *this;
	}
	BulkQuote(BulkQuote && rhs)noexcept:DiskQuote(move(rhs)){
//		cout<<"BulkQuote�ƶ����캯��"<<endl;
	}
	BulkQuote & operator=(DiskQuote && rhs)noexcept{
		DiskQuote::operator =(rhs);
//		cout<<"BulkQuote�ƶ����캯��"<<endl;
		return *this;
	}
	double netPrice(size_t quentity)const;
	BulkQuote * clone()const &{
		return new BulkQuote(*this);
	}
	BulkQuote * clone()&&{
		return new BulkQuote(move(*this));
	}
		
	
	~BulkQuote(){
//		cout<<"BulkQuote��������"<<endl;
	}
};


#endif /* BULKQUOTE_H_ */
