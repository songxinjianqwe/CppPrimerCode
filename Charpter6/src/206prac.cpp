#include <iostream>
#include <string>
using namespace std;
//声明一个返回指向10个元素的string数组的引用
string(&func())[10];
//使用类型别名
using arrStr = string[10];
arrStr & func();
//使用尾置返回类型
auto func()->string(&)[10];
//使用decltype
string arr[10] = { "2" };
decltype(arr) & func();

//最简洁的应该是类型别名的形式
