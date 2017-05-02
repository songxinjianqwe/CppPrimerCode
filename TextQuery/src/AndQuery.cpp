/*
 * AndQuery.cpp
 *
 *  Created on: 2016年9月26日
 *      Author: songx
 */

#include "../header/AndQuery.h"

#include <algorithm>
#include <iterator>
#include <memory>
#include <set>
#include <vector>

#include "../header/QueryResult.h"

//算法set_intersection
//接受五个迭代器，前四个表示两个输入序列，最后一个表示目的位置。该算法将两个输入序列中共同出现的元素写入到目的位置中
//插入一个插入迭代器作为目的位置
QueryResult AndQuery::eval(TextQuery & tq)const{
	auto leftResult = lhs.eval(tq),rightResult = rhs.eval(tq);
	//拷贝了一遍
	auto retLines = make_shared<set<int>>();
	set_intersection(leftResult.begin(),leftResult.end(),rightResult.begin(),rightResult.end(),inserter(*retLines,retLines->begin()));
	return QueryResult(rep(),leftResult.getFile(),retLines);
}

