/*
 * 412sharedPtr.cpp
 *
 *  Created on: 2016��9��10��
 *      Author: songx
 */

#include <iostream>
#include <memory>

using namespace std;

//shared_ptr�������÷�
//shared_ptr<T> p(q) q��һ������ָ�룬ָ��new������ڴ棬��q����ʼ��p
//shared_ptr<T> p(u) u��unique_ptr��p��u����ӹ��˶��������Ȩ��u��Ϊ��
//shared_ptr<T> p(q,callable) q��һ������ָ�룬δ����ָ��̬�ڴ棬Ҳ����ָ��ĳ����Դ��p��ʹ��callable�ɵ��ö���������delete
//shared_ptr<T> p(p2,callable) p2Ҳ��һ��ֻ��ָ�룬p����p2�Ŀ�����������p�����ÿɵ��ö���������delete
//p.reset() ���p��Ψһָ��������shared_ptr����ôreset���ͷŴ˶��󣬲���p��Ϊ��
//p.reset(q) q������ָ�룬p���ͷŶ���֮�󣬻�ָ��q
//p.reset(q,callable) ��������˿�ѡ����callable����ʹ�ÿɵ��ö���������delete

//ע�⣬����������ָ��ֱ��ָ������ָ�� shared_ptr<int> sp = new int;//error
//shared_ptr<int> p(new int);//ok

//ע�⣡���ɻ�����ָͨ�������ָ��

void process(shared_ptr<int> sp){
	cout<<"in process function:"<<sp.use_count()<<endl;
}
void test5(){
	shared_ptr<int> sp = make_shared<int>(1024);
	process(sp);//sp�ڴ���֮ǰ���ü���Ϊ1������֮�������Ǵ�ֵ���ã�ָ�뱻�������������ü���Ϊ2
	int x = *sp;//�����������󣬺����ڲ��ľֲ�����ָ�뱻���٣����ü�����Ϊ1���Կ��Խ�����
	cout<<x<<endl;
}
void test6(){
	int * p = new int(1024);
	process(shared_ptr<int>(p));//�ڽ��뺯��֮������ָ������ü���Ϊ1
	int x = *p;//��������������ָ������ü���Ϊ0���ڴ汻�ͷţ�p�ǿ���ָ��
	cout<<x<<endl;//�Կ���ָ������û����
}

//����ʹ��get��ʼ����һ������ָ���Ϊ����ָ�븳ֵ
void test7(){
	shared_ptr<int> sp(new int(42));
	int * q = sp.get();//get�᷵��һ����ָͨ�룬ֻ��ʹ�ã�����delete
	{
		shared_ptr<int> r(q);
	}
	//��������˳�ʱ���������ָ����ͷŵ�q��ָ����ڴ棬�Ӷ�ʹ��spָ����ڴ�Ҳ���ͷţ���˲������ٽ�����sp
	int s = *sp;
	cout<<s<<endl;
}

//reset������������ü�����������unique����һ��ʹ�á�����ж��shard_ptr����ͬһ��������ôһ������ָ����Ҫ�޸�ֵ֮ǰ��Ҫ������һ�ݿ���������Ӱ������ָ��
void test8(){
	shared_ptr<int> p = make_shared<int>(1024);
	shared_ptr<int> q = p;
	if(!p.unique()){
		p.reset(new int(*p));
	}
	*p += 1024;
	cout<<*p<<"\t"<<*q<<endl;
}

void test9(){
	shared_ptr<int> p(new int(42));//�ں����е�����ָ����p�Ŀ�������ָͬ��ͬһ������
	process(shared_ptr<int>(p));
	cout<<p.use_count()<<endl;
	cout<<*p<<endl;//ok
}

void test10(){
	shared_ptr<int> p(new int(42));//�ں����е�����ָ����p�Ŀ�������ָͬ��ͬһ������
	process(shared_ptr<int>(p.get()));
	cout<<p.use_count()<<endl;//pʧЧ��p��ָ����ǿ� �ڴ��Ѿ����ͷ���
	cout<<*p<<endl;
}



