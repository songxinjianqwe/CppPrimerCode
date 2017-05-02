#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;
//变长参数在C++中有几种实现方式
//第一种是当参数类型相同时，可以使用标准库类型initializer_list
//第二种是当参数类型不同时，可以使用可变参数模板
//在这里只讨论第一种情况

//它的操作十分类似于vector
//它也是一种模板类型，需要说明类型参数
//与vector不同的是，它的元素一经初始化就不能再改变
//初始化的方式是列表初始化{..,....}
//有两种遍历方式：范围for和begin、end指针
void errorMsg(initializer_list<string> list) {
	for (auto begin = list.begin(); begin != list.end(); begin++) {
		cout << *begin << endl;
	}
}
//除了这个list，也可以加上其他的参数，不过不能放在最后，一般是可变参数放在最后一个位置上
void errorMsg(int errCode, initializer_list<string> list) {
	cout << errCode << endl;
	for (auto begin = list.begin(); begin != list.end(); begin++) {
		cout << *begin << endl;
	}
}
int main(void) {
	errorMsg({ "haa", "mmam" });
	errorMsg(2, { "haa", "mmam" });
	return 0;
}
