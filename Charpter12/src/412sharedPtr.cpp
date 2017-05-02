/*
 * 412sharedPtr.cpp
 *
 *  Created on: 2016年9月10日
 *      Author: songx
 */

#include <iostream>
#include <memory>

using namespace std;

//shared_ptr的其他用法
//shared_ptr<T> p(q) q是一个内置指针，指向new分配的内存，用q来初始化p
//shared_ptr<T> p(u) u是unique_ptr，p从u那里接管了对象的所有权，u置为空
//shared_ptr<T> p(q,callable) q是一个内置指针，未必是指向动态内存，也可以指向某种资源，p将使用callable可调用对象来代替delete
//shared_ptr<T> p(p2,callable) p2也是一个只能指针，p将是p2的拷贝，区别是p将调用可调用对象来代替delete
//p.reset() 如果p是唯一指向其对象的shared_ptr，那么reset会释放此对象，并将p置为空
//p.reset(q) q是内置指针，p在释放对象之后，会指向q
//p.reset(q,callable) 如果加入了可选参数callable，将使用可调用对象来代替delete

//注意，不能让智能指针直接指向内置指针 shared_ptr<int> sp = new int;//error
//shared_ptr<int> p(new int);//ok

//注意！不可混用普通指针和智能指针

void process(shared_ptr<int> sp){
	cout<<"in process function:"<<sp.use_count()<<endl;
}
void test5(){
	shared_ptr<int> sp = make_shared<int>(1024);
	process(sp);//sp在传入之前引用计数为1，传入之后由于是传值调用，指针被拷贝，所以引用计数为2
	int x = *sp;//当函数结束后，函数内部的局部变量指针被销毁，引用计数变为1，仍可以解引用
	cout<<x<<endl;
}
void test6(){
	int * p = new int(1024);
	process(shared_ptr<int>(p));//在进入函数之后，智能指针的引用计数为1
	int x = *p;//函数结束后，智能指针的引用计数为0，内存被释放，p是空悬指针
	cout<<x<<endl;//对空悬指针解引用会出错。
}

//不能使用get初始化另一个智能指针或为智能指针赋值
void test7(){
	shared_ptr<int> sp(new int(42));
	int * q = sp.get();//get会返回一个普通指针，只能使用，不能delete
	{
		shared_ptr<int> r(q);
	}
	//当代码块退出时，这个智能指针会释放掉q所指向的内存，从而使得sp指向的内存也被释放，因此不可能再解引用sp
	int s = *sp;
	cout<<s<<endl;
}

//reset函数会更新引用计数，经常和unique函数一起使用。如果有多个shard_ptr共享同一个对象，那么一个智能指针想要修改值之前，要先制作一份拷贝，以免影响其他指针
void test8(){
	shared_ptr<int> p = make_shared<int>(1024);
	shared_ptr<int> q = p;
	if(!p.unique()){
		p.reset(new int(*p));
	}
	*p += 1024;
	cout<<*p<<"\t"<<*q<<endl;
}

void test9(){
	shared_ptr<int> p(new int(42));//在函数中的智能指针是p的拷贝，共同指向同一个对象
	process(shared_ptr<int>(p));
	cout<<p.use_count()<<endl;
	cout<<*p<<endl;//ok
}

void test10(){
	shared_ptr<int> p(new int(42));//在函数中的智能指针是p的拷贝，共同指向同一个对象
	process(shared_ptr<int>(p.get()));
	cout<<p.use_count()<<endl;//p失效，p所指向的那块 内存已经被释放了
	cout<<*p<<endl;
}



