#include <stddef.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

//�������������ͱ�����
//key_type:�ؼ�������
//mapped_type:ֵ�����ͣ���������map
//value_type:����set����key_type��ͬ������map��Ϊpair<const key_type,mapped_type>

//ע��ؼ��ֶ���const�ģ�set��Ԫ�ز��ɱ䣬map��key���ɱ�

//������
//������һ����������������ʱ�����ǻ�õ�һ������Ϊ������value_type��ֵ������
void test9(){
	map<string,size_t> wordCount;
	for(auto it = wordCount.begin();it != wordCount.end();it++){
		cout<<it->first<<endl;
		it->second++;
	}
	
}
//set�ĵ���������ֻ���ģ������õ��������޸�Ԫ��
//�������õ���������һ��map��setʱ���������ᰴ�ؼ����������

//ͨ�����ǲ��Թ�������ʹ�÷����㷨����Ϊ���������ĵ�������const�ģ�map��key��const��value���ǣ�
//ֻ����ʹ��ֻ�����㷨�����͵������㷨Ч�ʽϵͣ���Ϊ���ܰ������ǵĹؼ��ֽ��п��ٲ��ң�����˳�����
//ʹ�ù������������find�㷨�ȷ���find��ö�
//���������Ҫ��һ����������ʹ���㷨��Ҫô��������һ��ԭ���У�Ҫô����һ��Ŀ��λ�á�����copy

//
void test10(){
	vector<string> sVec;
	multiset<string> sSet;
	copy(sVec.begin(),sVec.end(),inserter(sSet,sSet.end()));
//	copy(sVec.begin(),sVec.end(),back_inserter(sSet));sSetû�ж���push_back����
	copy(sSet.begin(),sSet.end(),inserter(sVec,sVec.end()));
	copy(sSet.begin(),sSet.end(),back_inserter(sVec));
}
