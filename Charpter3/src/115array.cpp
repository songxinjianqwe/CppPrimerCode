#include <iostream>
#include <iterator>
#include <cstdlib>
using namespace std;

void ptrAndArray() {
	int arr[3][4];
	int (*pArr)[4] = &arr[2]; //pArr��һ������ָ�룬ָ��arr����ĵ�����
	pArr = arr; //ָ��arr����ĵ�һ��(������Ϊ��Ԫ��ָ��)
	//����
//	int *ip[4];
//	int(*ip2)[4];
	//���ô��ڵ���Ķ�����ǰ����һ��ip���飬����Ԫ����int*��������һ��ָ������
	//������һ��ipָ�룬ָ��һ��int[4]���飬������һ������ָ��
	//C++11��׼����ʹ��auto���ܿ���Щ���ӵ�����

	//ʹ��Ƕ��ѭ����������ά���飬��Ҫ��֪������㳤��
	for (auto pRow = arr; pRow != arr + 3; pRow++) {
		for (auto pCol = *pRow; pCol != *pRow + 4; pCol++) {
			//��һ�������ñ�ʾ��һ��
			*pCol = rand();
			cout << *pCol << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	//ʹ��begin��end��Ƕ����������ά���飬����Ҫ֪�����㳤��
	//���ַ�ʽ���Ӽ��
	for (auto pRow = begin(arr); pRow != end(arr); pRow++) {
		for (auto pCol = begin(*pRow); pCol != end(*pRow); pCol++) {
			cout << *pCol << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	//ʹ�����ͱ������м�
	using intArray = int[4];
	for (intArray *pRow = arr; pRow != arr + 3; pRow++) {
		for (int * pCol = *pRow; pCol != *pRow + 4; pCol++) {
			cout << *pCol << "\t";
		}
		cout << endl;
	}
}

