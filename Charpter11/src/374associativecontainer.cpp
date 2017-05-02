/*
 * 374associativecontainer.cpp
 *
 *  Created on: 2016年9月7日
 *      Author: songx
 */

#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
//关联容器
//set和map
//如果可以重复关键字，在前面加上multi
//如果是无序，在前面加上unordered
//map和multimap定义在头文件map中
//set和multiset定义在头文件set中
//无序容器定义在头文件unordered_map(unordered_map,unordered_multimap)和unordered_set(unordered_set,unordered_multiset)

//关联容器也是模板，需要指定类型参数
//map是由pair组成的，pair是一个模板类型，保存两个名为first和second的成员变量
//map所使用的pair用first保存key，用second保存value

void test1() {
	map<string, string::size_type> wordCount;
	set<string> exclude = { "The", "But", "And", "Or", "An", "A", "the", "but",
			"and", "or", "an", "a" };
	string word;
	while (cin >> word) {
		if (exclude.find(word) == exclude.end()) {
			wordCount[word]++;
		}
	}
	for (const auto & w : wordCount) {
		cout << w.first << "  " << w.second << endl;
	}
}
void test2() {
	map<string, string::size_type> wordCount;
	string word;
	while (cin >> word) {
		for (auto & ch : word) {
			ch = tolower(ch);
		}
		//函数remove_if()移除序列[start, end)中所有应用于谓词p返回true的元素.
		//此函数返回一个指向被修剪的序列的最后一个元素迭代器.
		//remove_if()并不会实际移除序列[start, end)中的元素; 如果在一个容器上应用remove_if(), 容器的长度并不会改变
		//(remove_if()不可能仅通过迭代器改变容器的属性), 所有的元素都还在容器里面.
		//实际做法是, remove_if()将所有应该移除的元素都移动到了容器尾部并返回一个分界的迭代器. 移除的所有元素仍然可以通过返回的迭代器访问到.
		//为了实际移除元素, 你必须对容器自行调用erase()以擦除需要移除的元素.
//		auto punctStart = remove_if(word.begin(), word.end(), ispunct);
//		word.erase(punctStart, word.end());
		wordCount[word]++;
	}
	for (const auto & w : wordCount) {
		cout << w.first << "  " << w.second << endl;
	}
}

