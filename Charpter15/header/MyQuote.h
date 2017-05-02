/*
 * MyQuote.h
 *
 *  Created on: 2016Äê9ÔÂ18ÈÕ
 *      Author: songx
 */

#ifndef MYQUOTE_H_
#define MYQUOTE_H_

#include <DiskQuote.h>
#include <stddef.h>
#include <string>

class MyQuote: public DiskQuote{
public:
	MyQuote() = default;
	MyQuote(const string & book,double price,size_t max,double disc):
		DiskQuote(book,price,max,disc){}
	double netPrice(size_t n)const;
};


#endif /* MYQUOTE_H_ */
