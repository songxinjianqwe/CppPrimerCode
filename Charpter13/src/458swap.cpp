/*
 * 458swap.cpp
 *
 *  Created on: 2016��9��13��
 *      Author: songx
 */
#include <iostream>
using namespace std;

//swap
//���˶��忽�����Ƴ�Ա��������Դ���໹����һ����Ϊswap�ĺ�����
//������Щ����Ԫ��˳����㷨һ��ʹ�õ��࣬����swap�Ƿǳ���Ҫ�ġ������㷨����Ҫ��������Ԫ��ʱ�����swap
//��������г���ָ���Ա����ô����ϣ������ʱ����ָ�룬���ǿ���֮���ٽ�����

class HasPtr3{
	friend void swap(HasPtr3 & ,HasPtr3 &);
public:
	HasPtr3(const string & s = string()):ps(new string(s)),i(0),count(new size_t(1)){}
	HasPtr3(const HasPtr3 & orig):ps(new string(*orig.ps)),i(orig.i),count(orig.count){
		--*count;
	}
	HasPtr3& operator=(HasPtr3 );
	HasPtr3& operator=(const HasPtr3 & hp){
		//��Ҫ�����Ը�ֵ�����⣺�ȵ����Ҳ��������ļ��������ٵݼ����
		++*hp.count;
		--*count;
		if(*count == 0){
			if(ps){
				delete ps;
				ps = nullptr;
			}
			delete count;
			count = nullptr;
		}
		ps = hp.ps;
		i = hp.i;
		count = hp.count;
		return *this;
	}
	~HasPtr3(){
		--*count;
		if(*count == 0){
			if(ps){
				delete ps;
				ps = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}
private:
	string * ps;
	int i;
	size_t *count;//������
};
//Ϊ�����Ч�ʣ�swap����һ�㶨��Ϊinline
inline void swap(HasPtr3 & left,HasPtr3 &right){
	swap(left.ps,right.ps);
	swap(left.i,right.i);
}
//ע�⣺��׼��Ҳ������ͨ�õ�swap�������ǲ��ÿ���ֵ�ķ�ʽ�����ģ�Ч�ʲ����Լ�����ĸߡ�
//������������ض���swap�汾����ƥ��̶Ȼ�����std�ж���İ汾����ˣ�������������ض���swap�汾��swap���û���֮ƥ�䡣��������������ض��İ汾�����ʹ��std�еİ汾��


//�ڸ�ֵ�����������ʹ��swap
//��ֵ������

HasPtr3 & HasPtr3::operator =(HasPtr3 rhs){
	swap(*this,rhs);
	return *this;
}
//ע����������Ĳ����ǿ������������ã����Ҳ�������󿽱���rhs
//��������������ԭ�������ָ�����rhs������rhs��ԭ����ָ�����*this�С�
//��ˣ���swap����֮��*this�е�ָ�뽫ָ���·����string---�Ҳ����������string��һ������
//����ֵ���������ʱ��rhs�����٣�HasPtr������������ִ�С�delete��rhs����ָ����ڴ棬���ͷŵ�������������ԭ�����ڴ档
//�Զ��������Ը�ֵ�����������Ȼ�����쳣��ȫ��
//ͨ���ı�����������֮ǰ�����Ҳ��������֤���Ը�ֵ����ȷ
//Ψһ�����׳��쳣���ǿ������캯���е�new���ʽ
//����淢�����쳣����Ҳ�������Ǹı�����������֮ǰ������




