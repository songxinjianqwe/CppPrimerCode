/*
 * 415shared_ptrAndException.cpp
 *
 *  Created on: 2016��9��10��
 *      Author: songx
 */

#include <memory>

using namespace std;

//����ָ�����쳣
//����ָ���ܹ���֤��Դ���ͷ�
//���ʹ������ָ�룬��ʹ�����������������ָ����Ҳ��ȷ�����ڴ治����Ҫ��ʱ�����ͷ�
//������ָͨ����ԣ������new��delete֮�䷢���쳣�����쳣û�б�������ô�ڴ����Զ�޷����ͷ��ˡ�

//�������ö�����࣬Ӧ���ṩ����������������ָ�뱻����ʱ�����Զ�������������
//��������û�ж����������������ǿ����Լ��ṩһ��ɾ����

struct destination;
struct connection;

connection connect(destination *);
void disconnect(connection);
void f(destination &d ){
	connection c = connect(&d);
	//use connection
	//������˵���disconnect�����޷��ر�c�ˡ�
}
void endConnection(connection *p){
	disconnect(*p);
}
void g(destination &d){
	connection c = connect(&d);
	shared_ptr<connection> p (&c,endConnection);
	//��������ʱ�����Զ�����endConnection����
}
void h(destination &d){
	connection c = connect(&d);
	shared_ptr<connection> p (&c,[](connection *p){disconnect(*p);});
	//��������ʱ�����Զ�����endConnection����
}

//����ָ���ʹ�ù淶��
//1.��ʹ����ͬ������ָ���ʼ����reset�������ָ��
//2.��delete get�������ص�ָ��
//3.��ʹ��get������ʼ����reset��һ������ָ��
//4.���ʹ��get�������ص�ָ�룬��ô�����һ����Ӧ������ָ�����ٺ󣬸�ָ�����Ч��
//5.���ʹ������ָ�벻��new����Ķ�̬�ڴ棬��ô��Ҫ����һ��ɾ����


