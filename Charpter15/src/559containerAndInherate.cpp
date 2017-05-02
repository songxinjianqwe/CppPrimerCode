/*
 * 559containerAndInherate.cpp
 *
 *  Created on: 2016��9��25��
 *      Author: songx
 */


#include <BulkQuote.h>
#include <Quote.h>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

//������ʹ��������ż̳���ϵ�еĶ���ʱ��ͨ��������ü�Ӵ洢�ķ�ʽ����Ϊ�����в��ܷŲ�ͬ���͵�Ԫ�أ��������ǲ��ܰѾ��м̳й�ϵ
//�Ķ������͵Ķ���ֱ�Ӵ����������
//����������󱻸�ֵ���������ʱ�����е������ಿ�ֱ��е�����������ʹ��ڻ�����ϵ�������޷�����

//ͨ������ѡ���������д������ָ����Ƕ���
//���ǿ��Խ�һ�������������ָ��תΪ���������ָ��

void test40(){
	vector<Quote> qVec;
	qVec.push_back(BulkQuote("�����ȫ",23.99,20,0.88));
	qVec.push_back(Quote("C++Primer",21.99));
	double sum = 0;
	for(auto it:qVec){
		sum += it.netPrice(50);
	}
	cout<<sum<<endl;
}
void test41(){
	vector<shared_ptr<Quote>> qVec;
	qVec.push_back(make_shared<BulkQuote>("�����ȫ",23.99,20,0.88));
	qVec.push_back(make_shared<Quote>("C++Primer",21.99));
	double sum = 0;
	for(auto it:qVec){
		sum += it->netPrice(50);
	}
	cout<<sum<<endl;
}
 

