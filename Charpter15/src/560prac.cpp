/*
 * 560prac.cpp
 *
 *  Created on: 2016��9��25��
 *      Author: songx
 */

#include <Basket.h>
#include <BulkQuote.h>
#include <Quote.h>
#include <iostream>
#include <memory>


void test44(){
	Basket bask;
	bask.addItem(make_shared<Quote>("�����ȫ",23));
	bask.totalRecept(cout);
}
//������ڵ��������������Ҫ����Ĳ�����һ������ָ�룬�ܷ�ָ�����أ�ֱ�Ӵ�������ں����ڽ�����ת�ɶ�̬�ڴ��ŵ��أ�
//���ǣ��������ʹ��new Quote(q)���ַ�ʽ������������̬����Ļ������е�Quote��������������󶼻ᱻתΪQuote
//����Ĳ��ֽ����е�
//Ϊ�˽��������⣨�����麯����̬���͵��ص㣩��������Quote����һ���麯�������Դ���һ�����󣬷���һ����̬�����ָ��
//�����ָͨ�������Ϊ������������ָ��

void test45(){
	Basket bask;
	bask.addItem(Quote("�����ȫ",23));
	bask.addItem(BulkQuote("������֮��",24,30,0.88));
	bask.totalRecept(cout);
}
int main(){
	test45();
}

