#include <iostream>
using namespace std;
extern int i2 = 23;
void testConst() {
	//const�����������ֵ�����޸ģ��൱��java�е�final
	const int i = 3;
//	i = 5;//error
	//��������У��Ὣ����const�������ֵĵ�ַ�滻Ϊ��ֵ
	//const���������ļ�����Ч����ʹ�����ͬ�ļ�������ͬ����const������Ҳ����Ӱ��

	//�������һ��const�����ڶ���ļ��й�����ô��Ҫ����extern�ؼ���
	//�����������Ƕ��嶼��Ҫ����extern
}
void testConst2() {
	//const������
	//�Գ��������ã���Ƴ�������
	//Ҫ�����ñ�����һ��const���ã����������Լ�const��Ҳ���Բ���const
	//�������������ö���const��ʱ�򣬸ñ��������ɱ䣬Ҳ����ͨ�����������ı���
	//����������const������������const��ʱ�򣬸ñ�������ɱ䣬������ͨ�����������ı���
	//const���ÿ���ָ��һ��������
	//1.
	const int i = 12;
	const int & refI = i;
//	refI = 21;//error
	//2.
	int i2 = 123;
	const int & refI2 = i2;
//	refI2 = 1234;//error
	i2 = 21;//ok
	const int & refI3 = 32;//const���ÿ���ָ��һ��������
}
