#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;
//�䳤������C++���м���ʵ�ַ�ʽ
//��һ���ǵ�����������ͬʱ������ʹ�ñ�׼������initializer_list
//�ڶ����ǵ��������Ͳ�ͬʱ������ʹ�ÿɱ����ģ��
//������ֻ���۵�һ�����

//���Ĳ���ʮ��������vector
//��Ҳ��һ��ģ�����ͣ���Ҫ˵�����Ͳ���
//��vector��ͬ���ǣ�����Ԫ��һ����ʼ���Ͳ����ٸı�
//��ʼ���ķ�ʽ���б��ʼ��{..,....}
//�����ֱ�����ʽ����Χfor��begin��endָ��
void errorMsg(initializer_list<string> list) {
	for (auto begin = list.begin(); begin != list.end(); begin++) {
		cout << *begin << endl;
	}
}
//�������list��Ҳ���Լ��������Ĳ������������ܷ������һ���ǿɱ�����������һ��λ����
void errorMsg(int errCode, initializer_list<string> list) {
	cout << errCode << endl;
	for (auto begin = list.begin(); begin != list.end(); begin++) {
		cout << *begin << endl;
	}
}
int main(void) {
	errorMsg({ "haa", "mmam" });
	errorMsg(2, { "haa", "mmam" });
	return 0;
}
