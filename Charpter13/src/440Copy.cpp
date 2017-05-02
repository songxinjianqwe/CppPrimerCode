/*
 * 440Copy.cpp
 *
 *  Created on: 2016��9��12��
 *      Author: songx
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//һ����ͨ��������������ĳ�Ա���������ƿ������ƶ�����ֵ�����ٲ������������캯����������ֵ��������ƶ����캯�����ƶ���ֵ���������������
//�������ƶ����캯�������˵���ͬ���͵���һ�������ʼ��������ʱ��ʲô
//�������ƶ���ֵ��������彫һ��������ͬ���͵���һ������ʱ��ʲô
//�������������˵������Ͷ�������ʱ��ʲô
//��Щͳ��Ϊ�������Ʋ���

//�ڶ���C++���ʱ�򣬿������Ʋ������Ǳ����

//�������캯��
//���һ�����캯���ĵ�һ�����������������͵����ã����κζ����������Ĭ��ֵ����˹��캯���ǿ������캯��
//�������캯��ͨ����Ӧ����explict
//�ϳɿ������캯��
//��ʹ�����Լ��������������캯������������Ҳ��Ϊ���ǺǺǲ���һ���������캯��
//һ������£��ϳɵĿ������캯���Ὣ������ĳ�Ա��𿽱������ڴ����Ķ�����
//ÿ����Ա�����;���������ο������������͵ĳ�Ա����ʹ���俽�����캯�����������������͵ĳ�Ա��ֱ�ӿ�������Ԫ�صؿ���һ���������͵ĳ�Ա
class SalesData {
public:
	SalesData(const SalesData &);
private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0;
};
SalesData::SalesData(const SalesData & orig) :
		bookNo(orig.bookNo), unitsSold(orig.unitsSold), revenue(orig.revenue) {
}
//������ʼ��
//������ʼ����ʹ��=�������ʵ�ֵģ����Ⱥ��Ҳ�Ķ��󿽱������Ķ����У�������ʽ��ֱ�ӳ�ʼ��
void test1(){
	string s("Hello");//ֱ�ӳ�ʼ��
	string s2 = s;//������ʼ��
}
//ֱ�ӳ�ʼ����Ҫ�������ʹ����ͨ�ĺ���ƥ����ѡ���������ṩ�Ĳ�����ƥ��Ĺ��캯����������ʼ����Ҫ����������Ҳ�������󿽱������ڴ����Ķ�����
//������ʼ��ͨ��ʹ�ÿ������캯������ɡ����һ������һ���ƶ����캯�����򿽱���ʼ����ʱ��ʹ���ƶ����캯�����ǿ������캯������ɡ�
//������ʼ����������=�������ʱ�ᷢ�����������Ҳ�ᷢ����
//��һ��������Ϊʵ�δ��ݸ�һ�����������͵��β�
//��һ����������Ϊ���������͵ĺ�������һ������
//�û������б��ʼ��һ�������е�Ԫ�ػ�һ���ۺ���ĳ�Ա

//�������캯����������ʼ�������������Ͳ�������һ���Խ�����Ϊʲô�������캯���Լ��Ĳ����������������͡��������������������ͣ��������ԶҲ����ɹ�
//Ϊ�˵��ÿ������캯�������Ǳ��뿽������ʵ�Σ���Ϊ�˿���ʵ�Σ���������Ҫ���ÿ������캯����

//������ǵĳ�ʼ��ֵҪ��ͨ��һ��explict�Ĺ��캯������������ת������ôʹ�ÿ�����ʼ������ֱ�ӳ�ʼ���Ͳ����޹ؽ�Ҫ���ˡ�
//vector<int> v1(10);//ok ֱ�ӳ�ʼ��
//vector<int> v2 = 10;//error ������ʼ��

//�������������ƹ�����/�ƶ����캯��,ֱ�Ӵ������󣬽�������ʼ��תΪֱ�ӳ�ʼ��


//13.5
class HasPtr{
	friend void swap(HasPtr &,HasPtr &); 
	friend bool operator<(const HasPtr &,const HasPtr &);
public:
	HasPtr(const string & s = string()):ps(new string(s)),i(0){}
	HasPtr(const HasPtr & orig):ps(new string(*orig.ps)),i(orig.i){}
	HasPtr& operator=(const HasPtr & hp){
		string * newPtr = new string(*hp.ps);
		delete ps;
		ps = newPtr;
		i = hp.i;
		return *this;
	}
	~HasPtr(){
		delete ps;
	}
	
	string  toString()const {
		return *ps;
	}
	void swap(HasPtr & rhs){
		std::swap(ps,rhs.ps);
		std::swap(i,rhs.i);
		cout<<"call swap(HasPtr & rhs)"<<endl;
	}
private:
	string * ps;
	int i;
};

//ע�⿽�����캯���Ϳ�����ֵ�����������һ�仰��
//������ֻ���ڸ�ֵʱ���ŵ��ø�ֵ������������������ʱ��B b3=b1��B b4(b3)���õĺ�����һ���ģ���Ϊ�������캯����
//������󲢳�ʼ��ʱ���ÿ������캯�����Ժ��=��Ϊ������ֵ�����
//����2���������캯��ͨ���������ϵͳ�ṩ����ǳ��������������ֵ�����ͨ����ǳ����  ��Ȼ��һ�㲢û�й涨
//����3��������ֵ�����Ҫע��ԭ�ж���Ķ�̬�ڴ��ͷ����⣬�������캯�����ؿ�����һ��
inline void swap(HasPtr & left,HasPtr & right){
	swap(left.ps,right.ps);
	swap(left.i,right.i);
	cout<<"call swap(HasPtr & left,HasPtr & right)"<<endl;
}

bool operator<(const HasPtr & lhs,const HasPtr & rhs){
	return *lhs.ps < *rhs.ps;
}

void test(){
	vector<HasPtr> hVec = {HasPtr("ccc"),HasPtr("bbb"),HasPtr("aaa")};
	sort(hVec.begin(),hVec.end());
	for(const auto & h:hVec){
		cout<<h.toString()<<endl;
	}
}

