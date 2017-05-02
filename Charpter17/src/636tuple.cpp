/*
 * 636tuple.cpp
 *
 *  Created on: 2016年10月1日
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
//tuple
//tuple是类似pair的模板，但是tuple类型的成员类型是不同的，成员数量也是不同的。
//每个确定的tuple类型的成员数目是固定的，但一个tuple类型的成员数目可以与另一个tuple类型不同
//tuple<T1,T2,T3,...Tn> t;
//tuple<T1,T2,T3,...Tn> t(v1,v2,....vn);
//make_tuple(v1,v2,...vn);
//get<i>(t) 获得第i个数据成员的引用
//tuple_size<tupleType>::value    类模板，表示了给定tuple中成员的数量，value是一个public static数据成员
//tuple_element<i,tupleType>::type 类模板，表示了给定tuple中第i个元素的类型
//可以将tuple看做一个快速而随意的数据结构
//定义在tuple头文件中


//注意，只能采用直接初始化的方式，不能赋值初始化
//make_tuple也可以用于初始化

void test1(){
	tuple<size_t,size_t,size_t> threeD = make_tuple(2,3,5);
//	tuple<size_t,size_t,size_t> threeD2 = {2,4,5};//error
	tuple<string,vector<double>,int,list<int>>someVal("constants",{3.14,2.718},42,{0,1,23});
}

//访问元素
void test2(){
	auto item = make_tuple("0-999-78345-X",3,20.00);
	auto book = get<0>(item);
	cout<<book<<endl;
	//简化类型描述
	using trans = decltype(item);
	size_t sz = tuple_size<trans>::value;
	cout<<sz<<endl;
	tuple_element<1,trans>::type cnt = get<1>(item);
	cout<<cnt<<endl;
}




