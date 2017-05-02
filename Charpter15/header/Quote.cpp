/*
 * Quote.cpp
 *
 *  Created on: 2016Äê9ÔÂ18ÈÕ
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
