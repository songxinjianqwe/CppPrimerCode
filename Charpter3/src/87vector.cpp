#include <iostream>
#include <vector>
#include <string>
using namespace std;
//vector
//����ʹ�÷���
//vector<int> vector<string>
//vector ��ʼ��
void initVector() {
	//һ������£�Բ���ű�ʾ���죬�����ű�ʾ�б��ʼ��
	//����ҲҪ���ݷ��͵����ͣ������Ϊ��ֵ�ͣ���ô������Ҳ�ܱ�ʾ����

	//1
	vector<int> vec;
	//2
	vector<int> vec2 = vec;//��������java��ͬ������ָ��ͬһ����
	//3
	vector<int> vec(10);//vector�ж�����10��Ԫ�أ�����Ĭ�ϳ�ʼ��
	vector<int> vec{10};//ֻ��һ��Ԫ��
//	vector<string> vec{10};//��10��Ԫ��
	//ǰ�������������ڣ�����vector�����ͣ��������ֵ����ô��Ϊ�б��ʼ�������������ֵ����ô��Ϊ����
	
	//4
	vector<int> vec(2, 32);//vector�ж���������32 vector<T>(n,val) ������n��Ԫ�أ���val����ʼ��
	//5
	vector<int> vec = { 23,4512,123,54,213,123 };//��������ĳ�ʼ��
	//������֮������Ԫ�ض���õ�Ĭ�ϵĳ�ʼ��
}
