/*
 * 338algo.cpp
 *
 *  Created on: 2016��9��6��
 *      Author: songx
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
//ֻ���㷨
//accumulate �ۼӺ�����������numeric�С�
//ǰ���������Ƿ�Χ�������������Ǻ͵ĳ�ֵ�����Ҿ����˺�����ʹ���ĸ��ӷ�������Լ�����ֵ������
//�����е�Ԫ�����ͱ������������������������
//���㷨�ٶ��ڶ����������ٺ͵�һ������һ����
void test2() {
	vector<int> iVec = { 2, 3, 4, 5, 5, 6 };
	int sum = accumulate(iVec.cbegin(), iVec.cend(), 0);
	cout << "The sum of vector<int> is " << sum << endl;
	vector<string> sVec = { "The ", "movie ", "is ", "so ", "interesting" };
	string sum2 = accumulate(sVec.cbegin(), sVec.cend(), string(""));
	//ע������������������ǡ�������Ϊ����������const char *��û�ж���ӷ�����
	cout << "The sum of vector<string> is " << sum2 << endl;
}
//equal ȷ�����������Ƿ񱣴�ͬ����ֵ
//����������ǰ�����ǵ�һ�������е�Ԫ�ط�Χ�������������ǵڶ������е���Ԫ��
void test3() {
	vector<int> iVec = { 2, 3, 4, 5 };
	list<int> iList = { 2, 3, 4, 5 };
	cout<<equal(iVec.cbegin(),iVec.cend(),iList.cbegin())<<endl;
	
}
//practice 10.4
void test4(){
	vector<double> dVec = {2,2.231,23,4.23,23.09};
	double sum = accumulate(dVec.cbegin(),dVec.cend(),0);
	//�������������Ϊint���ͣ���ôÿ��Ԫ�ض���תΪint����
	cout<<sum<<endl;
}
//10.5
void test5(){
	vector<const char *> sVec = {"123","234","345"};
	list<const char *> sList = {"123","234","345"};
	cout<<equal(sVec.cbegin(),sVec.cend(),sList.cbegin())<<endl;
}

