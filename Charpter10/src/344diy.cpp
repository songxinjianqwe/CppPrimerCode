#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
//���Ʋ�����
//��������Ĭ���ǰ���<��������ؽ��������
//���û�����أ�������Ҫ����������ԣ������Լ����ƣ�һ�ֶ��Ʒ������Ǵ���Ƚϵĺ���
//ע�⺯����Ϊ����ʱ��Ҫд()
extern void deDuplication(vector<string> & sVec);

//����ϣ���������Ȱ��������򣬳�����ͬ�İ��ֵ�����
//��Ҫ�����Ȱ��ֵ������ٰ��ճ������򣬲��ҳ��������㷨���ڳ�����ȵ�Ԫ�ز��ı����ǵĴ���
//sort����һ���汾�����ܵ�������������һ��ν��
//ν����һ���ɵ��õı��ʽ���䷵�ؽ����һ��������������ֵ��
//��һԪν�ʺͶ�Ԫν�ʣ�һԪν����ζ��ֻ���ܵ�һ��������Ԫν�ʽ�����������
//����һ����Ԫν�ʲ�����sort���������ν��������<�������
bool isShorter(const string & s1,const string & s2){
	return s1.size() < s2.size();
}
//����������

//stable_sort�㷨���ȶ������㷨�����������Ԫ�ص�ԭ��˳��

void test12(){
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	deDuplication(sVec);
	stable_sort(sVec.begin(),sVec.end(),isShorter);
	for(const auto & s:sVec){
		cout<<s<<"\t";
	}
	cout<<endl;
}


