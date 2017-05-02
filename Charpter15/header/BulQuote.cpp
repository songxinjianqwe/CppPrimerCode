/*
 * BulQuote.cpp
 *
 *  Created on: 2016Äê9ÔÂ18ÈÕ
 *      Author: songx
 */

#include <stddef.h>
#include <string>

#include "BulkQuote.h"


double BulkQuote::netPrice(size_t count) const {
	if(count >= qty){
		return count*(1-discount)*price;
	}else{
		return count*price;
	}
}
