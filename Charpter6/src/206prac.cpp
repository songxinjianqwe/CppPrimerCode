#include <iostream>
#include <string>
using namespace std;
//����һ������ָ��10��Ԫ�ص�string���������
string(&func())[10];
//ʹ�����ͱ���
using arrStr = string[10];
arrStr & func();
//ʹ��β�÷�������
auto func()->string(&)[10];
//ʹ��decltype
string arr[10] = { "2" };
decltype(arr) & func();

//�����Ӧ�������ͱ�������ʽ
