/*
 * 386erase.cpp
 *
 *  Created on: 2016年9月8日
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

//删除元素
//有三个版本的erase
//第一个版本是给出一个迭代器，删除该迭代器指向的元素
//第二个版本是给出两个迭代器，删除它们之间的元素
//第三个版本是接受一个key，删除所有对应的key和value，返回删除的元素个数


void test15(){
	map<string,size_t> wordCount;
	wordCount.emplace("word",1);
	cout<<wordCount.erase("word")<<endl;
	for(const auto &w:wordCount){
		cout<<w.first<<"  "<<w.second<<endl;
	}
}

//map的下标操作
//map和unordered_map容器提供了下标运算符和一个对应的at函数
//set不支持下标，multimap和unordered_multimap也不支持下标（一对多）
//c[key] 返回关键字为key的value，如果k不在c中，那么添加一个关键字为key的元素，并对其进行值初始化
//c.at(key) 访问关键字为key的元素，带参数检查，如果key不在c中，那么抛出out_of_range异常

//当对一个map进行下标操作时，会得到一个value对象；当解引用一个map的迭代器时，返回一个pair
//map的下标操作返回的是一个左值，所以既可读又可写
void test16(){
	map<string,size_t> wordCount;
	wordCount["Anna"] = 1;
	cout<<wordCount["Anna"]<<endl;
	wordCount["Anna"]++;
	cout<<wordCount["Anna"]<<endl;
}


