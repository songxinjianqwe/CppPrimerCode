/*
 * Basket.cpp
 *
 *  Created on: 2016年9月25日
 *      Author: songx
 */

#ifndef BASKET_H_
#define BASKET_H_

#include <Quote.h>
#include <iostream>
#include <memory>
#include <set>
#include <string>
using namespace std;

bool compare(const std::shared_ptr<Quote> & lhs,
		const std::shared_ptr<Quote> & rhs) {
	return lhs->isbn() < rhs->isbn();
}
//compare比较函数可以放在类外，如果要放在类内的话需要声明为static，因为非static成员函数有一个隐式指针this参数
//购物篮的类
class Basket {
public:
	Basket():items(compare){}
	void addItem(const shared_ptr<Quote> & sale) {
		items.insert(sale);
	}
	void addItem(const Quote & q){//拷贝
		items.insert(shared_ptr<Quote>(q.clone()));
	}
	//注意：用构造函数参数创建智能指针使用make_shared
	//使用普通指针构造智能指针使用shared_ptr<>()构造函数
	
	void addItem(Quote && q){//移动
		items.insert(shared_ptr<Quote>(move(q).clone()));
	}
	double totalRecept(ostream & os) const;
private:
	//有序存储
	multiset<std::shared_ptr<Quote>, decltype(compare)*> items;
};

double Basket::totalRecept(ostream & os) const {
	double sum = 0;
	for (auto it = items.cbegin(); it != items.cend();
			it = items.upper_bound(*it)) {
		sum += printTotal(os, **it, items.count(*it));
		//printTotal函数接受三个参数，输出流，一个Quote对象和对象个数
		//count函数是multiset内置函数，可以计算出有多少个具有相同给定值的元素
	}
	return sum;
}


#endif /* BASKET_H_ */
