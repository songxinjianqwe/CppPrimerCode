#include <iostream>
#include <string>
using namespace std;

//ע�⸳ֵ�ͳ�ʼ����ͬ
//���캯������������д����һ������Ĭ�ϳ�ʼ����ֵ�ķ�ʽ��һ���ǳ�ʼ���ķ�ʽ

class SalesData {
public:
	//��ʼ���ķ�ʽ
	SalesData(const string& s,unsigned units,double rev):bookNo(s),unitsSold(units),revenue(rev){}
	//��ֵ�ķ�ʽ��������java)
	SalesData(const string& s, unsigned units, double rev) {
		bookNo = s;
		unitsSold = units;
		revenue = rev;
	}
	
private:
	string bookNo;
	unsigned unitsSold;
	double revenue;
};

//���û���ڹ��캯���ĳ�ʼ���б���ʽ�س�ʼ����Ա����ó�Ա���ڹ��캯����֮ǰִ��Ĭ�ϳ�ʼ��
//���ַ�ʽ������
//��Ϊ��Щ����¹��캯���ĳ�ʼ���ز�����
//�����г�Ա����Ϊconst�������õ����
//ʾ��
class ConstRef {
public:
	ConstRef(int ii);
private:
	int i;
	const int ci;
	int & refI;
};
ConstRef::ConstRef(int ii) {
	i = ii;
//	ci = ii;//error
//	refI = ii;//error
}
//��Ϊû�й��캯����ʼ���б����Գ�Ա������������Ĭ�ϳ�ʼ���������Ź��캯���忪ʼִ�У���ʼ��������ˡ�
//��ʼ��const�������������͵�λ�ƻ������ͨ�����캯����ʼֵ

ConstRef::ConstRef(int ii) :i(ii),ci(ii),refI(ii){}//ok

//��Ա��ʼ����˳��
//��Ա�ĳ�ʼ��˳����������ඨ���еĳ���˳��һ�£����캯����ʼֵ�б��г�ʼֵ��ǰ��λ�ù�ϵ����Ӱ��ʵ�ʵĳ�ʼ��˳��
class X {
	int i;
	int j;
public:
	X(int val) :j(val),i(j){}//error
};
//������캯���Ǵ����
//��Ϊi�ȱ���ʼ������j��δ����ģ����Ի���һ��δ�����ֵ��ʼ��i��

//��������캯����ʼֵ��˳�����Ա������˳�򱣳�һ�£�����������ܵĻ�����������ʹ��ĳЩ��Ա��ʼ��������Ա

//Ĭ��ʵ�κ͹��캯��
//���캯����Ҳ����ʹ��Ĭ��ʵ��
//���һ�����캯���еĲ�������������Ĭ��ʵ�Σ���ô������캯��Ҳ������Ϊ��Ĭ�Ϲ��캯��
//���������Ĺ��캯�����ܶ���һ��������������᲻֪��Ӧ�õ����ĸ�

