/*
 * 292container.cpp
 *
 *  Created on: 2016��10��3��
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

//��ֵ��swap
//��ֵ�����Ҫ����ߺ��ұߵ�������������ͬ����
//assign�����������Ǵ�һ����ͬ�����ݵ����͸�ֵ�����ߴ�������һ�������и�ֵ��
//assign�����ò�����ָ����Ԫ�صĿ����滻�������������Ԫ��
void test2() {
	list<string> names;
	vector<const char *> oldstyle;
//	names = oldstyle;//error
	names.assign(oldstyle.cbegin(), oldstyle.cend()); //ok
}
//assign�ĵڶ����汾����һ������ֵ��һ��Ԫ��ֵ������ָ����Ŀ�Ҿ�����ͬ����ֵ��Ԫ���滻������ԭ�е�Ԫ��
void test3() {
	list<string> sList(1);
	sList.assign(10, "Hi");
}
//ʹ��swap
void test4() {
	vector<string> sVec(10);
	vector<string> sVec2(24);
	swap(sVec, sVec2);
	//���������������ݵĲ�����֤��ܿ죬Ԫ�ر���δ������swapֻ�ǽ����������������ڲ����ݽṹ
	//ָ�������ĵ����������ú�ָ����swap����֮�󶼲���ʧЧ������ָ��swap����֮ǰ��ָ���Ԫ��
	//swap�г�Ա�����ͷǳ�Ա�İ汾
	//ͳһʹ�÷ǳ�Ա�汾��swap��һ����ϰ��
}

//*****************************************************************************
//ʹ��push_back
void test5() {
	string word;
	vector<string> sVec;
	while (cin >> word) {
		sVec.push_back(word);
	}
}
//ʹ��push_front
void test6() {
	list<int> iList;
	for (size_t i = 0; i != 4; ++i) {
		iList.push_front(i);
	}
	// 3 2 1 0
}
//���������ض�λ�����Ԫ��
//vector list deque string ��֧��insert
//ÿ��insert����������һ����������Ϊ���һ��������������ָ������������ʲôλ�÷�����Ԫ�ء�������ָ���������κ�λ��
//��������β��֮�����һ��λ�á�
//���ڵ���������ָ������β��֮�󲻴��ڵ�Ԫ�ص�λ�ã�������������ʼλ�ò���Ԫ���Ǻ����õĸ������insert�ǽ�
//��Ԫ�ز��뵽��������ָ��λ��֮ǰ

void test7() {
	list<int> iList = { 2, 3, 4 };
	iList.insert(iList.end(), 2);
	iList.insert(iList.begin(), 23);
	for (auto i : iList) {
		cout << i << "\t";
	}
	cout << endl;
}
//���뷶Χ�ڵ�Ԫ��
//insert�����Խ���һ��Ԫ����Ŀ��һ��ֵ����ָ��������Ԫ����ӵ�ָ��λ��֮ǰ����ЩԪ�ض�������ֵ��ʼ��
void test8() {
	vector<string> sVec;
	sVec.insert(sVec.end(), 10, "A");
	for (auto s : sVec) {
		cout << s << "\t";
	}
	cout << endl;
}
//ʹ��insert�ķ���ֵ
//insert����ָ������ӵ�Ԫ�ص�λ�õĵ�����
void test9() {
	list<string> sList;
	auto it = sList.begin();
	string word;
	while (cin >> word) {
		it = sList.insert(it, word);
	}
	//�൱��push_front
	for (auto s : sList) {
		cout << s << "\t";
	}
	cout << endl;
}
//ʹ��emplace����
//��������ǿ���Ԫ��
//�����ǵ���һ��emplace��Ա����ʱ���ǽ��������ݸ�Ԫ�����͵Ĺ��캯���С�
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
//����Ԫ��
//���ʳ�Ա�������ص����á����������const�����򷵻�ֵ��const���á������������const����ô����ֵ����ͨ���á�
void test11() {
	list<int> iList = { 2, 3, 4, 5 };
	if (!iList.empty()) {
		iList.front() = 23;
		auto & v = iList.back();
		v = 1024;
		auto v2 = iList.back();
		v2 = 0;	//v2�������ã�û�иı�iList��ֵ
	}
	for (auto i : iList) {
		cout << i << "\t";
	}
	cout << endl;
}

//�±���ҺͰ�ȫ���������
//�°ڲ�����������Ч��Χ�ڣ���֤�±���Ч�ǳ���Ա������
void test12() {
	vector<string> sVec;
//	cout<<sVec[0];//����
	cout << sVec.at(0);	//���û��Ԫ�أ���ô���׳�һ��out_of_range�쳣
//	terminate called after throwing an instance of 'std::out_of_range'
//	  what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
}

//**********************************************************************************

//ɾ��Ԫ��
//pop_front��pop_back
//string vector��֧��pop_front
//forward_list��֧��pop_back
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
//ʹ��erase�����ܵ���������
void test14() {
	list<int> iList = { 2, 3, 4, 5, 6, 7, 8 };
	for (auto it = iList.begin(); it != iList.end(); ++it) {
		if (*it % 2 == 0) {
			it = iList.erase(it);
			//erase���ر�ɾԪ��֮���Ԫ�صĵ�����
		}
	}
	for (auto i : iList) {
		cout << i << "\t";
	}
	cout << endl;
}
//ɾ�����Ԫ��
//����һ�Ե�����
void test15() {
	list<int> iList = { 2, 3, 4, 5, 6, 7, 8 };
	iList.erase(iList.begin(), iList.end());
	for (auto i : iList) {
		cout << i << "\t";
	}
	cout << endl;
}
//erase��list��ɾ������Ԫ�أ���vector��ɾ��ż��Ԫ��
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
//�������ɾ��Ԫ��ʱ��������Ҫ��������������:һ��������Ҫ�����Ԫ�أ�һ��ָ����ǰ��
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
//�������в��ҵ�һ��string�������ڶ���string���뵽�����ŵ�һ��string֮���λ��
//�����һ��stringû���������У��򽫵ڶ���stirng���뵽��β��
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
//��д�ı�������ѭ������
//������뱣֤ÿ��ѭ���ж����µ����������û�ָ��
//���ѭ���е��õ���insert��erase����ô���µ����������ס���Щ�������ص����������ǿ�����������
void test19(){
	vector<int> iVec = {0,1,2,3,4,5,6,7,8,9};
	auto it = iVec.begin();
	while(it != iVec.end()){
		if(*it % 2 == 1){
			it = iVec.insert(it,*it);
			it+=2;//������ǰԪ�غ͸ղ����Ԫ��
		}else{
			it = iVec.erase(it);
		}
	}
	for(auto i:iVec){
		cout<<i<<"\t";
	}
	cout<<endl;
}
//�����ڵ���insert��erase�󶼸��µ���������Ϊ���߶���ʹ������ʧЧ
//�ڵ���erase֮�󣬲��ص�������������Ϊerase���صĵ������Ѿ�ָ����������һ��Ԫ�ء�����insert����Ҫ��������������

//��Ҫ����end���صĵ���������Ϊend���صĵ��������ǻ�ʧЧ����ӻ�ɾ��Ԫ�ص�ѭ��������뷴������end�����������ȱ���
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

