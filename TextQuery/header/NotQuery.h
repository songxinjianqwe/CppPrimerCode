/*
 * NotQuery.h
 *
 *  Created on: 2016年9月26日
 *      Author: songx
 */

#ifndef NOTQUERY_H_
#define NOTQUERY_H_

#include "Query.h"
#include "TextQuery.h"

class NotQuery:public QueryBase{
	friend Query operator~(const Query &);
private:
	NotQuery(const Query & q):query(q){}
	QueryResult eval(TextQuery & tq)const;
	string rep()const{
		return "~("+query.rep()+")";
	}
	Query query;//保存着一个需要取反的Query对象
};
//取反运算符会生成一个新的NotQuery对象
Query operator~(const Query & q){
	return Query(shared_ptr<QueryBase>(new NotQuery(q)));
}




#endif /* NOTQUERY_H_ */
