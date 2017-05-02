/*
 * 427allocator.cpp
 *
 *  Created on: 2016年9月10日
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

//allocator 可以将分配内存与对象构造分离，意味着我们可以分配大块内存，但只在真正需要时才真正执行对象创建操作
//比如分配n个对象，但实际上只用到了一半对象，后一半就没有必要进行初始化，而前一半进行了两次赋值，一次是默认初始化，一次是我们自己进行的赋值
//allocator类定义在头文件memory中，它分配的内存是未构造的
//allocator是一个模板，需要定义可以分配的对象类型
//操作：
//allocator<T> a
//a.allocate(n) 分配n个对象的内存，但未初始化
//a.construct(p,args) p是一个指针，指向一块原始内存，args是构造函数的参数
//a.destory(p) 对p指向的对象执行析构函数
//a.deallocate(p,n) 释放从p中地址开始的内存，这块内存保存了n个对象。要求p必须是allocate返回的指针，n是创建时的大小，在调用这个函数之前，必须对每个对象调用destroy

//执行destory操作之后，就可以重新使用这部分内存来保存其他对象了，也可以通过deallocate归还给系统
void test30() {
	size_t n = 20; //size_t是可移植类型，足以保存最大的数组长度
	allocator<int> a;
	auto p = a.allocate(n);
	auto q = p;
	for (size_t i = 0; i != n; i++, q++) {
		a.construct(q, i);
	}
	while (p != q) {
		cout << *--q << "\t";
//		a.destory(q);
	}
}

//拷贝和填充未初始化内存的算法
//可以使用construct构造元素，也可以通过一些算法向数组中拷贝元素或填充元素
//这些算法定义在memory中
//uninitialized_copy(begin,end,begin2) begin和end是两个迭代器，将这两个迭代器之间的元素拷贝到begin2指定的原始内存中
//uninitialized_copy_n(begin,n,begin2) 从begin开始，拷贝n个元素到begin2开始的内存中
//uninitialized_fill(begin,end,t)	   在begin和end范围内创建对象，对象的值为t的拷贝	
//uninitialized_fill_n(begin,n,t)    从begin开始，创建n个对象，对象的值为t的拷贝
//它们返回一个指针，指向最后一个构造的元素之后的位置

//上面的迭代器也可以用指针代替
void test31() {
	vector<int> iVec = { 2, 3, 4, 5 };
	allocator<int> alloc;
	auto p = alloc.allocate(iVec.size() * 2);
	auto q = uninitialized_copy(iVec.begin(), iVec.end(), p);
	uninitialized_copy_n(q, iVec.size(), 42);

}

//12.26
void test32() {
	size_t n = 10;
	allocator<string> alloc;
	string * psArr = alloc.allocate(n);
	string * psArrEnd = psArr;
	string s;
	while (cin >> s && psArrEnd != psArr + n) {
		alloc.construct(psArrEnd++, s);
	}
	while (psArrEnd != psArr) {
		cout << *--psArrEnd << endl;
		alloc.destroy(psArrEnd);
	}
	alloc.deallocate(psArr, n);
}

