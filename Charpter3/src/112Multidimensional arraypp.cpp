#include <iostream>
#include <string>
#include <vector>
using namespace std;
//��ά������б��ʼ��
void initArray() {
	int arr[][3] = { 
		{2,1,3},
		{2,1,3}
	};
	int arr2[][3] = { 2,1,3,2,1,3 };//�������ַ�ʽ��ȫ�ȼ�
	int arr3[][4] = { {2},{3},{1} };//��ʼ����ÿ�еĵ�һ��Ԫ��

//	int(&row)[3] = arr[1];//row��һ��һά��������ã�ָ����arr��ά����ĵڶ���
//	cout << row[0] << "  " << row[1] << "  " << row[2] << endl;

	int arrI[2][3];
	//Ƕ��ѭ��������ά����
	//��Ҫ֪��ÿһ��ĳ���
	constexpr size_t row = 2, col = 3;
	for (size_t i = 0; i != row; i++) {
		for (size_t j = 0; j != col; j++) {
			arrI[i][j] = i*row + j;
		}
	}
	/*for (size_t i = 0; i != row; i++) {
		for (size_t j = 0; j != col; j++) {
			cout << arrI[i][j]<<"   ";
		}
		cout << endl;
	}*/
	//ʹ��rangeFor������ά����
	//�������ڲ��ѭ���⣬��������ѭ�����Ʊ�����Ӧ������������
	//��Ϊ��������������ͣ��������Ὣ����תΪָ����Ԫ�ص�ָ�룬�Ǿ�û������ʹ��rangeFor��
	for (auto & row : arrI) {
		for (auto col : row) {
			cout << col << "\t";
		}
		cout << endl;
	}
	//�����Ҫ�޸�ֵ����ô���ڲ��ѭ��ҲҪʹ����������
	for (auto & row : arrI) {
		for (auto&  col : row) {
			col = 21;
		}
	}
	for (auto & row : arrI) {
		for (auto col : row) {
			cout << col << "\t";
		}
		cout << endl;
	}
}
