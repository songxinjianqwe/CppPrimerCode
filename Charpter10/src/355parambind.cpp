/*
 * 355parambind.cpp
 *
 *  Created on: 2016��9��7��
 *      Author: songx
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::placeholders;
//lambda��ʹ��Ҳ���ھ��ޣ�ֻ������ֻ��һ�����ط�ʹ�õļ򵥲��������Ҫ�ڶ���ط�ʹ�ã���ô���Ǻ������á�
//��Ϊ��������Ϊν�ʴ���ȱ�ݣ�����ȱ������ԣ����ܴ��ݲ���
//Ϊ���ֲ���һȱ�ݣ�ʵ�ֺ�lambdaһ����Ч�������ǿ���ʹ��bind����ʵ�֡�ԭ�������������������ǽ��������а�װ����Ӳ�����Ȼ��õ�һ����װ����µĺ���
bool checkSize(const string & str,string::size_type sz){
	return str.size() > sz;
}
//����������������Ҫ��ΪһԪν�ʣ���ô��Ҫ���ڶ�������һ��ֵ������ʹ�ú�������Ϊֻ����һ������
//��׼�⺯��bind����ʵ����һ�㣬������functionalͷ�ļ���
//auto newCallable = bind(callable,argsList);
//�����ǵ���newCallableʱ��newCallable�����callable�����������ݸ�argsList
//argsList���԰���ʵ�ʵ�ʵ�Σ�������Ҫ�����Ĳ��������Լ���ռλ������ʽ��_n
//��������λ�õĲ�����Ϊ�µĺ����ĵ�һ��������ռλ��Ӧ��д��_1���Դ�����
//�����Ļ������˿������ʵ��֮�⣬Ҳ���Ե���������˳��

//����_n������һ����Ϊplaceholders�������ռ��У���������ռ䱾������std�����ռ䡣Ϊ��ʹ����Щ���֣������������ռ䶼Ҫд�ϡ�
//using namespace namespace_name; ����������ʹ����������namespace_name�����ֶ����������ǵĳ�����ֱ��ʹ�á�
//��������ռ䶨����functionalͷ�ļ���

//ע�⣬��lambda���������һ����bind����Ĭ�϶��ǿ����������Ϊ��ʵ�ִ�����
//����Ҫʹ�ñ�׼�⺯��ref���õ�һ�����������
void print(ostream & os,const string & s){
	os<<s<<"\t";
}
bool compare(const string &s1,const string &s2){
	return s1.size()<s2.size();
}
void test32(){
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	sort(sVec.begin(), sVec.end(),compare);
	auto biggerStart = find_if(sVec.begin(), sVec.end(),
			bind(checkSize,_1,4));
	for_each(biggerStart, sVec.end(),bind(print,ref(cout),_1));
	cout << endl;
}
