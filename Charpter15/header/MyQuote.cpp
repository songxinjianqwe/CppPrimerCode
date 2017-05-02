/*
 * MyQuote.cpp
 *
 *  Created on: 2016��9��18��
 *      Author: songx
 */

#include <MyQuote.h>
#include <stddef.h>



double MyQuote::netPrice(size_t count)const {
	if(count <= qty){
		return count*price*(1-discount);
	}else{
		return qty*price*(1-discount)+(count-qty)*price;
	}
}

