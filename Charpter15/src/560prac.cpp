/*
 * 560prac.cpp
 *
 *  Created on: 2016年9月25日
 *      Author: songx
 */

#include <Basket.h>
#include <BulkQuote.h>
#include <Quote.h>
#include <iostream>
#include <memory>


void test44(){
	Basket bask;
	bask.addItem(make_shared<Quote>("代码大全",23));
	bask.totalRecept(cout);
}
//这里存在的问题的是我们需要传入的参数是一个智能指针，能否将指针隐藏，直接传入对象，在函数内将对象转成动态内存存放的呢？
//但是，如果我们使用new Quote(q)这种方式拷贝并创建动态对象的话，所有的Quote对象及其派生类对象都会被转为Quote
//多余的部分将被切掉
//为了解决这个问题（利用虚函数动态类型的特点），我们在Quote设置一个虚函数，可以传入一个对象，返回一个动态对象的指针
//这个普通指针可以作为参数构造智能指针

void test45(){
	Basket bask;
	bask.addItem(Quote("代码大全",23));
	bask.addItem(BulkQuote("代码简洁之道",24,30,0.88));
	bask.totalRecept(cout);
}
int main(){
	test45();
}

