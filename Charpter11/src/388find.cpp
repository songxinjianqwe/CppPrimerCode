/*
 * 388find.cpp
 *
 *  Created on: 2016年9月8日
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//访问元素
//c.find(key) 返回一个迭代器，指向第一个关键字为key的元素，如果不存在，那么返回尾后迭代器
//c.count(key( 返回关键字为key的元素个数，对于不允许重复关键字的容器，返回值永远是0或1
//c.lower_bound(key) 返回一个迭代器，指向第一个关键字>=key的元素
//c.upper_bound(key) 返回一个迭代器，返回第一个关键字>key的元素
//c.equal_range(key) 返回一个迭代器pair，表示关键字等于key的范围，如果key不存在，那么pair的两个成员均为尾后迭代器

//lower_bound upper_bound不适用于无序容器
//下标和at操作适用于非const的map和unordered_map
//对于map而言，如果想要查找，那么最好使用find而不是下标操作，因为下标存在副作用

void test17() {
	map<string, size_t> wordCount;
	if (wordCount.find("Anna") == wordCount.end()) {
		cout << "Anna is not in the map" << endl;
	}
}
//对于multimap或者multiset而言，查找比较复杂
//需要返回一个范围
//共有三种实现方式
//1、使用find和count，建立在相同key的元素是放在一起的事实
void test18(multimap<string, string> authors) {
	auto entries = authors.count("Anna");
	for (auto it = authors.find("Anna"); entries != 0; it++, entries--) {
		cout << it->first << "  " << it->second << endl;
	}
}
//2、使用lower_bound和upper_bound
//如果这两个函数的参数是同样的key，那么它们可以返回一个范围，这个范围就是key的范围
//如果没有找到，那么它们会返回相等的迭代器，都指向给定关键字的插入点，能保持容器中元素顺序的插入位置
void test19(multimap<string, string> authors) {
	for (auto begin = authors.lower_bound("Anna"), end = authors.upper_bound(
			"Anna"); begin != end; begin++) {
		cout << begin->first << "  " << begin->second << endl;
	}
}
//3、使用equal_range，直接返回一个范围
void test20(multimap<string, string> authors) {
	for (auto pos = authors.equal_range("Anna"); pos.first != pos.second;
			pos.first++) {
		cout << pos.first->first << "   " << pos.first->second << endl;
	}
}

//11.28
void test21() {
	map<string, vector<int>> sVMap;
	sVMap.insert( { "key", { 2, 34, 5, 6, 7 } });
	auto value = sVMap.find("key");
	for (auto it = value->second.begin(); it != value->second.end(); it++) {
		cout << *it << "\t";
	}
	cout << endl;
}
//11.31
//给定一个键和值，在multimap中删掉它
//使用find遍历一般与count函数配合
void deleteKey(multimap<string, string> &authors, const string &author,	const string & work) {
	auto count = authors.count(author);
	for (auto it = authors.find(author); count != 0; it++, count--) {
		if (it->second == work) {
			authors.erase(it);
			break;
		}
	}
}

//11.32
//给出一个multimap，要求将其按照key有序并且在相同key下值有序输出
//先将key排序，插入到一个map即可，这个map的value是一个multiset，用来实现value有序
void displayInOrder(multimap<string, string> &authors) {
	map<string, multiset<string>> orderedAuthors;
	for (const auto & a : authors) {
		orderedAuthors[a.first].insert(a.second);
	}
	for (const auto & oa : orderedAuthors) {
		cout << oa.first << ":";
		for (const auto & work : oa.second) {
			cout << work << "\t";
		}
		cout << endl;
	}
}

int main(void) {
	multimap<string, string> authors;
	 authors.emplace("Socket", "UDP");
	 authors.emplace("Anna", "Blues");
	 authors.emplace("Anna", "Blues");
	 authors.emplace("Anna", "Blues");
	 authors.emplace("Stream", "IO");
	 test18(authors);
	 cout<<endl;
	 test19(authors);
	 cout<<endl;
	 test20(authors);
	test21();
	
	multimap<string, string> authors;
	authors.insert( { "Knoth", "C++" });
	authors.insert( { "Yikalos", "Index" });
	authors.insert( { "Knoth", "SE" });
	authors.insert( { "Knoth", "C" });
	deleteKey(authors, "Knoth", "C");
	for (const auto & a : authors) {
		cout << a.first << "\t" << a.second << endl;
	}
	displayInOrder(authors);
	return 0;
}
