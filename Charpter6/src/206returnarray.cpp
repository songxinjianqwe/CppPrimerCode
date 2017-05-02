#include <iostream>
using namespace std;
//c++中不允许返回数组
//但是可以返回指向数组首元素的指针或数组的引用，并且都有必要声明数组的大小
//返回数组指针有三种方法：
//1.使用类型别名
using arrI = int[10];
arrI* function(int i);
//返回的就是一个指向一个有10个元素的int数组的指针

//2.比较繁琐的方式
//ElementType (*functionName(parameters))[ArraySize]
int(*function(int i))[10];
//从内向外解读：内部是function(int i)，是函数名和参数列表
//向外有一个指针，表示返回的是指针类型；如果返回的是引用，那么应写成int(&function(int i))[10]
//括号外面是int[10]，表示返回的指针是指向有10个元素的int数组类型
//括号必须加，否则报错

//3.尾置返回类型
//auto function(int i) -> int(*)[10];
//在返回类型放置一个auto
//在声明的右侧加上-> 和 返回的实际类型（指向int[10]的指针）

//4.使用decltype
//适用于已知要返回哪个数组（定义在外部）的情况
int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };
decltype(odd) * function(int i) {
	return i % 2 == 0 ? &odd : &even;
}
//decltype并不负责将数组类型转为对应的指针，所以decltype的结果是一个数组，要想表示返回指针还必须在声明处加一个*
//修改为返回数组引用
decltype(odd) & function(int i) {
	return i % 2 == 0 ? odd : even;
}

