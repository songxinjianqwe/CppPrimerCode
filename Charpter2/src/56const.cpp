#include <iostream>
typedef char * pstring;
void testPointer() {
	//const��ָ��
	//��Ϊ���ָࣺ������ָ��ͳ���ָ��
	//��һ�ָࣺ������ָ�루�ײ�const��
	//������һ����ָ������ָ�����ָ��һ��const���εı�����Ҳ����ָ��һ��û����const���εı���
	//��������ͨ��ָ�����޸ı�����ֵ
	//һ������ֻ����һ��ָ������ָ����ָ�򣬶������ɷ�const��ָ��ָ��
	//ʾ��
	const int i = 21;
	const int * ptrI = &i;
//	*ptrI = 21;//error
	int i2 = 21;
	ptrI = &i2;//ok
//	*ptrI = 123;//error

	const int i3 = 12;
//	int * ptrI3 = i3;//error

	//�ڶ��ࣺ����ָ�루����const��
	//����ָ�����˼����ָ�뱾����һ��������������г�ʼ��ָ��һ�����������Ҳ���ָ����������
	//����ָ��Ҳ����ͨ��ָ�����޸�ָ��ı�����ֵ
	//ʾ��
	int i4 = 21;
	int * const ptrI4 = &i4;
	int i5 = 2112;
//	ptrI4 = &i5;//error
//	int * const ptrI;//error
	//���߼����֮�ľ���ָ�����ĳ���ָ�룬�Ȳ���ָ����������Ҳ����ͨ����ָ���޸�ָ��ı�����ֵ
	const int * const ptr = &i4;

//	const int i5;//error const����������г�ʼ��


	//��ִ�б����Ŀ�������ʱ��������������𣺳���ָ�벻��Ӱ��
	int i6 = 21;
	const int ci7 = 12;
	const int * p2 = &i6;
	const int * const p3 = p2; 
	p2 = p3;//ok p3�ǳ���ָ�룬��p2û��Ӱ��
	i6 = ci7;

	//��ָͨ�벻�ܸ�ָ������ָ���ֵ����Ϊ����ͨ����ָͨ��ȥ�޸�ԭ������ֵ
	//��֮���ǳ�������ת���ɳ�������֮����
//	int * p4 = p2;//error
	//�����ã���const������Ҳ��������const����
//	int & ref = ci7;//error

	//const�����ͱ���
	char ch = 'A';
	const pstring pstr = &ch;
	//ע�⣬����ͳ�ʶ������ͬ
	//const pstring pstr �൱�� char * const pstr��Ҳ����ָ���ַ��ĳ���ָ��
	//����������ǽ�����Ϊconst char * pstr��Ҳ����ָ�����ַ���ָ��
} 
  