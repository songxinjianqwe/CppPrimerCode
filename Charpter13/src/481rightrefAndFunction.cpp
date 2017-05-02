/*
 * 481rightrefAndFunction.cpp
 *
 *  Created on: 2016��9��14��
 *      Author: songx
 */
#include <iostream>
#include "StrVec.h"
using namespace std;

//��ֵ���úͳ�Ա����
//���˹��캯��or��������������ƶ�������Ҳ����������ͨ�ĺ����ϡ�
//һ����Ա��������ͬʱ�ṩ�������ƶ��汾��һ���汾����һ��const& const��ֵ���ã�һ���汾����һ��&&��ֵ����

void StrVec::push_back(const string & e) {
	check_n_copy();
	alloc.construct(firstFree++, e);
	//��һ��������ָ�룬ָ��΢������ڴ�ռ䣬ʣ�����ȷ�����ĸ����캯�����������(������õ���string�Ŀ�������)
}
//���صĽ���һ����ֵ���õĺ���
void StrVec::push_back(string &&e) {
	check_n_copy();
	alloc.construct(firstFree++, move(e));
}

//�����ǵ���push_backʱ��ʵ�����;�������Ԫ���ǿ��������ƶ���������
void test50() {
	StrVec vec;
	string s = "HelloWorld";
	vec.push_back(s); //���õ�һ���汾
	vec.push_back("done"); //���õڶ����汾
}

//ͨ��������һ�������ϵ��ó�Ա�����������������������ֵ������ֵ
void test51() {
	string s1 = "Hello", s2 = "World";
	(s1 + s2) = "wow";
	//������s1+s2��һ����ֵ���˴����Ƕ�һ����ֵ�����˸�ֵ��û���﷨���󣬵�����java���ǽ�ֹ�ģ�
}
//�±�׼����Ȼ��������ֵ��ֵ���������ǿ���ϣ�����Լ���������ֹ�����÷�������ϣ��ǿ��������������һ����ֵ
//�붨��const��Ա������ͬ���ڲ����б�����һ�������޶�����
//�����޶���������&��&&���ֱ�ָ��this����ָ��һ����ֵ����ֵ������const�޶����������޶���ֻ�����ڷǾ�̬��Ա�������ұ���ͬʱ�����ں����������Ͷ����С�
//����&�޶��ĺ���������ֻ�ܽ���������ֵ������&&�޶��ĺ�����ֻ��������ֵ
class Foo {
public:
	Foo & operator=(const Foo&) &; //ֻ��������ֵ
};
Foo & Foo::operator =(const Foo & foo) & {
	return *this;
}

Foo & retRef1(Foo& f) {
	return f; //����һ����ֵ���ã�
}
Foo retVal1() {
	return Foo(); //����һ��ֵ��Ҳ����ֵ����
}
void test52() {
	Foo i, j;
	retRef1(j) = i;
//	retVal() = j;//error
	i = retVal1();
}
//һ����������ͬʱ��const�������޶��������޶���������const֮��
class Foo2 {
public:
	Foo someMem() const &;
};

//�����޶���Ҳ�����������ذ汾�����ҿ����ۺ������޶�����const������һ����Ա���������ذ汾
//const & ��ʾ�����ж��󶼿��Ե��ã�����this��һ����ֵ��Ҳ���ǲ����п��ܻ�ı����constҲ�����˲����޸Ķ���
//&&��ʾthis��һ����ֵ���ã�Ҳ������ʱ������û�������û�����˿��������޸Ķ���

class Foo3 {
public:
	Foo3 sorted() &&;
	Foo3 sorted() const &;
private:
	vector<int> data;
};
Foo3 Foo3::sorted() && {
	sort(data.begin(), data.end());
	return *this;
}
Foo3 Foo3::sorted() const & {
	Foo3 t(*this);
	sort(t.data.begin(), t.data.end());
	return t;
}

Foo3 & retRef(Foo3& f) {
	return f; //����һ����ֵ���ã�
}
Foo3 retVal() {
	return Foo3(); //����һ��ֵ��Ҳ����ֵ����
}
void test53() {
	Foo3 i, j;
	retVal().sorted(); //���õ���Foo3::sorted() &&
	retRef(i).sorted(); //���õ���Foo3::sorted() const &
}

//�����Ƕ���const��Ա����ʱ�����Զ��������汾��Ψһ�Ĳ����һ���汾��const��һ���汾û��
//�����޶��ĺ�����ͬ������������������Ͼ�����ͬ���ֺͲ����б�ĳ��ﺯ������ô���Ǳ��붼Ҫ�������޶�����
