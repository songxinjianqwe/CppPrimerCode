/*
 * 292container.cpp
 *
 *  Created on: 2016年10月3日
 *      Author: songx
 */

#include <stddef.h>
#include <array>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

void test1() {
	array<int, 10> arr;
	array<int, 10>::size_type i;
//	array<int>::size_type j;//error
}

//赋值和swap
//赋值运算符要求左边和右边的运算对象具有相同类型
//assign函数允许我们从一个不同但相容的类型赋值，或者从容器的一个子序列赋值。
//assign操作用参数所指定的元素的拷贝替换左边容器的所有元素
void test2() {
	list<string> names;
	vector<const char *> oldstyle;
//	names = oldstyle;//error
	names.assign(oldstyle.cbegin(), oldstyle.cend()); //ok
}
//assign的第二个版本接受一个整型值和一个元素值，它用指定书目且具有相同给定值的元素替换容器中原有的元素
void test3() {
	list<string> sList(1);
	sList.assign(10, "Hi");
}
//使用swap
void test4() {
	vector<string> sVec(10);
	vector<string> sVec2(24);
	swap(sVec, sVec2);
	//交换两个容器内容的操作保证会很快，元素本身未交换，swap只是交换了两个容器的内部数据结构
	//指向容器的迭代器、引用和指针在swap操作之后都不会失效，而是指向swap操作之前所指向的元素
	//swap有成员函数和非成员的版本
	//统一使用非成员版本的swap是一个好习惯
}

//*****************************************************************************
//使用push_back
void test5() {
	string word;
	vector<string> sVec;
	while (cin >> word) {
		sVec.push_back(word);
	}
}
//使用push_front
void test6() {
	list<int> iList;
	for (size_t i = 0; i != 4; ++i) {
		iList.push_front(i);
	}
	// 3 2 1 0
}
//在容器的特定位置添加元素
//vector list deque string 都支持insert
//每个insert函数都接受一个迭代器作为其第一个参数，迭代器指出了在容器中什么位置放置新元素。它可以指向容器中任何位置
//包括容器尾部之后的下一个位置。
//由于迭代器可能指向容器尾部之后不存在的元素的位置，而且在容器开始位置插入元素是很有用的概念，所以insert是将
//将元素插入到迭代器所指向位置之前

void test7() {
	list<int> iList = { 2, 3, 4 };
	iList.insert(iList.end(), 2);
	iList.insert(iList.begin(), 23);
	for (auto i : iList) {
		cout << i << "\t";
	}
	cout << endl;
}
//插入范围内的元素
//insert还可以接受一个元素数目和一个值，将指定数量的元素添加到指定位置之前。这些元素都按给定值初始化
void test8() {
	vector<string> sVec;
	sVec.insert(sVec.end(), 10, "A");
	for (auto s : sVec) {
		cout << s << "\t";
	}
	cout << endl;
}
//使用insert的返回值
//insert返回指向新添加的元素的位置的迭代器
void test9() {
	list<string> sList;
	auto it = sList.begin();
	string word;
	while (cin >> word) {
		it = sList.insert(it, word);
	}
	//相当于push_front
	for (auto s : sList) {
		cout << s << "\t";
	}
	cout << endl;
}
//使用emplace操作
//构造而不是拷贝元素
//当我们调用一个emplace成员函数时，是将参数传递给元素类型的构造函数中。
class Foo {
public:
	Foo(int m) :
			mem(m) {
	}
	int mem;
};
void test10() {
	list<Foo> sList;
	int i;
	while (cin >> i) {
		sList.emplace(sList.end(), i);
	}
	for (auto f : sList) {
		cout << f.mem << "\t";
	}
	cout << endl;
}
//**************************************************************************
//访问元素
//访问成员函数返回的引用。如果容器是const对象，则返回值是const引用。如果容器不是const，那么返回值是普通引用。
void test11() {
	list<int> iList = { 2, 3, 4, 5 };
	if (!iList.empty()) {
		iList.front() = 23;
		auto & v = iList.back();
		v = 1024;
		auto v2 = iList.back();
		v2 = 0;	//v2不是引用，没有改变iList的值
	}
	for (auto i : iList) {
		cout << i << "\t";
	}
	cout << endl;
}

//下标查找和安全的随机访问
//下摆操作必须在有效范围内，保证下标有效是程序员的责任
void test12() {
	vector<string> sVec;
//	cout<<sVec[0];//出错
	cout << sVec.at(0);	//如果没有元素，那么会抛出一个out_of_range异常
//	terminate called after throwing an instance of 'std::out_of_range'
//	  what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
}

//**********************************************************************************

//删除元素
//pop_front和pop_back
//string vector不支持pop_front
//forward_list不支持pop_back
void process(int i) {
	cout << i << endl;
}
void test13() {
	list<int> iList = { 2, 3, 4, 5 };
	while (!iList.empty()) {
		process(iList.front());
		iList.pop_front();
	}
}
//使用erase，接受迭代器参数
void test14() {
	list<int> iList = { 2, 3, 4, 5, 6, 7, 8 };
	for (auto it = iList.begin(); it != iList.end(); ++it) {
		if (*it % 2 == 0) {
			it = iList.erase(it);
			//erase返回被删元素之后的元素的迭代器
		}
	}
	for (auto i : iList) {
		cout << i << "\t";
	}
	cout << endl;
}
//删除多个元素
//接受一对迭代器
void test15() {
	list<int> iList = { 2, 3, 4, 5, 6, 7, 8 };
	iList.erase(iList.begin(), iList.end());
	for (auto i : iList) {
		cout << i << "\t";
	}
	cout << endl;
}
//erase从list中删除奇数元素，从vector中删除偶数元素
void test16() {
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> iVec(begin(arr), end(arr));
	list<int> iList(iVec.begin(), iVec.end());
	for (auto it = iVec.begin(); it != iVec.end();) {
		if (*it % 2 == 0) {
			it = iVec.erase(it);
		} else {
			it++;
		}
	}
	for (auto it = iList.begin(); it != iList.end();) {
		if (*it % 2 == 1) {
			it = iList.erase(it);
		} else {
			it++;
		}
	}
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;
	for (auto i : iList) {
		cout << i << "\t";
	}
	cout << endl;

}
//****************************************************************
//forward_list
//当插入或删除元素时，我们需要控制两个迭代器:一个是我们要处理的元素；一个指向其前驱
void test17(){
	forward_list<int> flist = {0,1,2,3,4,5,6,7,8,9};
	auto prev = flist.before_begin();
	auto curr = flist.begin();
	while(curr != flist.end()){
		if(*curr % 2 == 0){
			curr = flist.erase_after(prev);
		}else{
			prev = curr;
			++curr;
		}
	}
	for(auto i:flist){
		cout<<i<<"\t";
	}
	cout<<endl;
}
//在链表中查找第一个string，并将第二个string插入到紧跟着第一个string之后的位置
//如果第一个string没有在链表中，则将第二个stirng插入到表尾。
void test18(forward_list<string> & flist,const string & s1,const string & s2){
	bool hasString1 = false;
	auto prev = flist.before_begin();
	auto curr = flist.begin();
	while(curr != flist.end()){
		if(*curr == s1){
			curr = flist.insert_after(curr,s2);
			hasString1 = true;
		}else{
			curr++;
			prev++;
		}
	}
	if(!hasString1){
		flist.insert_after(prev,s2);
	}
}
//***********************************************************************************
//编写改变容器的循环程序
//程序必须保证每个循环中都更新迭代器、引用或指针
//如果循环中调用的是insert或erase，那么更新迭代器很容易。这些操作返回迭代器，我们可以用来更新
void test19(){
	vector<int> iVec = {0,1,2,3,4,5,6,7,8,9};
	auto it = iVec.begin();
	while(it != iVec.end()){
		if(*it % 2 == 1){
			it = iVec.insert(it,*it);
			it+=2;//跳过当前元素和刚插入的元素
		}else{
			it = iVec.erase(it);
		}
	}
	for(auto i:iVec){
		cout<<i<<"\t";
	}
	cout<<endl;
}
//我们在调用insert和erase后都更新迭代器，因为二者都会使迭代器失效
//在调用erase之后，不必递增迭代器，因为erase返回的迭代器已经指向序列中下一个元素。调用insert后，需要递增迭代器两次

//不要保存end返回的迭代器，因为end返回的迭代器总是会失效。添加或删除元素的循环程序必须反复调用end，而不能事先保存
/*
int main() {
//	forward_list<string> flist = {"P","P","A","B"};
	forward_list<string> flist = {"A","B","A","B"};
	test18(flist,"P","PPP");
	for(auto s:flist){
		cout<<s<<"\t";
	}
	cout<<endl;
}*/

