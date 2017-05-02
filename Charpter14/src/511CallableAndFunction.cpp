/*
 * 511�ɵ��ö�����function.cpp
 *
 *  Created on: 2016��9��17��
 *      Author: songx
 */

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

//C++�еĿɵ��ö��󣺺���������ָ�롢lambda��bind�����Ķ��󡢺�������
//��ͬ���͵Ŀɵ��ö�����ܹ���ͬһ�ֵ�����ʽ

int add(int i,int j){
	return i+j;
}
auto mod = [](int i,int j){return i+j;};
class divide{
public://ע��Ҫ��ʽ����Ϊpublic�ģ������޷�����
	int operator()(int i,int j){
		return i/j;
	}
};
//������Щ�ɵ��ö�����Ȼ���Ͳ�ͬ�����ǹ�����ͬһ�ֵ�����ʽ int(int,int)
//����ϣ������Щ�ɵ��ö������һ��map�У��γ�һ������������˿ɵ��ö����ָ��
//ʹ��string��Ϊkey��ʹ�ÿɵ��ö����ָ����Ϊvalue
//����value��������Ϊ����ָ��int(*)(int,int)
void test60(){
	map<string,int(*)(int,int)> functionTable;
	functionTable.insert({"+",add});//ok
	//���ǲ��ܷ��������Ŀɵ��ö���
//	functionTable.insert({"%",mod});//error
//	functionTable.insert({"/",divide()});//error
}


//��׼������һ���µ�����function�����������еĿɵ��ö���
//������functionalͷ�ļ���
//function<T> f��һ�������洢�ɵ��ö���Ŀ�function���ɵ��ö������ʽӦ���뺯������T��ͬ
//T: returnType(args)
//function<T> f(nullptr) ��ʽ�����function
//function<T> f(obj) obj��һ���ɵ��ö��󣬽�obj����һ�ݴ洢��f��
//function<T> f = obj  ͬ��

//if(f) while(f) f��Ϊ���������f�ǿգ�����true
//f(args) ���ÿɵ��ö��󣬲���Ϊargs
//result_type ����ֵ����
//argument_type ��fֻ��һ���β�ʱ��������β�����
//first_argument_type ��һ���β�����
//second_argument_type �ڶ����β�����

//functionҲ��һ��ģ�壬���Ͳ����ǵ�����ʽ������int(int,int)
void test61(){
	function<int(int,int)> f1 = add;
	function<int(int,int)> f2 = mod;
	function<int(int,int)> f3 = divide();
	map<string,function<int(int,int)>> functionTable;
	//��ʱ������ָ�루����������lambda���������󣨰����Զ���ͱ�׼�⣩�����Է������map��
}

//���������������
//����ֱ�ӽ����غ��������ַ���function���͵Ķ�����

//SalesData add(const SalesData & lhs,const SalesData & rhs);
void test62(){
	map<string,function<int(int,int)>> functionTable;
//	functionTable.insert({"+",add});//error
	
	//һ��;���Ǵ洢����ָ�룬����һ������ָ��ָ��׼��Ҫ�洢�ĺ�����Ȼ�󽫺���ָ�����map��
	int(*p)(int,int) = add;
	functionTable.insert({"+",p});//ok
	
	//��һ��;����ʹ��lambda��װһ��
	functionTable.insert({"+",[](int a,int b){return add(a,b);}});
}

void calculator(){
	map<string,function<int(int,int)>> functionTable = {
			{"+",add},
			{"-",minus<int>()},
			{"*",[](int i,int j){return i*j;}},
			{"/",divide()},
			{"%",mod},
	};
	int x = 0,y = 0;
	string op;
	cout<<"Please enter operand1 operator operand2:";
	while(cin>>x>>op>>y){
		if((y == 0 && op == "/")||functionTable.find(op) == functionTable.end()){
			cout<<"Input Error!Please try again."<<endl;
		}else{
			cout<<"The result of "<<x<<" "<<op<<" "<<y<<":  "<<functionTable[op](x,y)<<endl;
		}
		cout<<"Please enter operand1 operator operand2:";
	}
}


 
