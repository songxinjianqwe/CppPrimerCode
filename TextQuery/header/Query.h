/*
 * Query.h
 *
 *  Created on: 2016年9月26日
 *      Author: songx
 */

#ifndef QUERY_H_
#define QUERY_H_


#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"

//使用组合的方式来组织

class Query{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &,const Query &);
	friend Query operator&(const Query &,const Query &);
public:
	Query(const string & str);//用于构建一个新的WordQuery
	//都调用q的相应方法
	QueryResult eval(TextQuery & tq)const{
		return q->eval(tq);
	}
	string rep()const{
		return q->rep();
	}
private:
	Query(shared_ptr<QueryBase> query):q(query){}
	//私有构造函数，仅供友元函数调用
	shared_ptr<QueryBase> q;
};

ostream & operator<<(ostream & os,const Query & query);
Query operator&(const Query & lhs,const Query & rhs);

#endif /* QUERY_H_ */
