/*
 * 455DefineClassLikePtr.cpp
 *
 *  Created on: 2016��9��12��
 *      Author: songx
 */

#include <cstddef>
#include <memory>
#include <string>

using namespace std;

//������Ϊ��ָ�����
//�����������ܵ�������ͷŹ�����string��ֻ�е����һ��ָ��string��HasPtr����ʱ�����ſ����ͷ�string��
//��һ����չ������ָ�����Ϊ����÷�������ʹ��shared_ptr���������е���Դ��
//������ֵһ��shared_ptr�´����ֵshared_ptr��ָ���ָ�롣
//shared_ptr���Լ���¼�ж����û���������ָ��Ķ��󡣵�û���û�ָ�����ʱ��shared_ptr�ฺ���ͷ���Դ��

//����Ҳ�����ֶ���ʵ�֣�ʹ�����ü�����ʹ��ָͨ������������ָ��

//���ü����Ĺ�����ʽ��
//1.���캯�������˿������캯������Ҫ����һ�����ü�����Ĭ��Ϊ1
//2.�������캯���������µļ����������ǿ���������������ݳ�Ա���������������������캯����������ļ�����
//3.���������ݼ���������ָ������״̬���û�����һ���������������Ϊ0�������������ͷ�״̬
//4.������ֵ����������Ҳ��������ļ��������ݼ�����������ļ��������������������ļ�����Ϊ0����ô���١�

//���ü�����Ҫ�����еĶ�����Ϊ�˱���״̬һ�£�ʹ�ö�̬�ڴ������档
class HasPtr2{
public:
	HasPtr2(const string & s = string()):ps(new string(s)),i(0),count(new size_t(1)){}
	HasPtr2(const HasPtr2 & orig):ps(new string(*orig.ps)),i(orig.i),count(orig.count){
		--*count;
	}
	HasPtr2& operator=(const HasPtr2 & hp){
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
	~HasPtr2(){
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

//ʹ������ָ���������ֶ�����
class HasPtrWithSP {
public:
	HasPtrWithSP(const string & s = string()):ps(make_shared<string>(s)),i(0){}
	HasPtrWithSP(const HasPtrWithSP & orig):ps(orig.ps),i(orig.i){}
	HasPtrWithSP& operator=(const HasPtrWithSP & hp){
		ps = hp.ps;
		i = hp.i;
		return *this;
	}
	~HasPtrWithSP(){}
private:
	shared_ptr<string> ps;
	int i;
};


