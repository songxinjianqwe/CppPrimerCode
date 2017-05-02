/*
 * 427allocator.cpp
 *
 *  Created on: 2016��9��10��
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

//allocator ���Խ������ڴ����������룬��ζ�����ǿ��Է������ڴ棬��ֻ��������Ҫʱ������ִ�ж��󴴽�����
//�������n�����󣬵�ʵ����ֻ�õ���һ����󣬺�һ���û�б�Ҫ���г�ʼ������ǰһ����������θ�ֵ��һ����Ĭ�ϳ�ʼ����һ���������Լ����еĸ�ֵ
//allocator�ඨ����ͷ�ļ�memory�У���������ڴ���δ�����
//allocator��һ��ģ�壬��Ҫ������Է���Ķ�������
//������
//allocator<T> a
//a.allocate(n) ����n��������ڴ棬��δ��ʼ��
//a.construct(p,args) p��һ��ָ�룬ָ��һ��ԭʼ�ڴ棬args�ǹ��캯���Ĳ���
//a.destory(p) ��pָ��Ķ���ִ����������
//a.deallocate(p,n) �ͷŴ�p�е�ַ��ʼ���ڴ棬����ڴ汣����n������Ҫ��p������allocate���ص�ָ�룬n�Ǵ���ʱ�Ĵ�С���ڵ����������֮ǰ�������ÿ���������destroy

//ִ��destory����֮�󣬾Ϳ�������ʹ���ⲿ���ڴ����������������ˣ�Ҳ����ͨ��deallocate�黹��ϵͳ
void test30() {
	size_t n = 20; //size_t�ǿ���ֲ���ͣ����Ա����������鳤��
	allocator<int> a;
	auto p = a.allocate(n);
	auto q = p;
	for (size_t i = 0; i != n; i++, q++) {
		a.construct(q, i);
	}
	while (p != q) {
		cout << *--q << "\t";
//		a.destory(q);
	}
}

//���������δ��ʼ���ڴ���㷨
//����ʹ��construct����Ԫ�أ�Ҳ����ͨ��һЩ�㷨�������п���Ԫ�ػ����Ԫ��
//��Щ�㷨������memory��
//uninitialized_copy(begin,end,begin2) begin��end����������������������������֮���Ԫ�ؿ�����begin2ָ����ԭʼ�ڴ���
//uninitialized_copy_n(begin,n,begin2) ��begin��ʼ������n��Ԫ�ص�begin2��ʼ���ڴ���
//uninitialized_fill(begin,end,t)	   ��begin��end��Χ�ڴ������󣬶����ֵΪt�Ŀ���	
//uninitialized_fill_n(begin,n,t)    ��begin��ʼ������n�����󣬶����ֵΪt�Ŀ���
//���Ƿ���һ��ָ�룬ָ�����һ�������Ԫ��֮���λ��

//����ĵ�����Ҳ������ָ�����
void test31() {
	vector<int> iVec = { 2, 3, 4, 5 };
	allocator<int> alloc;
	auto p = alloc.allocate(iVec.size() * 2);
	auto q = uninitialized_copy(iVec.begin(), iVec.end(), p);
	uninitialized_copy_n(q, iVec.size(), 42);

}

//12.26
void test32() {
	size_t n = 10;
	allocator<string> alloc;
	string * psArr = alloc.allocate(n);
	string * psArrEnd = psArr;
	string s;
	while (cin >> s && psArrEnd != psArr + n) {
		alloc.construct(psArrEnd++, s);
	}
	while (psArrEnd != psArr) {
		cout << *--psArrEnd << endl;
		alloc.destroy(psArrEnd);
	}
	alloc.deallocate(psArr, n);
}

