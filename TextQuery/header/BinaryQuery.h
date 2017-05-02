/*
 * BinaryQuery.h
 *
 *  Created on: 2016��9��26��
 *      Author: songx
 */

#ifndef BINARYQUERY_H_
#define BINARYQUERY_H_

#include "Query.h"

class BinaryQuery:public QueryBase{
protected:
	BinaryQuery(const Query & l,const Query & r,string s):lhs(l),rhs(r),op(s){}
	//�����಻����eval��ֱ�Ӽ̳��˴��麯��
	string rep()const{
		return "("+lhs.rep()+" "+op+" "+rhs.rep()+")";
	}
	Query lhs,rhs;
	string op;
};


#endif /* BINARYQUERY_H_ */
