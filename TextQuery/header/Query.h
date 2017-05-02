/*
 * Query.h
 *
 *  Created on: 2016��9��26��
 *      Author: songx
 */

#ifndef QUERY_H_
#define QUERY_H_


#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"

//ʹ����ϵķ�ʽ����֯

class Query{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &,const Query &);
	friend Query operator&(const Query &,const Query &);
public:
	Query(const string & str);//���ڹ���һ���µ�WordQuery
	//������q����Ӧ����
	QueryResult eval(TextQuery & tq)const{
		return q->eval(tq);
	}
	string rep()const{
		return q->rep();
	}
private:
	Query(shared_ptr<QueryBase> query):q(query){}
	//˽�й��캯����������Ԫ��������
	shared_ptr<QueryBase> q;
};

ostream & operator<<(ostream & os,const Query & query);
Query operator&(const Query & lhs,const Query & rhs);

#endif /* QUERY_H_ */
