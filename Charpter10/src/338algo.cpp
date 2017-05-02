/*
 * 338algo.cpp
 *
 *  Created on: 2016年9月6日
 *      Author: songx
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
//只读算法
//accumulate 累加函数，定义在numeric中。
//前两个参数是范围，第三个参数是和的初值，并且决定了函数中使用哪个加法运算符以及返回值的类型
//序列中的元素类型必须与第三个参数的类型相容
//该算法假定第二个序列至少和第一个序列一样长
void test2() {
	vector<int> iVec = { 2, 3, 4, 5, 5, 6 };
	int sum = accumulate(iVec.cbegin(), iVec.cend(), 0);
	cout << "The sum of vector<int> is " << sum << endl;
	vector<string> sVec = { "The ", "movie ", "is ", "so ", "interesting" };
	string sum2 = accumulate(sVec.cbegin(), sVec.cend(), string(""));
	//注意第三个参数不可以是“”，因为“”类型是const char *，没有定义加法运算
	cout << "The sum of vector<string> is " << sum2 << endl;
}
//equal 确定两个序列是否保存同样的值
//三个参数，前两个是第一个序列中的元素范围，第三个参数是第二个序列的首元素
void test3() {
	vector<int> iVec = { 2, 3, 4, 5 };
	list<int> iList = { 2, 3, 4, 5 };
	cout<<equal(iVec.cbegin(),iVec.cend(),iList.cbegin())<<endl;
	
}
//practice 10.4
void test4(){
	vector<double> dVec = {2,2.231,23,4.23,23.09};
	double sum = accumulate(dVec.cbegin(),dVec.cend(),0);
	//如果第三个参数为int类型，那么每个元素都会转为int类型
	cout<<sum<<endl;
}
//10.5
void test5(){
	vector<const char *> sVec = {"123","234","345"};
	list<const char *> sList = {"123","234","345"};
	cout<<equal(sVec.cbegin(),sVec.cend(),sList.cbegin())<<endl;
}

