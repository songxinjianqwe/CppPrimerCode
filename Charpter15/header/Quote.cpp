/*
 * Quote.cpp
 *
 *  Created on: 2016��9��18��
 *      Author: songx
 */

#include "Quote.h"

bool operator!=(const Quote &lhs,const Quote & rhs){
	return lhs.bookNo != rhs.bookNo || lhs.price != rhs.price;
}



double printTotal(ostream & os,const Quote & item,size_t n){
	double ret = item.netPrice(n);
	os<<"ISBN: "<<item.isbn()<<"# sold:"<<n<<" total due:"<<ret<<endl;
	return ret;
}
