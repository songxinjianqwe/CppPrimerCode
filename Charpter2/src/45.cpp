#include <iostream>
using namespace std;
int main(void) {
	int val = 1024;
	int & refVal = val;
	cout << val << endl;
	cout << refVal << endl;//���þ��Ǳ���������ֱ��������൱�����ԭֵ
	//���ò��Ƕ���û��ʵ�ʵ�ַ
	//�����ڶ���ʱ��Ҫ��&��ʹ��ʱ����Ҫ�ټ��������������ʱ��ü��ϱ�ʶ����ʾ�������������
	//�ڶ����ͬʱ�������һ����ֵ��������������������Ҳ���Ǳ���󶨵�һ���������ϣ�
	refVal = 2014;
	cout << val << endl;//ͨ�����ÿ����޸�ԭֵ
	int val2 = 3;
	refVal = val2;//���ò������°󶨵���һ�������ϣ�������ʵ�����ǽ���һ��������ֵ����ԭ���ı���
	cout << refVal << endl;
	cout << val << endl;

	double val3 = 20.14;
	refVal = val3; //ʵ�����ǽ�double ���͵�ֵתΪintȻ�󸳸�val
	cout << refVal << endl;
	refVal = 10.21;//ʵ�����ǽ�double ���͵�ֵתΪintȻ�󸳸�val
	cout << refVal << endl;

	//ע��󶨵�ʱ����������ñ�����ͬһ����
	int i = 2;
	int & refi = i;
	//	double & refi = i;//error
	double d = 32;
	double & refd = d;
	i = refd;//���Խ����ø���һ���������൱�ڽ�����ָ�������ֵת�ͺ󸳸��ñ���
	refd = i;//Ҳ���Խ������������ã��൱�ڸñ�����ֵ����������ָ��ı���
	refi = refd;//Ҳ���Խ�һ�����ø�����һ�����ã��൱�ڽ���һ������ָ�������ֵ����ǰһ������ָ���ֵ
	cout << i << endl;
	cout << endl;
	//��ϰ2.17
	int i2, &refI2 = i2;
	i2 = 5;
	refI2 = 10;
	cout << i2 << "  " << refI2 << endl;
	return 0;
}
