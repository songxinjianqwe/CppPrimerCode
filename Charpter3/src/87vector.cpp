#include <iostream>
#include <vector>
#include <string>
using namespace std;
//vector
//可以使用泛型
//vector<int> vector<string>
//vector 初始化
void initVector() {
	//一般情况下，圆括号表示构造，花括号表示列表初始化
	//但是也要根据泛型的类型，如果不为数值型，那么花括号也能表示构造

	//1
	vector<int> vec;
	//2
	vector<int> vec2 = vec;//拷贝，与java不同，不是指向同一对象
	//3
	vector<int> vec(10);//vector中定义了10个元素，采用默认初始化
	vector<int> vec{10};//只有一个元素
//	vector<string> vec{10};//有10个元素
	//前两个的区别在于，考虑vector的类型，如果是数值，那么就为列表初始化；如果不是数值，那么就为构造
	
	//4
	vector<int> vec(2, 32);//vector中定义了两个32 vector<T>(n,val) 定义了n个元素，用val来初始化
	//5
	vector<int> vec = { 23,4512,123,54,213,123 };//类似数组的初始化
	//当定义之后，所有元素都会得到默认的初始化
}
