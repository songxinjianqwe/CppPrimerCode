/*
 * BinaryQuery.h
 *
 *  Created on: 2016年9月26日
 *      Author: songx
 */

#ifndef BINARYQUERY_H_
#define BINARYQUERY_H_

#include "Query.h"

class BinaryQuery:public QueryBase{
protected:
	BinaryQuery(const Query & l,const Query & r,string s):lhs(l),rhs(r),op(s){}
	//抽象类不定义eval，直接继承了纯虚函数
	string rep()const{
		return "("+lhs.rep()+" "+op+" "+rhs.rep()+")";
	}
	Query lhs,rhs;
	string op;
};


#endif /* BINARYQUERY_H_ */
