#include <iostream>
#include <string>
using namespace std;
//ί�й��캯��
//һ��ί�й��캯��ʹ������������������캯��ִ�����Լ��ĳ�ʼ������
//ί�й��캯��Ҳ��һ����Ա��ʼֵ�б��һ�������塣��ί�й��캯���ڣ���Ա��ʼֵ�б�ֻ��һ����ڣ���������������������Ա��ʼֵһ�����������������������������
//�����б������б������������һ�����캯��ƥ��
//����():����(ʵ��){}
//������java�е�this();

class SalesData {
public:
	SalesData(const string & bk,unsigned units,double rev):bookNo(bk),unitsSold(units),revenue(rev){}
	//ί��1
	SalesData() :SalesData("", 0, 0){}
	//ί��2
	SalesData(const string & s) :SalesData(s, 0, 0){}
	//ί��3����ί����Ĭ�Ϲ��캯����Ĭ�Ϲ��캯����ί�������������Ĺ��캯��
	SalesData(istream & is) :SalesData() {
		read(is, *this);
	}
	istream & read(istream & is, SalesData& item) {
		double price = 0;
		cin >> item.bookNo >> item.unitsSold >> price;
		item.revenue = item.unitsSold* price;
		return is;
	}
private:
	string bookNo;
	unsigned unitsSold;
	double revenue;
};

//ִ��˳��
//1.��ί�еĹ��캯����ʼֵ�б�
//2.��ί�еĹ��캯���ĺ�����
//3.ί���ߵĹ��캯��������