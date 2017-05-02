#include <iostream>
#include <string>
using namespace std;
//聚合类
//所有成员都是public；没有定义构造函数；没有类内初始值；没有父类，没有virtual函数0
//可以直接访问成员变量
//初始化形式为列表初始化，初始值的顺序必须与声明的顺序一致
//如果初始值列表中的元素个数少于类的成员数量，则靠后的成员将被值初始化
struct Data {
	int iVal;
	string s;
};
void test3() {
	Data data = { 2,"12" };

}