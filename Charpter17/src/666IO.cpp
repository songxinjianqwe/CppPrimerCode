/*
 * 666IO.cpp
 *
 *  Created on: 2016��10��1��
 *      Author: songx
 */




#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

//IO��
//��ʽ���������
//��׼�ⶨ����һ����ݷ����޸����ĸ�ʽ״̬��һ�����ݷ���һ����������һ�����󣬻�Ӱ������״̬�������������������������������
//����������������������ݷ�Ҳ��Ӱ�����������������������ǿ�����һ���������ϲ��ݷ������ݡ�
//���ݷ�����������������ƣ�������ֵ��������ʽ�Լ����Ʋ��׵�������λ�ã�������ı��ʽ״̬�Ĳ��ݷ���������/��ԭ�ɶԵġ�
//һ�����ݷ���������ʽ״̬����Ϊһ����ֵ������һ���������临ԭ���ָ�Ϊ������Ĭ�ϸ�ʽ��

//�����ݷ��ı����ĸ�ʽ״̬ʱ��ͨ���ı���״̬�����к���IO����Ч��
//ͨ������ڲ�����Ҫ�����ʽʱ���콫���ָ���Ĭ��״̬


//1.���Ʋ���ֵ�ĸ�ʽ
//boolalpha������ֵ��ӡֵ����Ϊtrue false 
//noboolalpha����ԭ״

void test10(){
	cout<<true<<"\t"<<false<<endl;
	cout<<boolalpha<<true<<"\t"<<false<<noboolalpha<<endl;
}
//2.ָ������ֵ�Ľ���
//oct 8  hex 16 dec 10 
//ʹ��dec����ԭ״
void test11(){
	cout<<hex<<20<<dec<<endl;
	cout<<oct<<20<<dec<<endl;
	cout<<dec<<20<<endl;
}
//���ӱ�ʾ���Ƶķ���
//showbase 
//noshowbase����ԭ״

void test12(){
	cout<<showbase;
	cout<<hex<<20<<dec<<endl;
	cout<<oct<<20<<dec<<endl;
	cout<<dec<<20<<endl;
	cout<<noshowbase;
}

//3.���Ƹ������ĸ�ʽ
//�������ȡ����ƣ���ʾ�������Ƿ��ӡС����
//precision��Ա/setprecision�������ƾ��ȣ�����ӡ�����ֵ�����������С����
//precision �����صģ�һ���汾����һ��int������������Ϊ��ֵ����һ���汾�����ܲ��������ص�ǰ����ֵ��
//��Щ���Ʒ�������iomanipͷ�ļ���
//��ѧ�⺯��cmath

void test13(){
	cout<<sqrt(2.0)<<endl;
	cout.precision(12);
	cout<<sqrt(2.0)<<endl;
	cout<<setprecision(3);
	cout<<sqrt(2.0)<<endl;
}




int main(){
	test13();
}
