#include <iostream>
using namespace std;
//c++�в�����������
//���ǿ��Է���ָ��������Ԫ�ص�ָ�����������ã����Ҷ��б�Ҫ��������Ĵ�С
//��������ָ�������ַ�����
//1.ʹ�����ͱ���
using arrI = int[10];
arrI* function(int i);
//���صľ���һ��ָ��һ����10��Ԫ�ص�int�����ָ��

//2.�ȽϷ����ķ�ʽ
//ElementType (*functionName(parameters))[ArraySize]
int(*function(int i))[10];
//�������������ڲ���function(int i)���Ǻ������Ͳ����б�
//������һ��ָ�룬��ʾ���ص���ָ�����ͣ�������ص������ã���ôӦд��int(&function(int i))[10]
//����������int[10]����ʾ���ص�ָ����ָ����10��Ԫ�ص�int��������
//���ű���ӣ����򱨴�

//3.β�÷�������
//auto function(int i) -> int(*)[10];
//�ڷ������ͷ���һ��auto
//���������Ҳ����-> �� ���ص�ʵ�����ͣ�ָ��int[10]��ָ�룩

//4.ʹ��decltype
//��������֪Ҫ�����ĸ����飨�������ⲿ�������
int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };
decltype(odd) * function(int i) {
	return i % 2 == 0 ? &odd : &even;
}
//decltype����������������תΪ��Ӧ��ָ�룬����decltype�Ľ����һ�����飬Ҫ���ʾ����ָ�뻹��������������һ��*
//�޸�Ϊ������������
decltype(odd) & function(int i) {
	return i % 2 == 0 ? odd : even;
}

