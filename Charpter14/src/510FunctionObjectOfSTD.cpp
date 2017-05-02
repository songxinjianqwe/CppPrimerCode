/*
 * 510��׼�ⶨ��ĺ�������.cpp
 *
 *  Created on: 2016��9��17��
 *      Author: songx
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
using namespace placeholders;


//��׼�ⶨ����һ���ʾ�������������ϵ��������߼���������࣬ÿ����ֱ�����һ��ִ�����������ĵ��������
//plus�ඨ����һ������������������ڶ�һ�Ե��ö���ִ�мӷ�����
//��Щ�౻����Ϊģ�����ͣ�����Ϊ���ƶ���������ͣ���������;��ǵ�����������β�����
//plus<string> ��string�ӷ������������string����
//������functionalͷ�ļ���
//������
//plus minus multiplies divides modulus negate
//equal_to not_equal_to greater greater_equal less less_equal
//logical_and logical_or logical_not


void test40(){
	plus<int> intAdd;
	negate<int> intNegate;
	int sum = intAdd(3,5);
	sum = intNegate(2);
	cout<<sum<<endl;
	//�ڱ�׼���㷨��ʹ�ñ�׼�⺯������
	vector<string> sVec = {"a","b","c"};
	sort(sVec.begin(),sVec.end(),greater<string>());
	//������һ����ʱ��greater���������string��<�������������java��comparator
	
	//���ڴ洢����ָ�������ԣ�ʹ��<�������Ƚ�ָ��ֵ��������ϣ�����ǱȽ�ָ����ָ���ֵ
	//��׼��ĺ��������Ƕ������õģ�����Ƚ�ָ����ָ���ֵ
	//ʹ��functionObject<key_type>����
	vector<string *> nameTable;
//	sort(nameTable.begin(),nameTable.end(),[](string *a,string *b){return a<b;});//error
	//Ŀ�Ĳ��ǱȽ�ָ��
	sort(nameTable.begin(),nameTable.end(),less<string *>());
	
}

void prac1(){
	vector<int> iVec = {2048,2047,12023,232,12334,12};
	cout<<count_if(iVec.begin(),iVec.end(),bind(greater<int>(),_1,1024))<<endl;
}
void prac2(){
	vector<string> sVec = {"pooh","pooh","hole"};
	auto begin = find_if(sVec.begin(),sVec.end(),bind(not_equal_to<string>(),_1,"pooh"));
	cout<<*begin<<endl;
}
void prac3(){
	vector<int> iVec = {23,4,2321,23,23,2321,123,42};
	transform(iVec.begin(),iVec.end(),iVec.begin(),bind(multiplies<int>(),_1,2));
	copy(iVec.begin(),iVec.end(),ostream_iterator<int>(cout,"\t"));
	cout<<endl;
}
bool canDividedExactly(int val,const vector<int> & iVec){
//	return !accumulate(iVec.begin(),iVec.end(),3,modulus<int>());
	modulus<int> mod;
	return any_of(iVec.begin(),iVec.end(),[&](int i){return 0 == mod(val,i);});
}


int main(void){
	vector<int> iVec = {3,6,9,12};
	cout<<canDividedExactly(3,iVec)<<endl;
}




