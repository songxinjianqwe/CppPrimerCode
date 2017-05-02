/*
 * 593templateParameter.cpp
 *
 *  Created on: 2016��9��28��
 *      Author: songx
 */

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

//ģ�����
//һ��ģ��������Ŀ��÷�Χ����������֮����ģ�������������֮ǰ��
//ģ������������������������������ͬ���֡�
//���ǣ���ģ���ڲ�������ģ�������
//һ��ģ���������һ���ض�ģ������б���ֻ�ܳ���һ��

//ģ������
//�����е�ģ����������ֲ����붨������ͬ
//template<typename T>T calc(const T&,const T&);  ����

//����
//template<typename type>
//type calc(const type &a,const type &b){....}

//***********************************************************************
//ʹ��������ͳ�Ա
//��������������ͳ�Ա��static���ݳ�Ա
//������ͨ�� ����::�ķ�ʽ���з���

//������ͨ������ԣ�������������Ķ��壬��ˣ���֪��ͨ����������������ʵ����������ͻ���static��Ա��
//ʹ��string::size_type����������string�Ķ��壬�Ӷ�֪��size_type��һ������
//��������ģ����ԣ�ʹ��T::mem����������֪��mem��һ�����ͳ�Ա����static���ݳ�Ա
//Ϊ�˴���ģ�壬����������֪�������Ƿ��ʾһ������
//T�����Ͳ�����
//T::size_type * p
//�����Ƕ���һ����Ϊp�ı�����Ҳ�����ǽ�һ����Ϊsize_type��static���ݳ�Ա����һ��p
//��using size_type = vector<T>::size_type;
//�����޷�ȷ�������ݻ������ͣ���Ҫ��һ��typename�Ա�ʾ����һ������
template<typename T> class Test {
	using size_type = typename vector<T>::size_type;
};
//������ϣ��֪ͨ������һ�����ֱ�ʾ����ʱ������ʹ�ùؼ���typename

//******************************************************************************
//Ĭ��ģ��ʵ��
//����Ϊ���������ṩĬ�ϲ���һ��������Ҳ�����ṩĬ��ģ��ʵ��
template<typename T,typename F = less<T>>
int compare(const T & lhs,const T & rhs,F f = F()){
	if(f(lhs,rhs)){
		return -1;
	}else if(f(rhs,lhs)){
		return 1;
	}else{
		return 0;
	}
}
//����Ϊ���ģ��ʵ���ṩ��Ĭ��ʵ�Σ��������Ӧ�ĺ���ʵ��Ҳ�ṩ��Ĭ��ʵ�Ρ�Ĭ��ģ��ʵ��ָ��compare��ʹ��less������
//���û�����compareʱ�������ṩ�Լ��ıȽϲ��������ⲻ�Ǳ����
void test25(){
	bool i = compare(0,42);
	cout<<i<<endl;
//	SalesData items1(cin),items2(cin);
//	bool j = compare(item1,item2,commpareIsbn);
}

//���һ����ģ��Ϊ������ģ��������ṩ��Ĭ��ʵ�Σ�������ϣ��ʹ����ЩĬ��ʵ�Σ��ͱ�����ģ����֮���һ����<>
template<typename T = int>class Numbers{
public:
	Numbers(T v = 0):val(v){}
private:
	T val;
};
void test27(){
	Numbers<long double> n;
	Numbers<> i;
}

