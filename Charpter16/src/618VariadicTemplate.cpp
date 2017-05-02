/*
 * 618VariadicTemplate.cpp
 *
 *  Created on: 2016��9��30��
 *      Author: songx
 */

#include <iostream>
#include <string>

#include "../header/StrVec.h"

using namespace std;

//һ���ɱ����ģ��ʱһ�����ܿɱ���Ŀ������ģ�庯����ģ���ࡣ
//�ɱ���Ŀ�Ĳ�������Ϊ��������
//ģ���������ʾ0~���ģ�������������������ʾ0~�����������
//��һ��ʡ�Ժű�ʾһ����
//class/typename ...ָ���������Ĳ�����ʾ����������͵��б�
//һ�������������һ��ʡ�Ժű�ʾ��������������͵ķ����Ͳ������б�
//�ں��������б��У����һ��������������һ��ģ�����������ô�˲�����һ������������
template<typename T,typename...Args>
void foo(const T & t, const Args & ... rest){
	
}
//����һ���ɱ����ģ�壬�����������ƶϲ�������֮�⣬�����ƶϲ���������
void test51(){
	int i = 0;
	double d = 23;
	string s = "hw";
	foo(s,42,i,d);
}
//foo��ʵ����Ϊ
//void foo(const char[3]&,const int &,const int &,const double &)

//sizeof...�����
//��������Ҫ֪�������ж��ٸ�Ԫ��ʱ������ʹ��sizeof...�������sizeof...Ҳ����һ���������ʽ�����Ҳ������ʵ����ֵ
template<typename ...Args>
void g(Args... args){
	cout<<sizeof...(Args)<<endl;
	cout<<sizeof...(args)<<endl;
}

//���ʹ��һ��initializer_list������һ���ɱ�����ĺ�������������ͱ�������ͬ��
//�����ǼȲ���Ҫ��Ҫ�����ʵ�ε���ĿҲ��֪�����ǵ�����ʱ���ɱ���������Ǻ����õġ�
//�ɱ��������ͨ���ǵݹ�ġ�
//��һ�������Ǵ�����еĵ�һ��ʵ�Σ�Ȼ����ʣ��ʵ�ε�������
//Ϊ����ֹ�ݹ飬���ǻ���Ҫ����һ���ǿɱ�����ĺ���������һ������һ������

//���ڽ����ݹ�ĺ���
//�˺��������ڿɱ�����汾��print����֮ǰ����
template<typename T>
ostream & print(ostream & os,const T & t){
	return os<<t;
}
template<typename T,typename ... Args>
ostream & print(ostream &os,const T & t,const Args&...rest){
	os<<t<<"\t";
	return print(os,rest...);//�ݹ���ã���ӡ����ʵ��;��restֻʣһ����ʱ������������ôprint����
}
//return(os,rest...);
//������rest�еĵ�һ��ʵ�α��󶨵�t�ϣ�ʣ��ʵ���γ���һ��print���õĲ�������
//��ÿ�������У����еĵ�һ��ʵ�α��Ƴ�����Ϊ�󶨵�t��ʵ�Ρ�

//print(cout,i,s,42)
//�ݹ�ִ�����£�
//                     t     rest...
//print(cout,i,s,42)   i      s,42
//print(cout,s,42)     s      42
//print(cout,42)       //�ǿɱ�����汾��print
//�������һ�ε��õݹ����print(cout,42)������print�汾���ǿ��еġ����Ƿǿɱ����ģ��ȿɱ����ģ���������������˱�����ѡ��ǿɱ�����汾
//������ɱ�����汾��printʱ���ǿɱ�����汾�������������������С�

void test60(){
	print(cout,23,"sdjai",23.23923,'d',2e21);
}

//*******************************************************************************************************

//����չ
//����һ�������������˻�ȡ���С֮�⣬�����ܶ�������Ψһ�����������չ
//����չһ����ʱ�����ǻ�Ҫ�ṩ����ÿ����չԪ�ص�ģʽ��
//��չһ�������ǽ����ֽ�Ϊ���ɵ�Ԫ�أ���ÿ��Ԫ��Ӧ��ģʽ�������չ����б�
//����ͨ����ģʽ�ұ߷�һ��ʡ�Ժ���������չ����

//��һ����չ���� ��չģ���������Ϊprint���ɺ��������б�
//�ڶ�����չ���������ڶ�print�ĵ����С��� ģʽΪprint��������ʵ���б�
//�ڴ�����£�ģʽ�Ǻ���������������rest����ģʽ��չ��һ���ɰ���Ԫ����ɵġ����ŷָ����б�

//C++����������ӵ���չģʽ
template<typename ...Args>
ostream & errorMsg(ostream & os,const Args&...rest){
	return print(os,debugRep(rest)...);
}
//���print������ģʽdebugRep(rest)����ģʽ��ʾ����ϣ���Ժ���������rest�е�ÿ��Ԫ�ض�����debugRep��
//��չ�������һ�����ŷָ���debugRep�ĵ����б�
//�������ֵ���:errorMsg(cerr,fcnName,code.num(),otherData);
//print(cerr,debugRep(fcnNuame),debugRep(code.num()),debugRep(otherData));


//ע�ⲻ��д��debugRep(rest...);
//��ͼ��4��ʵ�ε��б�������debugRep
//��չ�е�ģʽ�������Ӧ���ڰ��е�ÿ��Ԫ��

//*********************************************************************************************

//ת��������
//���ǿ������ʹ�ÿɱ����ģ���forward��������д����������ʵ�β���ش��ݸ���������
//��StrVec�е�emplace_back��ԱΪ��
/*

template <typename ...Args>
void StrVec::emplace_back(Args&&...args){
	check_n_copy();
	alloc.construct(firstFree++,forward<Args>(args)...);
}
*/
//emplace_back����Ӧ���ǿɱ�����ģ���Ϊstring�ж�����캯��������������ͬ��
//��������ϣ��ʹ��string���ƶ����캯������˻���Ҫ���ִ��ݸ�emplace_back��ʵ�ε�����������Ϣ
//����������Ϣ��һ�����׶εĹ��̡����ȣ�Ϊ�˱���ʵ���е�������Ϣ�����뽫emplace_back�ĺ�����������Ϊ��ֵ����
//��Σ���emplace_back����Щʵ�δ��ݸ�constructʱ�����Ǳ���ʹ��forward������ʵ�ε�ԭʼ����

//��ģʽ����������ʽԪ��
//forward<Ti>ti
//����Ti��ʾģ��������е�i��Ԫ�ص����ͣ�ti��ʾ�����������е�i��Ԫ�ء�
void test66(){
	StrVec sVec;
	sVec.emplace_back(10,'c');
	//construct�����е�ģʽ����չ��forward<int>(10),forward<char>(c)
	for(auto it = sVec.begin();it != sVec.end();it++){
		cout<<*it<<"\t";
	}
	cout<<endl;
}








