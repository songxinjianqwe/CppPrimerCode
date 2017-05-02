/*
 * NotQuery.h
 *
 *  Created on: 2016��9��26��
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
	Query query;//������һ����Ҫȡ����Query����
};
//ȡ�������������һ���µ�NotQuery����
Query operator~(const Query & q){
	return Query(shared_ptr<QueryBase>(new NotQuery(q)));
}




#endif /* NOTQUERY_H_ */
