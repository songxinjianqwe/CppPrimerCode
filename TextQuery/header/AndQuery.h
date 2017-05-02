/*
 * AndQuery.h
 *
 *  Created on: 2016Äê9ÔÂ26ÈÕ
 *      Author: songx
 */

#ifndef ANDQUERY_H_
#define ANDQUERY_H_

#include <memory>

#include "BinaryQuery.h"
#include "Query.h"
#include "TextQuery.h"

class AndQuery:public BinaryQuery{
	friend Query operator&(const Query&,const Query &);
private:
	AndQuery(const Query & left,const Query & right):BinaryQuery(left,right,"&"){}
	QueryResult eval(TextQuery & )const;
};




#endif /* ANDQUERY_H_ */
