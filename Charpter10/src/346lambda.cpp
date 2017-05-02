#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


using namespace std;

//������������ϲ��㣬Ϊ���ֲ���һ�㣬����lambda
//֮ǰ�ĺ���д���˱ȶ��ٸ��ַ������������������뽫����ַ�������Ϊ�������룬�ǲ����еġ�
//lambda����������һ��

//�ɵ��ö��󣺶����κ�һ�����ʽ��������Զ���ʹ�õ�������������������Ϊ�ɵ��õġ�
//�������ֿɵ��ö��󣺺���������ָ�롢�����˺���������������ࡢlambda���ʽ

//һ��lambda���ʽ��ʾһ���ɵ��õĴ��뵥Ԫ�����ǿ��Խ������Ϊһ��δ����������������
//һ��lambda���ʽ����һ���������ͣ�һ�������б�һ�������壬���ʽû�����֣����Զ����ں����С�
//��ʽ��[capture list](parameter list)->return type {body}
//�����б���һ��lambda���ں����ж���ľֲ��������б�����Ϊ��
//���в����б�ͷ��������ǿ��Ժ��Եģ��������б�ͺ������ǲ��ɺ�O�Ե�
//������Է������ͣ�lambda����ݺ������еĴ����ƶϳ��������ͣ����lambda�ĺ���������κε�һreturn���֮������ݣ���δָ���������ͣ��򷵻�void

//��lambda����
//ʵ�κ��β����ͱ���ƥ�䣬���Ҳ�����Ĭ�ϲ���
//�ղ����б��ʾ��lambda���ʽ�����������ں������е��κξֲ�����

//ʹ�ò����б�
//һ��lambdaͨ�����ֲ������������䲶���б�����ָ������ʹ����Щ�����������б�ָ��lambda�����ڲ��������ʾֲ������������Ϣ
//lambda����ֱ��ʹ�þֲ���̬�������������ں���֮�������ĺ���
extern void deDuplication(vector<string> & sVec);

void test15() {
	auto f = [] {return 42;};
	//������һ���ɵ��ö���f������ʹ�õ��������������
	cout << f() << endl;
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	deDuplication(sVec);
	stable_sort(sVec.begin(), sVec.end(),
			[](const string & s1,const string &s2) {return s1.size() < s2.size();});
	for (const auto & s : sVec) {
		cout << s << "\t";
	}
}

//find_if�㷨
//��������������ǰ������ʾ��Χ����������һ��һԪν�ʣ��� �����е�ÿ��Ԫ�ص��ø��������ν�ʣ������ص�һ��ʹν�ʷ��ط�0ֵ��Ԫ�أ���������ڣ���ô����β����������ڶ���������
//for_each�㷨
//��������������ǰ������ʾ��Χ����������һ��һԪν�ʣ��������е�ÿ��Ԫ�ض����ô�ν��
//
//����ַ��������д��ڸ������ȵ��ַ�����������������Ƕ�ָ̬��
//�Ƚ���������������Ȼ���ҵ���һ�����ȴ��ڸ���ֵ�ĵ��������Ӵ˴���ĩβ��Ԫ�ض��ǳ��ȴ��ڸ���ֵ��Ԫ�أ����for_each�㷨���
void test16(string::size_type sz) {
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	deDuplication(sVec);//ȥ��
	//����������
	stable_sort(sVec.begin(),sVec.end(),[](const string &s1,const string &s2){return s1.size()<s2.size();});
	auto start = find_if(sVec.begin(), sVec.end(),
			[sz](const string & str) {return str.size() > sz;});
	for_each(start,sVec.end(),[](const string & s){cout<<s<<"\t";});
	cout<<endl;
}
