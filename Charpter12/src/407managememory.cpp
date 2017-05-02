/*
 * 407managememory.cpp
 *
 *  Created on: 2016年9月9日
 *      Author: songx
 */

#include <iostream>
#include <memory>
#include <new>
#include <string>
#include <vector>

using namespace std;
//直接管理内存
//new分配内存，delete释放内存
//自己直接管理内存的类与使用智能指针的类不同，它们不能依赖类对象拷贝、赋值和销毁操作的任何默认定义。
//默认情况下，动态分配的对象是默认初始化的，这意味着内置类型或组合类型的对象的值是未定义的，而类类型对象将用默认构造函数进行初始化。
//可以使用直接初始化，列表初始化
//也可以对动态分配的对象进行值初始化，只需在类型名之后跟一对空括号即可。
//对于定义了自己的构造函数的类类型，要求值初始化是没有意义的，不管采用什么形式，对象都会通过默认构造函数来初始化。

void test2(){
	int *pi = new int;//默认初始化
	int *pi2 = new int();//值初始化
	int * pi3 = new int(1024);//直接初始化
	vector<int> *pV = new vector<int>{1,2,3,4};//列表初始化
	string * ps = new string;//空串
	string * ps2 = new string("happy?!");
	//动态分配的const对象
	//new const
	const int * pci = new const int(1024);
	const string * pcs = new const string;
	//new返回的指针是一个指向const的指针
	delete pi;
	delete pi2;
	delete pi3;
	delete pV;
	delete ps;
	delete ps2;
	delete pci;
	delete pcs;
}
//内存耗尽
//如果new不能分配所要求的内存空间，它会抛出一个类型为bad_alloc的异常。我们可以改变使用new的方式来组织它抛出异常
void test3(){
	int * p1 = new int;
	int * p2 = new (nothrow) int;
	//这种new称为定位new（placement new），定位new表达式允许我们向new传递额外的参数。
	//我们传递给它一个由标准库定义的名为nothrow对象。如果将nothrow传递给new，我们的意图是告诉它不能抛出异常。如果这种形式的new不能分配所需内存，它会返回一个空指针
	//bad_alloc和nothrow都定义在头文件new中
	delete p1;
	delete p2;
}

//释放动态内存
//delete表达式将动态内存归还给系统，接受一个指针，指向我们想要释放的对象
void test4(){
	int * pi = new int;
	delete pi;
	//注意pi不可以是局部变量，不可以是已经被释放的变量的指针
	//允许是空指针
}

//使用new和delete管理动态内存存在三个问题：
//1.忘记delete 2.使用已经释放掉的内存 3.同一块内存释放多次
//只是用智能指针，就可以避免所有这些问题。

//当我们delete一个指针后，指针值就变为无效了。虽然指针已经无效，但是指针仍然保存着已经释放了的动态内存的地址
//在delete之后，指针就变成了空悬指针，即指向一块曾经保存数据对象但现在已经无效的内存的指针
//未初始化指针的所有缺点空悬指针也有，有一种方法可以避免空悬指针的问题，就是在指针即将要离开其作用域时释放掉它所关联的内存。
//这样，在指针关联的内存被释放掉之后，就没有机会继续使用指针了。如果我们需要继续使用指针，可以在delete之后将nullptr赋予指针。
//仍然存在的问题是可能有多个指针指向同一块内存，当这块内存被释放之后，所有指向它的指针都失效了。

//12.6
vector<int> * getVector(){
	return new vector<int>;
}
vector<int> * save(vector<int> * pv){
	int i = 0;
	while(cin>>i){
		pv->push_back(i);
	}
	return pv;
}
void display(vector<int> * pv){
	for(auto i:*pv){
		cout<<i<<"\t";
	}
	cout<<endl;
	delete pv;
}
shared_ptr<vector<int>> getVector2(){
	return make_shared<vector<int>>();
}
shared_ptr<vector<int>> save2(shared_ptr<vector<int>> pv){
	int i = 0;
	while(cin>>i){
		pv->push_back(i);
	}
	return pv;
}
void display2(shared_ptr<vector<int>> pv){
	for(auto i:*pv){
		cout<<i<<"\t";
	}
	cout<<endl;
}

int main(void){
	display2(save2(getVector2()));
	return 0;
}

