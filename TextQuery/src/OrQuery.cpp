/*
 * OrQuery.cpp
 *
 *  Created on: 2016��9��26��
 *      Author: songx
 */

#include "../header/OrQuery.h"

#include <memory>
#include <set>

#include "../header/QueryResult.h"


QueryResult OrQuery::eval(TextQuery &tq)const{
	auto leftResult = lhs.eval(tq),rightResult = rhs.eval(tq);
	//������һ��
	auto retLines = make_shared<set<int>>(leftResult.begin(),leftResult.end());
	retLines->insert(rightResult.begin(),rightResult.end());
	return QueryResult(rep(),leftResult.getFile(),retLines);
}
Query operator|(const Query & lhs,const Query & rhs){
	return Query(shared_ptr<QueryBase>(new OrQuery(lhs,rhs)));
}

