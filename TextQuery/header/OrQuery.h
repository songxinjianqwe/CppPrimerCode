/*
 * OrQuery.h
 *
 *  Created on: 2016��9��26��
 *      Author: songx
 */

#ifndef ORQUERY_H_
#define ORQUERY_H_

#include "BinaryQuery.h"
#include "Query.h"
#include "TextQuery.h"

class OrQuery:public BinaryQuery{
	friend Query operator|(const Query &,const Query &);
private:
	OrQuery(const Query & left,const Query & right):BinaryQuery(left,right,"|"){}
	QueryResult eval(TextQuery &)const;
	//���ض���rep����Ϊ�����BinaryQuery��rep
};



#endif /* ORQUERY_H_ */
