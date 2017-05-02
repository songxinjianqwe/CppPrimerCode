/*
 * 423dynamicarray.cpp
 *
 *  Created on: 2016��9��10��
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

//��̬����
//��ʼ��һ����̬����ķ��������֣�ʹ��new/unique_ptr��allocator������
//����ע�⣬�����Ӧ�ö�Ӧ��ʹ�ñ�׼���������Ƕ�̬���飬�������򵥡������׳����и��õ�����
//new������
void test24(){
	int n = 20;
	int *piArr = new int[n];
	typedef int arrT[20];//arrT ���൱��int[20]
	int *piArr2 = new arrT;
}
//����new����һ������ʱ�����ǵõ�һ������Ԫ�����͵�ָ�룬����һ���������
//��ʼ����̬����
//new����Ķ��󣬲����ǵ������仹�����飬����Ĭ�ϳ�ʼ���ģ����Զ������е�Ԫ�ؽ���ֵ��ʼ�����������ڴ�С֮�����һ������
//������ͨ��һ����ʼ���б�,�б��е�Ԫ�ظ���С��Ԫ����Ŀ��ʣ��Ԫ�ؽ�����ֵ��ʼ�������ڵĻ����׳�bad_array_new_length�쳣
//��Ȼ�����ÿ����Ŷ������е�Ԫ�ؽ���ֵ��ʼ�������ǲ����������и�����ʼ��������Ҳ���Ƕ���û��Ĭ�Ϲ��캯���Ķ���������޷������ġ�
//��̬����һ���������ǺϷ��ģ����ǲ��ܽ�����
void test25(){
	int *piArr = new int[10];
	int *piArr2 = new int[10]();
	cout<<*piArr2<<endl;
	int *piArr3 = new int[10]{1,2,3,4};
	
}
//�ͷŶ�̬���飺ʹ��delete[] p
//�����е�Ԫ�ذ��������٣����һ��Ԫ�����ȱ����٣�Ȼ���ǵ����ڶ���
//����������Ǳ���ģ�������ԣ�����δ�������Ϊ

//ʹ������ָ��unique_ptr������̬����
//Ϊ����һ��unique_ptr����̬���飬���Ǳ����ڶ������ͺ����һ�Կյķ�����
//��һ��unique_ptrָ��һ������ʱ�����ǾͲ���ʹ�õ�ͼ�ͷ��Ա�����������ʹ���±������������Ԫ��
void test26(){
	unique_ptr<int[]> up(new int[10]);
	up.release();//�ͷ��ڴ棬�Զ�����delete[]
	for(size_t i = 0; i != 10;i++){
		up[i] = i;
	}
}

//������
//unique_ptr<T[]> u;
//unique_ptr<T[]> u(p) p������ָ����ָ��Ķ�̬����
//u[i]

//shard_ptr��ֱ��֧�ֹ���̬���飬���ϣ��ʹ����������̬���飬��Ҫ�ṩ�Լ���ɾ����������δ�����±����������֧��ָ�����������

//12.23
void test27(){
	char* arr = new char[255]();
	strcat(arr,"Hello");
	strcat(arr,"World");
	cout<<arr<<endl;
	delete[] arr;
	string * ps1 = new string("Hello");
	string * ps2 = new string("World");
	cout<<*ps1+*ps2<<endl;
}
//12.24
void test28(){
	size_t size = 0;
	cout<<"Please enter the size��"<<endl;
	cin>>size;
	char* pArr = new char[size+1]();
	cin.ignore();
	//cin.ignore(a,ch)�����Ǵ���������cin������ȡ�ַ�����ȡ���ַ������ԣ�ignore��������ʹ�á�
	//ÿ����һ���ַ�������Ҫ�����ͱȽ��ַ����������ֵ�ﵽa���߱��������ַ���ch����cin.ignore()����ִ����ֹ�������������ȴ��� 
	//���cin.ignore()������������Ĭ�ϲ���Ϊcin.ignore(1,EOF)������EOFǰ��1���ַ����
	cout<<"Please enter the string"<<endl;
	cin.get(pArr,size+1);
	//cin.get(�ַ�������,�����ַ���Ŀ)��������һ���ַ���,���Խ��տո� 
	cout<<pArr<<endl;
	delete[] pArr;
}


