/*
 * DiskQuote.cpp
 *
 *  Created on: 2016��9��25��
 *      Author: songx
 */

#include <DiskQuote.h>


bool operator!=(const DiskQuote & lhs,const DiskQuote &rhs){
	return Quote(lhs) != Quote(rhs) || lhs.qty != rhs.qty || lhs.discount != rhs.discount;
}

