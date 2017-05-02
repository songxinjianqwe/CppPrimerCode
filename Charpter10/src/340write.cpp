#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>


using namespace std;
//写容器算法
//需要程序员来保证容器大小至少不少于我们要求算法写入的元素数目
//fill算法，接收一对迭代器，第三个参数是要写入的值，将这个范围的元素都赋为第三个参数的值
void test6() {
	vector<int> iVec = { 2, 3, 4 };
	fill(iVec.begin(), iVec.end(), 0);
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;
}
//fill_n算法
//三个参数，第一个参数是容器的起始迭代器，第二个参数是要填充的元素个数，第三个参数是要放入的元素
//要求程序员保证容器中能容纳这么多的元素
void test7() {
	vector<int> iVec = { 2, 3, 3, 5, 5, 6, 6, 7, 8, 9, 9, 0 };
	fill_n(iVec.begin(), iVec.size(), 0);
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;
}
//插入迭代器
//具有普通迭代器的功能，并且在通过此迭代器赋值时，赋值运算符会调用push_back将一个具有给定值的元素添加到容器中
//函数back_inserter，可以返回一个插入迭代器，定义在头文件iterator
void test8() {
	vector<int> iVec;
	fill_n(back_inserter(iVec), 10, 0);
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;
}
//拷贝算法
//将输入的范围内的元素拷贝到目的序列中
//有三个参数，前两个参数表示一个范围，第三个参数表示目的序列的起始位置
//同样需要程序员保证目的序列的长度足够存放这些元素
void test9() {
	vector<int> iVec = { 2, 3, 3, 4, 5, 6 };
	list<int> iList;
	copy(iVec.begin(), iVec.end(), back_inserter(iList));
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;
}

//多个算法都提供拷贝版本，这些算法计算新元素的值，但是不是将它们放置在输入序列的末尾，而是创建一个新序列保存这些结果
//replace算法
//可以接受4个参数，前两个表示范围，第三个是旧值，第四个是新值

//replace_copy可以接受5个参数，添加一个第三个参数新容器的迭代器，不修改原来的容器，而是将修改后的新值都写入第三个参数
//这个迭代器要求是插入迭代器
void test10() {
	vector<int> iVec = { 2, 3, 4, 5, 5, 5, 5, 5 };
	replace(iVec.begin(), iVec.end(), 5, 0);
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;

	vector<int> iVec2 = { 2, 3, 4, 5, 5, 5, 5, 5 };
	vector<int> iVec3;
	replace_copy(iVec2.cbegin(), iVec2.cend(), back_inserter(iVec3), 5, 0);
	for (auto i : iVec3) {
		cout << i << "\t";
	}
	cout << endl;
}
//sort算法
//排序，接受两个迭代器表示范围
//会使用对象重载的<运算符
//unique算法
//移动元素，覆盖相邻的重复元素，使得不重复元素出现在序列开始位置，返回的迭代器指向最后一个不重复元素之后的位置。此位置之后的元素仍然存在，但是不知道它们的值

//去掉重复元素
//先排序将重复元素放在一起，然后调用unique将多余的重复元素放到序列最后，然后调用容器的删除方法将这些元素删除
void test11() {
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	sort(sVec.begin(), sVec.end());
	auto endUnique = unique(sVec.begin(), sVec.end());
	sVec.erase(endUnique, sVec.end());
	for (auto s : sVec) {
		cout << s << "\t";
	}
	cout << endl;
}
void deDuplication(vector<string> & sVec) {
	sort(sVec.begin(), sVec.end());
	sVec.erase(unique(sVec.begin(), sVec.end()), sVec.end());
}



