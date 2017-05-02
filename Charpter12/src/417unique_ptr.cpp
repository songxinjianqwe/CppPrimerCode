/*
 * 417unique_ptr.cpp
 *
 *  Created on: 2016��9��10��
 *      Author: songx
 */

#include <iostream>
#include <memory>

using namespace std;
//unique_ptr
//ӵ������ָ��Ķ���
//ĳ��ʱ��������һ��unique_ptrָ��һ���������󡣵�unique_ptr������ʱ������ָ��Ķ���Ҳ�����١�
//�����Ƕ���һ��unique_ptrʱ����Ҫ����󶨵�һ��new���ص�ָ���ϡ�
//��ʼ��unique_ptr�������ֱ�ӳ�ʼ���ķ�ʽ
//unique_ptr��֧����ͨ�Ŀ�����ֵ����
//������
//unique_ptr<T> u1
//unique_ptr<T,D> u2
//unique_ptr<T,D> u3(callable) ��ʹ��һ���ɵ��ö������ͷ�ָ�룬������ṩ������� �ͱ�ʾʹ��delete���ͷ�
//u = nullptr �ͷ��ڴ棬����u��Ϊ��
//u.release() u������ָ��Ŀ���Ȩ������ָ�룬����u��Ϊ�գ�ע�⣡���ָ��ָ����ڴ���Ҫ����Ա�ֶ��ͷţ�ͨ�����ڳ�ʼ����һ������ָ������һ������ָ�븳ֵ
//u.reset() �ͷ�uָ��Ķ�������ṩ������ָ��q����ô��uָ��q������u��Ϊ�� 
//u.reset(q)
//u.reset(nullptr)

//��Ȼ������������������Ӻ�������һ��unique_ptr����Ϊ������֪��Ҫ���صĶ���Ҫ�����٣��ڴ�����£�������ִ��һ������Ŀ�����
void test12() {
	unique_ptr<double> p(new double);
	unique_ptr<double> p2(p.release()); //p2�ӹ���pָ����ڴ�
	auto p3 = p2.release();
	cout << *p3 << endl;
	delete p3;

	unique_ptr<int> pi(new int);
//	unique_ptr<int> pi2 = pi;//use of deleted function
}
unique_ptr<int> clone(int i) {
	return unique_ptr<int>(new int(i));
}

//��unique_ptr����ɾ����

struct destination;
struct connection;

connection connect(destination *);
void disconnect(connection);
void f(destination &d) {
	connection c = connect(&d);
	//use connection
	//������˵���disconnect�����޷��ر�c�ˡ�
}
void endConnection(connection *p) {
	disconnect(*p);
}

void f(destination &d) {
	connection c = connect(&d);
	unique_ptr<c, decltype(endConnection)*> p(&c, endConnection);

}

