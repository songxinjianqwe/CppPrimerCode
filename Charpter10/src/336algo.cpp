#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
using namespace std;
//������㷨��������algorithm��numericͷ�ļ���
//��Щ�㷨��ֱ�Ӳ������������Ǳ���������������ָ����һ��Ԫ�ط�Χ
//��Щ�㷨���Ƿ��͵ģ�����֧����������������
//�㷨����ִ�������Ĳ���������ִ�е������Ĳ������㷨��Զ����ı�ײ������Ĵ�С�����ܻ�ı�Ԫ�ص�ֵ�����Ի��ƶ�Ԫ�أ�������ֱ�Ӳ���ɾ��Ԫ��
//��׼�ⶨ����һ������ĵ�������Ϊ�������������ڵײ��������ִ�в������

void test1(){
	vector<int> iVec = {2,3,4,5,6,6,6,6,6,6};
	auto result = find(iVec.cbegin(),iVec.cend(),2);
	//����Ҳ�������ô���صڶ���������Ҳ����β�������
	cout<<"The result:"<<(result != iVec.cend() ? "Found!":"Not Found")<<endl;
	
	//������������
	int iArr[] = {2,3,4,5};
	int * result1 = find(begin(iArr),end(iArr),4);
	cout<<"The result:"<<(result1 != end(iArr) ? "Found!":"Not Found")<<endl;
	
	cout<<count(iVec.begin(),iVec.end(),6)<<endl;
}
int myCount(const vector<int> & iVec,int val){
	return count(iVec.cbegin(),iVec.cend(),val);
}

int myCount(const list<string> & sList,const string & val){
	return count(sList.cbegin(),sList.cend(),val);
}
int main(void){
	test1();
	vector<int> iVec ={2,3,4,5,5,5,5,5,5,5,5};
	list<string> sList = {"ks","ks","ks","12","sd"};
	cout<<myCount(iVec,5)<<endl;
	cout<<myCount(sList,"ks")<<endl;
	return 0;
}
