#ifndef SalesData_H
#define SalesData_H
#include <iostream>
#include <string>
using namespace std;


class SalesData {
	//��Ԫ����������ֱ�ӷ������private�ĳ�Ա����
	friend SalesData add(const SalesData&, const SalesData&);
	friend ostream & print(ostream &, const SalesData&);
	friend istream & read(istream&, SalesData&);
private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0;
	double avgPrice() const {
		if (unitsSold) {
			return revenue / unitsSold;
		} else {
			return 0;
		}
	}
public:
	string isbn() const {
		return bookNo;
	}

	SalesData & combine(const SalesData & sd) {
		unitsSold += sd.unitsSold;
		revenue += sd.unitsSold;
		return *this;//������this����õ��������
	}//��Ϊ�ú���������+=����������ķ���ֵ�����Լ��������б�Ҫ�����Լ��������ص�������ֵ������Ҫ������������

	 //���캯��
	SalesData() = default;
	SalesData(const string & book) :bookNo(book) {
		//���û�����ڳ�ʼֵ�Ļ�
		unitsSold = 0;
		revenue = 0;
	}
	SalesData(const string & book, unsigned units, double reven) :bookNo(book), unitsSold(units), revenue(reven) {}
	SalesData(istream & is) {
		read(is, *this);
	}
};
SalesData add(const SalesData&, const SalesData&);
ostream & print(ostream &, const SalesData&);
istream & read(istream&, SalesData&);

SalesData add(const SalesData& item1, const SalesData& item2) {
	SalesData sum = item1;
	sum.combine(item2);
	return sum;
}
ostream & print(ostream & os, const SalesData& item) {
	os << item.isbn() << "\t" << item.unitsSold << "\t" << item.revenue;
	return os;
}
istream & read(istream & is, SalesData& item) {
	double price = 0;
	is >> item.bookNo >> item.unitsSold >> price;
	item.revenue = item.unitsSold* price;
	return is;
}
#endif // !SalesData_H