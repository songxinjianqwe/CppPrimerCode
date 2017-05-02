#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct SalesData {
	string isdn;
	int num;
	double price;
	double revenue;
};
void testSizeOf() {
	SalesData data, *p = &data;
	SalesData & ref = data;
	cout << "sizeof(SalesData):" << sizeof(SalesData) << endl;//整个结构体的长度
	cout << "sizeof(data):" << sizeof(data) << endl;//整个结构体的长度
	cout << "sizeof(p):" << sizeof(p) << endl;//指针的长度 4
	cout << "sizeof(*p):" << sizeof(*p) << endl;//整个结构体的长度
	cout << "sizeof(ref):" << sizeof(ref) << endl;//整个结构体的长度
	cout << "sizeof(SalesData::isdn):" << sizeof(SalesData::isdn) << endl;//结构体中一个成员变量的长度
	cout << "sizeof(data.isdn):" << sizeof(data.isdn) << endl;//结构体中一个成员变量的长度
	//sizeof 后面也可以不加括号
	int arr[] = { 2,2,1,3,5,2 };
	cout << "sizeof(arr):" << sizeof(arr) << endl;//整个数组的长度之和
	//sizeof string或vector只会计算该类型固定部分的大小，不会计算对象中的元素占用了多少空间
	//利用sizeof得到数组长度
	//sizeof可以得到一个常量表达式
	constexpr size_t size = sizeof(arr) / sizeof(*arr);
	int arr2[size];

	//如果定义一个指针指向该数组，那么sizeof（指针）的结果不是整个数组的大小，而是指针的大小
	int *pArr = arr;
	cout << "sizeof(pArr) / sizeof(*pArr): " << sizeof(pArr) / sizeof(*pArr) << endl;
	
	//逗号运算符
	//从左到右的顺序求值，最终结果是右侧表达式的值
	//经常用于for循环中
}
