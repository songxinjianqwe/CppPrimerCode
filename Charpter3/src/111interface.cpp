#include <iostream>
#include <string>
#include <vector>
using namespace std;
//����string��c����ַ���
//string��һ����Ա���������Է��ظ��ַ�����char����汾
void t() {
	string s = "HelloWorld";
	const char * str = s.c_str();
	//����ʹ��const char*������
	//��������ı���string����ôc_str���صĽ��Ҳ��ı�
	//�Ƚϱ��յķ����Ǹ���һ��
}
//ʹ����������ʼ��vector
//ע���ǿ����ķ�ʽ
void initVector2() {
	int arr[] = { 1,2,3,4 };
	vector<int> iVec(begin(arr), end(arr));
	for (auto i : iVec) {
		cout << i << endl;
	}
	cout << endl;
	//���Խ������һ���ָ��Ƶ�vector��
	vector<int> iVec2(arr + 1, arr + 3);
	//������ĵڶ���Ԫ����������Ԫ�ظ��Ƶ�vector��
	//�ӵ�һ��ָ��ָ���Ԫ�ؿ�ʼ���ڶ���ָ��ָ��Ԫ�ص�ǰһ��Ԫ��Ϊֹ
	for (auto i : iVec2) {
		cout << i << endl;
	}
}
