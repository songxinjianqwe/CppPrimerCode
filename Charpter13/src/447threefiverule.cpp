/*
 * 447threefiverule.cpp
 *
 *  Created on: 2016��9��12��
 *      Author: songx
 */
#include <iostream>
using namespace std;
//���巨��
//��������:��ǰ��֪�� �������캯����������ֵ���������������
//1.����������һ���п������캯���Ϳ������������������ָ�룬����ʱ��������Ĭ�ϵĿ���ָ�룬�����޸�Ϊ����ֵ��
//2.�������캯���Ϳ�����ֵ���������ͬʱ���ڻ�ͬʱ�����ڣ�����������û��Ҫ�󣩣����綨���һ�޶������
int publicId = 0;
class Numbered{
public:
	Numbered():id(++publicId){}
	Numbered(const Numbered & n):id(n.id+1){}
	int id;
};
void f(Numbered s){
	cout<<s.id<<endl;
}
void f(const Numbered &s){
	cout<<s.id<<endl;
}
void test10(){
	Numbered a,b = a,c = b;
	f(a);
	f(b);
	f(c);
	//13.14
	//1 1 1 
	
	//14.15
	//2 3 4 ����1 2 3�����ú������Ϊ2 3 4 
	
	//14.16
	//1 2 3 
	
}




