#include <iostream>
#include <vector>
#include <string>
using namespace std;
//����ת������
//1����intС������ֵ��������Ϊ�ϴ���������ͣ�����ܴ����int�оͷ���int�У��Ų��¾ͷ���unsigned int
//2�������зǲ���ֵתΪ����ֵ
//3����ֵ��䣬�Ҳ��������תΪ�����������ֵ
//4���������������ϵ�����ж������ͣ���ҪתΪͬһ����
//5���޷������͵�����������Ƚ�����������
//���һ�����з������ͣ���һ�����޷������ͣ���Ϊ���������
//1) �з�������>=�޷������ͣ���ô�з�������תΪ�޷������ͣ��������䣬���������޷�������ģ��
//2) �з�������<�޷������ͣ���ô������޷������͵�����ֵ���ܴ��ڸ��з������ͣ���ô�޷������͵��������תΪ�з������ͣ������з�������תΪ�޷�������

//������ָ��ǳ�����ָ��/����ת����ָ����Ӧ�ĳ������͵�ָ��/����
//int i ;
//const int & j = i;
//const int * p = &i;
//int & k = j;//error

//ǿ������ת��
//�﷨��cast-name<type>(expression)
//cast-name ��static_cast,dynamic_cast,const_cast,reinterpret_cast
void cast() {
	//static_cast
	//�κξ�����ȷ���������ת����ֻҪ�������ײ�const��ָ������ָ�룩��������ʹ��static_cast
	int i = 23,j = 12;
	double d = static_cast<double>(i) / j;
	cout << d << endl;
	
	//const_cast
	//ֻ�ܸı��������ĵײ�const
	//����������תΪ�ǳ����������Ϊ����Ϊȥ��const���ʡ�
	//һ��ȥ��const���ʣ��������Ͳ�����ֹ�Ըö������д�����ˡ�
	//����ö���ǳ�������ô�ǺϷ��ģ�����ǳ�������ô�����δ����ĺ��
	const char * pc = "hhh";
	char * p = const_cast<char*>(pc);
	//const_cast�����ں������ص���������

	//reinterpret_cast
	//ͨ��Ϊ��������λģʽ�ṩ�ϵͲ���ϵ����½���
	//�����������ڻ���
}