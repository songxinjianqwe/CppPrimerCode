#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct SalesData {
	string isdn;
	int num;
	double price;
	double revenue;
};
void testSizeOf() {
	SalesData data, *p = &data;
	SalesData & ref = data;
	cout << "sizeof(SalesData):" << sizeof(SalesData) << endl;//�����ṹ��ĳ���
	cout << "sizeof(data):" << sizeof(data) << endl;//�����ṹ��ĳ���
	cout << "sizeof(p):" << sizeof(p) << endl;//ָ��ĳ��� 4
	cout << "sizeof(*p):" << sizeof(*p) << endl;//�����ṹ��ĳ���
	cout << "sizeof(ref):" << sizeof(ref) << endl;//�����ṹ��ĳ���
	cout << "sizeof(SalesData::isdn):" << sizeof(SalesData::isdn) << endl;//�ṹ����һ����Ա�����ĳ���
	cout << "sizeof(data.isdn):" << sizeof(data.isdn) << endl;//�ṹ����һ����Ա�����ĳ���
	//sizeof ����Ҳ���Բ�������
	int arr[] = { 2,2,1,3,5,2 };
	cout << "sizeof(arr):" << sizeof(arr) << endl;//��������ĳ���֮��
	//sizeof string��vectorֻ���������͹̶����ֵĴ�С�������������е�Ԫ��ռ���˶��ٿռ�
	//����sizeof�õ����鳤��
	//sizeof���Եõ�һ���������ʽ
	constexpr size_t size = sizeof(arr) / sizeof(*arr);
	int arr2[size];

	//�������һ��ָ��ָ������飬��ôsizeof��ָ�룩�Ľ��������������Ĵ�С������ָ��Ĵ�С
	int *pArr = arr;
	cout << "sizeof(pArr) / sizeof(*pArr): " << sizeof(pArr) / sizeof(*pArr) << endl;
	
	//���������
	//�����ҵ�˳����ֵ�����ս�����Ҳ���ʽ��ֵ
	//��������forѭ����
}
