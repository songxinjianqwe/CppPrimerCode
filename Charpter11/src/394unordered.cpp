/*
 * 394unordered.cpp
 *
 *  Created on: 2016年9月8日
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//无序关联容器
//不是使用比较运算符来组织元素，而是使用一个哈希函数和关键字类型的==运算符。
//在关键字类型的元素没有明显的序关系的情况下，无序容器是非常有用的。在某些应用中，维护元素有序的代价非常高昂，此时无序容器也很有用
//无序容器和有序容器有着相同的操作，区别只是没有顺序，也有重复关键字的版本
//管理桶的操作：
//c.bucket_count() 正在使用的桶的数目
//c.bucket_size(n) 第n个桶有多少个元素
//c.bucket(key) 关键字为key的元素在哪个桶中

//local_iterator 可以用来访问桶中元素的迭代器类型
//c.begin(n),c.end(n) 桶n的首元素迭代器和尾后迭代器
//哈希策略
//c.rehash(n) 重组存储，使得bucket_count>=n
//c.reserver(n) 重组存储，使得c可以保存n个元素而不必rehash

//无序容器对关键字类型的要求
//无序容器使用关键字类型的==运算符来比较元素，还使用一个hash<key_type>类型的对象来生成每个元素的哈希值
//内置类型可以直接使用哈希函数得到哈希值，但是对于自定义类型，我们必须通过自己的hash模板 版本
//一种方法是通过函数来替代==运算符和哈希值计算函数
class SalesData{
private:
	string bookNo;
public:
	string isbn() const{
		return bookNo;
	}
};
//创建一个未命名的对象的语法：类型(参数)   ，在java中是new 类型(参数)
//hash类重载了运算符(),接受对于类型参数的string的hash对象而言，接受一个string，返回size_t哈希值
size_t hasher(const SalesData & sd){
	return hash<string>()(sd.isbn());
}

bool equals(const SalesData & sd1,const SalesData & sd2){
	return sd1.isbn() == sd2.isbn();
}

using SalesDataSet = unordered_multiset<SalesData,decltype(hasher)*,decltype(equals)*>;
void test22(){
	//构造函数有三个参数，第一个是桶的大小，第二个是哈希函数指针，第三个是相等性判断函数指针
	SalesDataSet bookstore(42,hasher,equals);
	
}
//如果自己的类重载了==运算符，那么只添加一个哈希函数指针的参数即可

//重写单词计数程序
void test23(){
	unordered_map<string,int> wordCount;
	string word;
	while(cin>>word){
		wordCount[word]++;
	}
	for(const auto & w:wordCount){
		cout<<w.first<<"  "<<w.second<<endl;
	}
}

int main(void){
	test23();
	return 0;
}


