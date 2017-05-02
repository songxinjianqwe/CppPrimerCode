/*
 * NotQuery.cpp
 *
 *  Created on: 2016年9月26日
 *      Author: songx
 */

#include "../header/NotQuery.h"




QueryResult NotQuery::eval(TextQuery & tq)const{
	auto result = query.eval(tq);
	//result 是查询 是 的结果
	auto retLines = make_shared<set<int>>();
	auto begin = result.begin(),end = result.end();
	auto size = result.getFile()->size();
	//size是原文本的行数
	for(size_t i = 0; i != size;i++){
		if(begin == end||*begin != i){
			//如果不在result中，那么加入到结果集中
			retLines->insert(i);
			
		}else if ( begin != end){
			//如果i在result中，且查询结果尚未结束，那么begin++
			begin++;
		}
	}
	return QueryResult(rep(),result.getFile(),retLines);
}
