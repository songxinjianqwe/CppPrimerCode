/*
 * 557prac.cpp
 *
 *  Created on: 2016��9��25��
 *      Author: songx
 */

#include <BulkQuote.h>
#include <Quote.h>
#include <algorithm>
#include <memory>

class DiskQuote;
using namespace std;




void test30(){
	Quote q("���֮��",23.99);
	Quote q2 = q;
	shared_ptr<BulkQuote> pBQ;
	pBQ = make_shared<BulkQuote>("�����ȫ",39.99,30,0.88);
	q = *pBQ;
	{
		BulkQuote bq;
		bq = move(*pBQ);
	}
}

