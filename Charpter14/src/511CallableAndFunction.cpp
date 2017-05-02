/*
 * 511可调用对象与function.cpp
 *
 *  Created on: 2016年9月17日
 *      Author: songx
 */

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

//C++中的可调用对象：函数、函数指针、lambda、bind创建的对象、函数对象
//不同类型的可调用对象可能共享同一种调用形式

int add(int i,int j){
	return i+j;
}
auto mod = [](int i,int j){return i+j;};
class divide{
public://注意要显式声明为public的，否则无法访问
	int operator()(int i,int j){
		return i/j;
	}
};
//上面这些可调用对象虽然类型不同，但是共享了同一种调用形式 int(int,int)
//我们希望将这些可调用对象放在一个map中，形成一个函数表，存放了可调用对象的指针
//使用string作为key，使用可调用对象的指针作为value
//我们value类型设置为函数指针int(*)(int,int)
void test60(){
	map<string,int(*)(int,int)> functionTable;
	functionTable.insert({"+",add});//ok
	//但是不能放入其他的可调用对象
//	functionTable.insert({"%",mod});//error
//	functionTable.insert({"/",divide()});//error
}


//标准库中有一个新的类型function，抽象了所有的可调用对象
//定义在functional头文件中
//function<T> f是一个用来存储可调用对象的空function，可调用对象的形式应该与函数类型T相同
//T: returnType(args)
//function<T> f(nullptr) 显式构造空function
//function<T> f(obj) obj是一个可调用对象，将obj拷贝一份存储到f中
//function<T> f = obj  同上

//if(f) while(f) f作为条件，如果f非空，返回true
//f(args) 调用可调用对象，参数为args
//result_type 返回值类型
//argument_type 当f只有一个形参时，这个是形参类型
//first_argument_type 第一个形参类型
//second_argument_type 第二个形参类型

//function也是一个模板，类型参数是调用形式，形如int(int,int)
void test61(){
	function<int(int,int)> f1 = add;
	function<int(int,int)> f2 = mod;
	function<int(int,int)> f3 = divide();
	map<string,function<int(int,int)>> functionTable;
	//此时，函数指针（函数名），lambda，函数对象（包括自定义和标准库）都可以放入这个map中
}

//解决函数重载问题
//不能直接将重载函数的名字放入function类型的对象中

//SalesData add(const SalesData & lhs,const SalesData & rhs);
void test62(){
	map<string,function<int(int,int)>> functionTable;
//	functionTable.insert({"+",add});//error
	
	//一种途径是存储函数指针，定义一个函数指针指向准备要存储的函数，然后将函数指针放入map中
	int(*p)(int,int) = add;
	functionTable.insert({"+",p});//ok
	
	//另一种途径是使用lambda包装一下
	functionTable.insert({"+",[](int a,int b){return add(a,b);}});
}

void calculator(){
	map<string,function<int(int,int)>> functionTable = {
			{"+",add},
			{"-",minus<int>()},
			{"*",[](int i,int j){return i*j;}},
			{"/",divide()},
			{"%",mod},
	};
	int x = 0,y = 0;
	string op;
	cout<<"Please enter operand1 operator operand2:";
	while(cin>>x>>op>>y){
		if((y == 0 && op == "/")||functionTable.find(op) == functionTable.end()){
			cout<<"Input Error!Please try again."<<endl;
		}else{
			cout<<"The result of "<<x<<" "<<op<<" "<<y<<":  "<<functionTable[op](x,y)<<endl;
		}
		cout<<"Please enter operand1 operator operand2:";
	}
}


 
