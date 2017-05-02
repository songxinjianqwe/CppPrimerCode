/*
 * Basket.cpp
 *
 *  Created on: 2016��9��25��
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
//compare�ȽϺ������Է������⣬���Ҫ�������ڵĻ���Ҫ����Ϊstatic����Ϊ��static��Ա������һ����ʽָ��this����
//����������
class Basket {
public:
	Basket():items(compare){}
	void addItem(const shared_ptr<Quote> & sale) {
		items.insert(sale);
	}
	void addItem(const Quote & q){//����
		items.insert(shared_ptr<Quote>(q.clone()));
	}
	//ע�⣺�ù��캯��������������ָ��ʹ��make_shared
	//ʹ����ָͨ�빹������ָ��ʹ��shared_ptr<>()���캯��
	
	void addItem(Quote && q){//�ƶ�
		items.insert(shared_ptr<Quote>(move(q).clone()));
	}
	double totalRecept(ostream & os) const;
private:
	//����洢
	multiset<std::shared_ptr<Quote>, decltype(compare)*> items;
};

double Basket::totalRecept(ostream & os) const {
	double sum = 0;
	for (auto it = items.cbegin(); it != items.cend();
			it = items.upper_bound(*it)) {
		sum += printTotal(os, **it, items.count(*it));
		//printTotal�������������������������һ��Quote����Ͷ������
		//count������multiset���ú��������Լ�����ж��ٸ�������ͬ����ֵ��Ԫ��
	}
	return sum;
}


#endif /* BASKET_H_ */
