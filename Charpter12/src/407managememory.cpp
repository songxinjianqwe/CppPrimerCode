/*
 * 407managememory.cpp
 *
 *  Created on: 2016��9��9��
 *      Author: songx
 */

#include <iostream>
#include <memory>
#include <new>
#include <string>
#include <vector>

using namespace std;
//ֱ�ӹ����ڴ�
//new�����ڴ棬delete�ͷ��ڴ�
//�Լ�ֱ�ӹ����ڴ������ʹ������ָ����಻ͬ�����ǲ�����������󿽱�����ֵ�����ٲ������κ�Ĭ�϶��塣
//Ĭ������£���̬����Ķ�����Ĭ�ϳ�ʼ���ģ�����ζ���������ͻ�������͵Ķ����ֵ��δ����ģ��������Ͷ�����Ĭ�Ϲ��캯�����г�ʼ����
//����ʹ��ֱ�ӳ�ʼ�����б��ʼ��
//Ҳ���ԶԶ�̬����Ķ������ֵ��ʼ����ֻ����������֮���һ�Կ����ż��ɡ�
//���ڶ������Լ��Ĺ��캯���������ͣ�Ҫ��ֵ��ʼ����û������ģ����ܲ���ʲô��ʽ�����󶼻�ͨ��Ĭ�Ϲ��캯������ʼ����

void test2(){
	int *pi = new int;//Ĭ�ϳ�ʼ��
	int *pi2 = new int();//ֵ��ʼ��
	int * pi3 = new int(1024);//ֱ�ӳ�ʼ��
	vector<int> *pV = new vector<int>{1,2,3,4};//�б��ʼ��
	string * ps = new string;//�մ�
	string * ps2 = new string("happy?!");
	//��̬�����const����
	//new const
	const int * pci = new const int(1024);
	const string * pcs = new const string;
	//new���ص�ָ����һ��ָ��const��ָ��
	delete pi;
	delete pi2;
	delete pi3;
	delete pV;
	delete ps;
	delete ps2;
	delete pci;
	delete pcs;
}
//�ڴ�ľ�
//���new���ܷ�����Ҫ����ڴ�ռ䣬�����׳�һ������Ϊbad_alloc���쳣�����ǿ��Ըı�ʹ��new�ķ�ʽ����֯���׳��쳣
void test3(){
	int * p1 = new int;
	int * p2 = new (nothrow) int;
	//����new��Ϊ��λnew��placement new������λnew���ʽ����������new���ݶ���Ĳ�����
	//���Ǵ��ݸ���һ���ɱ�׼�ⶨ�����Ϊnothrow���������nothrow���ݸ�new�����ǵ���ͼ�Ǹ����������׳��쳣�����������ʽ��new���ܷ��������ڴ棬���᷵��һ����ָ��
	//bad_alloc��nothrow��������ͷ�ļ�new��
	delete p1;
	delete p2;
}

//�ͷŶ�̬�ڴ�
//delete���ʽ����̬�ڴ�黹��ϵͳ������һ��ָ�룬ָ��������Ҫ�ͷŵĶ���
void test4(){
	int * pi = new int;
	delete pi;
	//ע��pi�������Ǿֲ����������������Ѿ����ͷŵı�����ָ��
	//�����ǿ�ָ��
}

//ʹ��new��delete����̬�ڴ�����������⣺
//1.����delete 2.ʹ���Ѿ��ͷŵ����ڴ� 3.ͬһ���ڴ��ͷŶ��
//ֻ��������ָ�룬�Ϳ��Ա���������Щ���⡣

//������deleteһ��ָ���ָ��ֵ�ͱ�Ϊ��Ч�ˡ���Ȼָ���Ѿ���Ч������ָ����Ȼ�������Ѿ��ͷ��˵Ķ�̬�ڴ�ĵ�ַ
//��delete֮��ָ��ͱ���˿���ָ�룬��ָ��һ�������������ݶ��������Ѿ���Ч���ڴ��ָ��
//δ��ʼ��ָ�������ȱ�����ָ��Ҳ�У���һ�ַ������Ա������ָ������⣬������ָ�뼴��Ҫ�뿪��������ʱ�ͷŵ������������ڴ档
//��������ָ��������ڴ汻�ͷŵ�֮�󣬾�û�л������ʹ��ָ���ˡ����������Ҫ����ʹ��ָ�룬������delete֮��nullptr����ָ�롣
//��Ȼ���ڵ������ǿ����ж��ָ��ָ��ͬһ���ڴ棬������ڴ汻�ͷ�֮������ָ������ָ�붼ʧЧ�ˡ�

//12.6
vector<int> * getVector(){
	return new vector<int>;
}
vector<int> * save(vector<int> * pv){
	int i = 0;
	while(cin>>i){
		pv->push_back(i);
	}
	return pv;
}
void display(vector<int> * pv){
	for(auto i:*pv){
		cout<<i<<"\t";
	}
	cout<<endl;
	delete pv;
}
shared_ptr<vector<int>> getVector2(){
	return make_shared<vector<int>>();
}
shared_ptr<vector<int>> save2(shared_ptr<vector<int>> pv){
	int i = 0;
	while(cin>>i){
		pv->push_back(i);
	}
	return pv;
}
void display2(shared_ptr<vector<int>> pv){
	for(auto i:*pv){
		cout<<i<<"\t";
	}
	cout<<endl;
}

int main(void){
	display2(save2(getVector2()));
	return 0;
}

