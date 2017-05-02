#include <iostream>
using namespace std;

//����ָ��ָ����Ǻ����������ķ������ͺ��β����͹�ͬȷ�����뺯�����޹�
//����һ������
bool lengthCompare(const string &s1, const string & s2);
//����һ��ָ��ú�����ָ�룬ֻ��Ҫ��(*ptr)���溯��������
bool (*pf)(const string &s1, const string & s2);
//ע�����Ų���ʡ��

//ʹ�ú���ָ��
void test() {
	bool(*pLengthComp)(const string &s1, const string & s2);
	pLengthComp = &lengthCompare;//ע�⣬�����ȡ��ַ�����п��ޣ�����Ϊ�˱���һ�²��»����������Ժ󶼼���&
	//����
	bool res = (*pLengthComp)("hello", "world!");
	//����ָ�����û��ָ���κκ��������Ը�ֵΪnullptr
	pLengthComp = nullptr;
}
//�������ָ��ָ�����غ�������ô����ָ������ͱ�����ĳһ�����غ�����ȷƥ��


//�β���Ϊ����ָ�룬������ָ���������Ϊ�βΣ�Ҳ����ʡ��*��
void useBigger(const string &s1, const string &s2, bool(*pf)(const string &s1, const string & s2)) {
	
}
//�򻯺���ָ���д��
typedef decltype(lengthCompare) Func;//Func�ʹ����˺�������
typedef decltype(lengthCompare) *pFunc;//pFunc�Ǻ���ָ������
//Ҳ����дȫ
typedef bool Func(const string &s1, const string & s2);//Func����������
typedef bool (*pFunc) (const string &s1, const string & s2);//pFunc�Ǻ���ָ������



//����ֵΪ����ָ�루�������ܷ��غ��������ǿ��Է��غ���ָ�룩
//�м��ַ�ʽ�������ڷ�������ָ�����ʽ
//�ͺ������͵��ββ�ͬ���������Ͳ����Զ�תΪָ�룬������ʽ����Ϊָ��
//1.ʹ�����ͱ���
using Func = bool(const string &, const string &);
using pFunc = bool(*)(const string &, const string &);
//ʾ��
Func* foo1(void);
pFunc foo2(void);

//2.ʹ��β�÷�������
auto foo3(void) -> bool(*)(const string &, const string &);
//3.ֱ��дȫ
bool(*foo4(void))(const string &, const string &);

//4.ʹ��decltype���������Ѿ����ڸú��������
decltype(lengthCompare)* foo5(void);


void call() {
	useBigger("hello", "world!", lengthCompare);
	pFunc pf = foo1();
	pFunc pf2 = foo2();
	Func * pf3 = foo3();
}


bool lengthCompare(const string &s1, const string & s2) {
	return s1.size() > s2.size();
}