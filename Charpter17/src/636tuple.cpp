/*
 * 636tuple.cpp
 *
 *  Created on: 2016��10��1��
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
//tuple
//tuple������pair��ģ�壬����tuple���͵ĳ�Ա�����ǲ�ͬ�ģ���Ա����Ҳ�ǲ�ͬ�ġ�
//ÿ��ȷ����tuple���͵ĳ�Ա��Ŀ�ǹ̶��ģ���һ��tuple���͵ĳ�Ա��Ŀ��������һ��tuple���Ͳ�ͬ
//tuple<T1,T2,T3,...Tn> t;
//tuple<T1,T2,T3,...Tn> t(v1,v2,....vn);
//make_tuple(v1,v2,...vn);
//get<i>(t) ��õ�i�����ݳ�Ա������
//tuple_size<tupleType>::value    ��ģ�壬��ʾ�˸���tuple�г�Ա��������value��һ��public static���ݳ�Ա
//tuple_element<i,tupleType>::type ��ģ�壬��ʾ�˸���tuple�е�i��Ԫ�ص�����
//���Խ�tuple����һ�����ٶ���������ݽṹ
//������tupleͷ�ļ���


//ע�⣬ֻ�ܲ���ֱ�ӳ�ʼ���ķ�ʽ�����ܸ�ֵ��ʼ��
//make_tupleҲ�������ڳ�ʼ��

void test1(){
	tuple<size_t,size_t,size_t> threeD = make_tuple(2,3,5);
//	tuple<size_t,size_t,size_t> threeD2 = {2,4,5};//error
	tuple<string,vector<double>,int,list<int>>someVal("constants",{3.14,2.718},42,{0,1,23});
}

//����Ԫ��
void test2(){
	auto item = make_tuple("0-999-78345-X",3,20.00);
	auto book = get<0>(item);
	cout<<book<<endl;
	//����������
	using trans = decltype(item);
	size_t sz = tuple_size<trans>::value;
	cout<<sz<<endl;
	tuple_element<1,trans>::type cnt = get<1>(item);
	cout<<cnt<<endl;
}




