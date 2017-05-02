#include <iostream>
#include <string>
using namespace std;
//��ʽ����ת��

//������캯��ֻ����һ��ʵ�Σ�����ʵ���϶�����ת��Ϊ�����͵���ʽת��������ʱ���ǰ����ֹ��캯������ת�����캯��
//��Ҫʹ����Ķ����ʱ�򣬿����ò�������

class SaleData {
public:
	SaleData(const string & bk, unsigned units, double rev) :bookNo(bk), unitsSold(units), revenue(rev) {}
	//ί��1
	SaleData() :SaleData("", 0, 0) {}
	//ί��2
	explicit SaleData(const string & s) :SaleData(s, 0, 0) {}
	//ί��3����ί����Ĭ�Ϲ��캯����Ĭ�Ϲ��캯����ί�������������Ĺ��캯��
	explicit SaleData(istream & is) :SaleData() {
		read(is, *this);
	}
	istream & read(istream & is, SaleData& item) {
		double price = 0;
		cin >> item.bookNo >> item.unitsSold >> price;
		item.revenue = item.unitsSold* price;
		return is;
	}
	string isbn() const {
		return bookNo;
	}

	 SaleData & combine(const SaleData & sd) {
		unitsSold += sd.unitsSold;
		revenue += sd.unitsSold;
		return *this;//������this����õ��������
	}
private:
	string bookNo;
	unsigned unitsSold;
	double revenue;
};

void test1() {
	string nullBook = "100-123-222";
	SaleData item("100-123-222", 23, 12.99);
//	item.combine(nullBook);
	
//	item.combine("100-123-222");//error
	//ԭ���Ǳ�����ֻ���Զ���ִ��һ������ת��
	//�����Ƚ�����תΪstring��Ȼ��stringתΪSalesData
//	item.combine(cin);//ok

	//������ʽ����ת��
	//ʹ��explicit�ؼ��ֿ��Ա�������ת��
	//explicit�ؼ���ֻ��һ��ʵ�εĹ��캯����Ч����Ҫ���ʵ�εĹ��캯����������ִ����ʽת�����������뽫��Щ���캯��ָ��Ϊexplicit�ġ�
	//ֻ���������������캯��ʱʹ��explicit�ؼ��֣������ⲿ����ʱ��Ӧ�ظ�

	//������ʽ����ת����һ������ǵ�����ִ�п�����ʽ�ĳ�ʼ��ʱ����ʱ����ʹ��ֱ�ӳ�ʼ��������ʹ��explicit���캯��
	SaleData item2(nullBook);
//	SalesData item3 = nullBook;//error


	//��ʹ��explicit���캯����Ҳ����ͨ��ǿ������ת������ʽ
	item.combine(SaleData(nullBook));
	item.combine(static_cast<SaleData>(cin));
}