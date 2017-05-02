#include <iostream>
#include <string>
#include <vector>
using namespace std;
//混用string和c风格字符串
//string有一个成员方法，可以返回该字符串的char数组版本
void t() {
	string s = "HelloWorld";
	const char * str = s.c_str();
	//必须使用const char*来接收
	//如果后续改变了string，那么c_str返回的结果也会改变
	//比较保险的方法是复制一份
}
//使用数组来初始化vector
//注意是拷贝的方式
void initVector2() {
	int arr[] = { 1,2,3,4 };
	vector<int> iVec(begin(arr), end(arr));
	for (auto i : iVec) {
		cout << i << endl;
	}
	cout << endl;
	//可以将数组的一部分复制到vector中
	vector<int> iVec2(arr + 1, arr + 3);
	//将数组的第二个元素至第三个元素复制到vector中
	//从第一个指针指向的元素开始到第二个指针指向元素的前一个元素为止
	for (auto i : iVec2) {
		cout << i << endl;
	}
}
