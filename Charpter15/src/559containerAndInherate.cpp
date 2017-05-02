/*
 * 559containerAndInherate.cpp
 *
 *  Created on: 2016年9月25日
 *      Author: songx
 */


#include <BulkQuote.h>
#include <Quote.h>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

//当我们使用容器存放继承体系中的对象时，通常必须采用间接存储的方式，因为容器中不能放不同类型的元素，所以我们不能把具有继承关系
//的多种类型的对象直接存放在容器中
//当派生类对象被赋值给基类对象时，其中的派生类部分被切掉，因此容器和存在击沉关系的类型无法兼容

//通常我们选择在容器中存放智能指针而非对象
//我们可以将一个派生类的智能指针转为基类的智能指针

void test40(){
	vector<Quote> qVec;
	qVec.push_back(BulkQuote("代码大全",23.99,20,0.88));
	qVec.push_back(Quote("C++Primer",21.99));
	double sum = 0;
	for(auto it:qVec){
		sum += it.netPrice(50);
	}
	cout<<sum<<endl;
}
void test41(){
	vector<shared_ptr<Quote>> qVec;
	qVec.push_back(make_shared<BulkQuote>("代码大全",23.99,20,0.88));
	qVec.push_back(make_shared<Quote>("C++Primer",21.99));
	double sum = 0;
	for(auto it:qVec){
		sum += it->netPrice(50);
	}
	cout<<sum<<endl;
}
 

