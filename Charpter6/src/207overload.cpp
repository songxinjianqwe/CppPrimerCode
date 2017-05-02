#include <iostream>
#include <string>
using namespace std;
//函数重载
//要求形参的类型或个数不同
//重载和const形参
//当形参为顶层const（比如const变量或者常量指针），不可与非const的形参的函数构成重载
//当形参为底层const（比如指向常量的指针或常量引用），可以与非const的形参的函数构成重载

string lookup(int i);
string lookup(const int i);//error 不可重载

string lookup(int * p);
string lookup(int * const p);//error 不可重载

string lookup(int * p);
string lookup(const int * p);//ok

string lookup(int &r);
string lookup(const int & r);//ok

//实参为常量时，形参可以是常量，也可以是非常量
//当我们传递一个非常量或者指向非常量对象的指针时，编译器会优先选用非常量版本的函数
