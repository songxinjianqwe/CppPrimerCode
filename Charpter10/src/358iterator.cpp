#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

//除了为每个容器定义的迭代器之外，头文件iterator还有几种迭代器
//插入迭代器；流迭代器；反向迭代器；移动迭代器

//插入迭代器
//当我们通过一个插入迭代器进行赋值时，该迭代器调用容器操作来想给定容器的指定位置插入一个元素
//*it = t 将元素t插入到it所指向的元素之前
//*it,it++,it-- 这些操作没有意义，都返回it
//插入迭代器根据元素插入的位置分为三种
//这些函数的第一个参数都是容器
//back_inserter 使用push_back
//front_inserter 使用push_front
//inserter 接受第二个参数，必须是一个指向给定容器的迭代器，元素将被插入到给定迭代器所指向的元素之前
void test35() {
	vector<int> iVec;
	auto inserter = back_inserter(iVec);
	*inserter = 32;
	*inserter = 21;
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl; //32  21
}
void test36() {
	list<int> iList1 = { 2, 3, 4, 5 };
	list<int> iList2, iList3;
	copy(iList1.cbegin(), iList1.cend(), front_inserter(iList2));
	copy(iList1.cbegin(), iList1.cend(), inserter(iList3, iList3.begin()));
	for (auto i : iList2) {
		cout << i << "\t";
	}
	cout << endl;
	for (auto i : iList3) {
		cout << i << "\t";
	}
	cout << endl;
}

//10.27
void test37(){
	list<int> iList = {2,3,4,5,5,5,5,5};
	list<int> iList2;
	unique_copy(iList.cbegin(),iList.cend(),back_inserter(iList2));
	for (auto i : iList2) {
		cout << i << "\t";
	}
	cout << endl;	
}
//10.28
void test38(){
	vector<int> iVec = {1,2,3,4,5,6,7,8,9};
	list<int> iList,iList2,iList3;
	copy(iVec.cbegin(),iVec.cend(),back_inserter(iList));
	copy(iVec.cbegin(),iVec.cend(),front_inserter(iList2));
	copy(iVec.cbegin(),iVec.cend(),inserter(iList3,iList3.begin()));
	for (auto i : iList) {
		cout << i << "\t";
	}
	cout << endl;	
	for (auto i : iList2) {
		cout << i << "\t";
	}
	cout << endl;	
	for (auto i : iList3) {
		cout << i << "\t";
	}
	cout << endl;	

} 

