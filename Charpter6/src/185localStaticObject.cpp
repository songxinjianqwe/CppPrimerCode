#include <iostream>
using namespace std;
//�ֲ���̬����
//static ����
//�ڳ���ִ��·����һ�ξ������������ʱ��ʼ��������ֱ����������������ű����١��ڴ��ڼ伴ʹ�������ڵĺ�������ִ��Ҳ���������Ӱ�졣
//���û����ʽ��ʼ������ô�ֲ���̬������ִ��ֵ��ʼ��������������Ϊ0��
size_t countCalls() {
	static size_t counter = 0;
	return ++counter;
}
int main(void) {
	for (int i = 0; i < 10; i++) {
		cout << countCalls() << endl;
	}
}
