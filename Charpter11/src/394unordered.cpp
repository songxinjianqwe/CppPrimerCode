/*
 * 394unordered.cpp
 *
 *  Created on: 2016��9��8��
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//�����������
//����ʹ�ñȽ����������֯Ԫ�أ�����ʹ��һ����ϣ�����͹ؼ������͵�==�������
//�ڹؼ������͵�Ԫ��û�����Ե����ϵ������£����������Ƿǳ����õġ���ĳЩӦ���У�ά��Ԫ������Ĵ��۷ǳ��߰�����ʱ��������Ҳ������
//������������������������ͬ�Ĳ���������ֻ��û��˳��Ҳ���ظ��ؼ��ֵİ汾
//����Ͱ�Ĳ�����
//c.bucket_count() ����ʹ�õ�Ͱ����Ŀ
//c.bucket_size(n) ��n��Ͱ�ж��ٸ�Ԫ��
//c.bucket(key) �ؼ���Ϊkey��Ԫ�����ĸ�Ͱ��

//local_iterator ������������Ͱ��Ԫ�صĵ���������
//c.begin(n),c.end(n) Ͱn����Ԫ�ص�������β�������
//��ϣ����
//c.rehash(n) ����洢��ʹ��bucket_count>=n
//c.reserver(n) ����洢��ʹ��c���Ա���n��Ԫ�ض�����rehash

//���������Թؼ������͵�Ҫ��
//��������ʹ�ùؼ������͵�==��������Ƚ�Ԫ�أ���ʹ��һ��hash<key_type>���͵Ķ���������ÿ��Ԫ�صĹ�ϣֵ
//�������Ϳ���ֱ��ʹ�ù�ϣ�����õ���ϣֵ�����Ƕ����Զ������ͣ����Ǳ���ͨ���Լ���hashģ�� �汾
//һ�ַ�����ͨ�����������==������͹�ϣֵ���㺯��
class SalesData{
private:
	string bookNo;
public:
	string isbn() const{
		return bookNo;
	}
};
//����һ��δ�����Ķ�����﷨������(����)   ����java����new ����(����)
//hash�������������(),���ܶ������Ͳ�����string��hash������ԣ�����һ��string������size_t��ϣֵ
size_t hasher(const SalesData & sd){
	return hash<string>()(sd.isbn());
}

bool equals(const SalesData & sd1,const SalesData & sd2){
	return sd1.isbn() == sd2.isbn();
}

using SalesDataSet = unordered_multiset<SalesData,decltype(hasher)*,decltype(equals)*>;
void test22(){
	//���캯����������������һ����Ͱ�Ĵ�С���ڶ����ǹ�ϣ����ָ�룬��������������жϺ���ָ��
	SalesDataSet bookstore(42,hasher,equals);
	
}
//����Լ�����������==���������ôֻ���һ����ϣ����ָ��Ĳ�������

//��д���ʼ�������
void test23(){
	unordered_map<string,int> wordCount;
	string word;
	while(cin>>word){
		wordCount[word]++;
	}
	for(const auto & w:wordCount){
		cout<<w.first<<"  "<<w.second<<endl;
	}
}

int main(void){
	test23();
	return 0;
}


