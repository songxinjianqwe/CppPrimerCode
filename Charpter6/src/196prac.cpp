#include <iostream>
using namespace std;
//6.21
int max(int val,const int *ptr) {
	if (val > *ptr) {
		return val;
	} else {
		return *ptr;
	}
}
//6.22
//����ָ���ֵ
void swapPtr(int * &p1, int * &p2) {
	int * temp = p1;
	p1 = p2;
	p2 = temp;
}
//6.23
void print(const int arr[], size_t size) {
	for (size_t i = 0; i != size; i++) {
		cout << arr[i] << endl;
	}
}
void print(const int * ptr) {
	//�ʺ��н�����־�����
	while (ptr) {
		cout << *ptr++ << endl;
	}
}
void print(const int * begin, const int * end) {
	while (begin != end) {
		cout << *begin << endl;
		begin++;
	}
}
void print(const int(&arr)[2]) {
	for (auto i : arr) {
		cout << i << endl;
	}
}

//���д��������ʽ����ôû�б�Ҫ�����������ϳ��ȣ�ֱ�Ӽ�һ������˵�����ȼ���
//���д��ָ����ʽ����ôҲ�Ǽ���һ�����ȵĲ���
//ֻ��д�����õ���ʽ���ű����������ĳ��ȣ���ʱҲ���üӲ�����

int main(void) {
	int arr[2] = { 1,2 };
	print(arr);
	print(begin(arr), end(arr));
	print(arr, 2);
}
