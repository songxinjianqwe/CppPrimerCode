/*
 * Query.cpp
 *
 *  Created on: 2016年9月26日
 *      Author: songx
 */

#include "../header/Query.h"

#include <iostream>
#include <memory>
#include <string>

#include "../header/AndQuery.h"
#include "../header/WordQuery.h"



//Query的构造函数，使用string来创建一个WordQuery，然后将WordQuery放到Query中
//q是智能指针，用一个string--> WordQuery-->Query
Query::Query(const string &s):q(new WordQuery(s)){}


//输出Query的表达式
ostream & operator<<(ostream & os,const Query & query){
	os<<query.rep();
	return os;
}

Query operator&(const Query & lhs,const Query & rhs){
	return Query(shared_ptr<QueryBase>(new AndQuery(lhs,rhs)));
}
