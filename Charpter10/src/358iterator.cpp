#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

//����Ϊÿ����������ĵ�����֮�⣬ͷ�ļ�iterator���м��ֵ�����
//���������������������������������ƶ�������

//���������
//������ͨ��һ��������������и�ֵʱ���õ������������������������������ָ��λ�ò���һ��Ԫ��
//*it = t ��Ԫ��t���뵽it��ָ���Ԫ��֮ǰ
//*it,it++,it-- ��Щ����û�����壬������it
//�������������Ԫ�ز����λ�÷�Ϊ����
//��Щ�����ĵ�һ��������������
//back_inserter ʹ��push_back
//front_inserter ʹ��push_front
//inserter ���ܵڶ���������������һ��ָ����������ĵ�������Ԫ�ؽ������뵽������������ָ���Ԫ��֮ǰ
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

