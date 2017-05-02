/*
 * Query.cpp
 *
 *  Created on: 2016��9��26��
 *      Author: songx
 */

#include "../header/Query.h"

#include <iostream>
#include <memory>
#include <string>

#include "../header/AndQuery.h"
#include "../header/WordQuery.h"



//Query�Ĺ��캯����ʹ��string������һ��WordQuery��Ȼ��WordQuery�ŵ�Query��
//q������ָ�룬��һ��string--> WordQuery-->Query
Query::Query(const string &s):q(new WordQuery(s)){}


//���Query�ı��ʽ
ostream & operator<<(ostream & os,const Query & query){
	os<<query.rep();
	return os;
}

Query operator&(const Query & lhs,const Query & rhs){
	return Query(shared_ptr<QueryBase>(new AndQuery(lhs,rhs)));
}
