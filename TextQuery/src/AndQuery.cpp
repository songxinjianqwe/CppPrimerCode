/*
 * AndQuery.cpp
 *
 *  Created on: 2016��9��26��
 *      Author: songx
 */

#include "../header/AndQuery.h"

#include <algorithm>
#include <iterator>
#include <memory>
#include <set>
#include <vector>

#include "../header/QueryResult.h"

//�㷨set_intersection
//���������������ǰ�ĸ���ʾ�����������У����һ����ʾĿ��λ�á����㷨���������������й�ͬ���ֵ�Ԫ��д�뵽Ŀ��λ����
//����һ�������������ΪĿ��λ��
QueryResult AndQuery::eval(TextQuery & tq)const{
	auto leftResult = lhs.eval(tq),rightResult = rhs.eval(tq);
	//������һ��
	auto retLines = make_shared<set<int>>();
	set_intersection(leftResult.begin(),leftResult.end(),rightResult.begin(),rightResult.end(),inserter(*retLines,retLines->begin()));
	return QueryResult(rep(),leftResult.getFile(),retLines);
}

