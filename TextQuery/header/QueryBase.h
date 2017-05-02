/*
 * QueryBase.h
 *
 *  Created on: 2016��9��26��
 *      Author: songx
 */

#ifndef QUERYBASE_H_
#define QUERYBASE_H_

#include "TextQuery.h"

//��ԭ�����ı���ѯ��������Ͻ�����չ
//����һ�����ʣ����ʲ�ѯ
//���� ~(word1) �õ����в�ƥ���ѯ������������
//����  (word1|word2) ������������������һ������
//����  (word1&word2) ����ƥ������ȫ����������

//���ʹ�� word1 & word2 | word3

//����������������ǲ�ѯ��䣬ʹ��Բ��������ʾ��ѯ�����ͺ�ִ�еĴ���
//((fiery & bird)|wind)

//��ṹ��
//QueryBase ���в�ѯ��ĳ������
//WordQuery ��ѯĳ������
//NotQuery ��
//BinaryQuery ������࣬��ʾ�������������Ĳ�ѯ
//AndQuery ��  �̳���BinaryQuery
//OrQuery ��     �̳���BinaryQuery

//��Щ�඼������������eval ����һ��TextQuery���󣬷���һ��QueryResult
//rep ���ػ�����ѯ��string���ʽ

//�������QueryBase��eval��rep����Ϊ���麯��
//��ΪAndQuery��OrQuery������������಻ͬ��������������������Զ���һ��BinaryQuery��λ���ǵĳ������

//����ι�ϵ�����ڽӿ���
//Query q = Query("word1") & Query("word2") | Query("word3")
//�û�����뽫����ֱ��ʹ����Щ�̳е���
//���ǽ�����һ��Query�Ķ���ӿڵ��࣬�û�ֻ�Ӵ�Query��
//��Query�ฺ�����������̳���ϵ
//Query�ཫ����һ��QueryBaseָ�룬��ָ��󶨵�QueryBase������������С�
//Query�Ķ���ӿں�QueryBaseһ�£�eval�������ѯ�����rep�û����ɲ�ѯ��string���ʽ
//Query�ṩһ�����ص�<<�����������ʾ��ѯ

//�û���ͨ��Query����Ĳ�����ӵش���������QueryBase����
//����Query�������������������Լ�һ������string������Query���캯��
//��Щ������̬����һ���µ�QueryBase���������
//& ����һ���󶨵��µ�AndQuery�����ϵ�Query����
//| ����һ���󶨵��µ�OrQuery�����ϵ�Query����
//~ ����һ���󶨵��µ�NotQuery�����ϵ�Query����

class QueryBase{
	friend class Query;
protected:
	virtual ~QueryBase() = default;
private:
	virtual QueryResult eval(TextQuery &) const = 0;
	virtual string rep() const = 0;
};

//���ǲ�ϣ���û���������ֱ��ʹ��QueryBase�����û��public��Ա
//���ж�QueryBase��ʹ�ö���Ҫͨ��Query����
//��ΪQuery�������QueryBase��˽�г�Ա�����Զ���Ϊ����Ԫ

#endif /* QUERYBASE_H_ */
