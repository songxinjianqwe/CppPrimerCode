/*
 * 423dynamicarray.cpp
 *
 *  Created on: 2016年9月10日
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

//动态数组
//初始化一个动态数组的方法有两种：使用new/unique_ptr；allocator分配器
//但是注意，大多数应用都应该使用标准库容器而非动态数组，容器更简单、更不易出错、有更好的性能
//new和数组
void test24(){
	int n = 20;
	int *piArr = new int[n];
	typedef int arrT[20];//arrT 就相当于int[20]
	int *piArr2 = new arrT;
}
//当用new分配一个数组时，我们得到一个数组元素类型的指针，而非一个数组对象
//初始化动态数组
//new分配的对象，不管是单个分配还是数组，都是默认初始化的；可以对数组中的元素进行值初始化，方法是在大小之后加上一个括号
//还可以通过一个初始化列表,列表中的元素个数小于元素数目，剩余元素将进行值初始化，大于的话会抛出bad_array_new_length异常
//虽然可以用空括号对数组中的元素进行值初始化，但是不能再括号中给出初始化参数，也就是对于没有默认构造函数的对象而言是无法创建的。
//动态分配一个空数组是合法的，但是不能解引用
void test25(){
	int *piArr = new int[10];
	int *piArr2 = new int[10]();
	cout<<*piArr2<<endl;
	int *piArr3 = new int[10]{1,2,3,4};
	
}
//释放动态数组：使用delete[] p
//数组中的元素按逆序销毁，最后一个元素首先被销毁，然后是倒数第二个
//这个方括号是必须的，如果忽略，则是未定义的行为

//使用智能指针unique_ptr来管理动态数组
//为了用一个unique_ptr管理动态数组，我们必须在对象类型后面加一对空的方括号
//当一个unique_ptr指向一个数组时，我们就不能使用点和箭头成员运算符。可以使用下标运算符来访问元素
void test26(){
	unique_ptr<int[]> up(new int[10]);
	up.release();//释放内存，自动调用delete[]
	for(size_t i = 0; i != 10;i++){
		up[i] = i;
	}
}

//操作：
//unique_ptr<T[]> u;
//unique_ptr<T[]> u(p) p是内置指针所指向的动态数组
//u[i]

//shard_ptr不直接支持管理动态数组，如果希望使用它来管理动态数组，需要提供自己的删除器；并且未定义下标运算符，不支持指针的算术运算

//12.23
void test27(){
	char* arr = new char[255]();
	strcat(arr,"Hello");
	strcat(arr,"World");
	cout<<arr<<endl;
	delete[] arr;
	string * ps1 = new string("Hello");
	string * ps2 = new string("World");
	cout<<*ps1+*ps2<<endl;
}
//12.24
void test28(){
	size_t size = 0;
	cout<<"Please enter the size："<<endl;
	cin>>size;
	char* pArr = new char[size+1]();
	cin.ignore();
	//cin.ignore(a,ch)方法是从输入流（cin）中提取字符，提取的字符被忽略（ignore），不被使用。
	//每抛弃一个字符，它都要计数和比较字符：如果计数值达到a或者被抛弃的字符是ch，则cin.ignore()函数执行终止；否则，它继续等待。 
	//如果cin.ignore()不给参数，则默认参数为cin.ignore(1,EOF)，即把EOF前的1个字符清掉
	cout<<"Please enter the string"<<endl;
	cin.get(pArr,size+1);
	//cin.get(字符数组名,接收字符数目)用来接收一行字符串,可以接收空格 
	cout<<pArr<<endl;
	delete[] pArr;
}


