#include <iostream>
#include <string>
using namespace std;

//����ʹ��class����struct��������
//�����������ڲ������Ա�����ͳ�Ա����
//�������ڷ���Ȩ�޵Ĳ�ͬ
//�����struct����ô�����ڵ�һ������˵����֮ǰ�ĳ�Ա��public��
//�����class����ô��private��
//����˵����������:public��private
//public���ڸ�˵����֮��ĳ�Ա�����������ڶ����Ա����ʣ���������Ľӿ�
//private���ڸ�˵����֮��ĳ�Ա���Ա���ĳ�Ա�������ʣ����ǲ��ܱ�ʹ�ø���Ĵ�����ʣ����������ʵ��ϸ��
//�Է���˵�������ֵĴ�����λ��û�����ƣ����Գ��ֶ�Σ������ظ�����


//ʾ����SalesData��
//��Ա�����У�bookNo string ���;unitsSold unsigned ����; revenue double ������
//�ӳ�Ա�����У�isbn()���ض����isbn��combine һ��SalesData����ӵ���ǰ��SalesData������
//�ǳ�Ա�����У�����������ⲿ������java�ľ�̬��������add ����SalesData����ļӷ�
//read��istream����SalesData������
//print��SalesData���������ostream��

//��Ԫ����
//��Ϊһ�������Ԫ���������Է������ķǹ��г�Ա
//��Ԫ���������ں����������������ĳ������Ϊ������Ԫ��������ô��Ҫ������ڲ�д������Ԫ����
//����������ⲿ����Ҫ�������ĺ�������
//��Ԫ���������������⣩���඼Ӧ�÷���ͷ�ļ��С�

class SalesData {
	//��Ԫ����������ֱ�ӷ������private�ĳ�Ա����
	friend SalesData add(const SalesData&, const SalesData&);
	friend ostream & print(ostream &, const SalesData&);
	friend istream & read(istream&, SalesData&);
private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0 ;
	double avgPrice() const;//ֻ����������
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
	SalesData(istream & is);//���ⲿ����
};
SalesData add(const SalesData&, const SalesData&);
ostream & print(ostream &, const SalesData&);
istream & read(istream&, SalesData&);
//���������ڲ��ĺ�������ʽ��inline����
//��Ա�������Զ��������ڣ�Ҳ���Զ���������

//this:
//��Ա����ͨ��һ����Ϊthis����ʽ���������ʵ��������Ǹ����󡣵����ǵ���һ����Ա����ʱ��������ú����Ķ����ַ��ʼ��this
//�κζ����Ա��ֱ�ӷ��ʶ�������this����ʽ����
//��Ϊthis��Ŀ��������ָ�������������this��һ������ָ�룬���ǲ�����ı�this�б���ĵ�ַ
//ע��isbn�����������һ��const�������const���������Ա�����ǳ�����Ա������������ı�����г�Ա������ֵ��

//���const�������Ǹı�this�����ͣ��ɳ���ָ���޸�Ϊָ�����ĳ���ָ�룬Ҳ����const SalesData * const this
//ΪʲôҪ�޸��أ�
//������ȷ�����Ա������Ŀ���Ƿ��ض����е�һ����Ա������ֵ�������޸ģ�getter��
//����this����ʽ���������������ͨ�����this�����޸���ֵ��ͨ�������ǽ���������������Ϊconst��ָ������ָ�룩
//��this�����Ͳ���ָ������ָ�룬������Ҫ��������ת����ת����λ�þ��ں����Ĳ����б�֮��

//�� const ���εĳ�Ա������ָ const ���ں���������ĺ��棬�������ں���ǰ����߲������ڣ���ֻ�ܶ�ȡ���ݳ�Ա�����ܸı����ݳ�Ա��
//û�� const ���εĳ�Ա�����������ݳ�Ա���ǿɶ���д�ġ�

//ע�⣡��Ա�������������ʹ�����е�������Ա������������Щ��Ա���ֵĴ��򣨱��������ȱ����Ա�������ٱ����Ա������

//�������������ⲿ�����Ա��������ô��Ҫ��ѭ��
//�����жԳ�Ա������������
//�������͡������ͺ���������Ҫ�����ڲ�����������һ��
//�������������������
//ʾ��
inline double SalesData::avgPrice() const {
	if (unitsSold) {
		return revenue / unitsSold;
	} else {
		return 0;
	}
}

//�����Ƕ���ĺ���������ĳ�����������ʱ��Ӧ����ú�������Ϊ����ģ������������
//���õĸ�ֵ����������������󵱳���ֵ���أ����Ϊ�˺�������һ�£�combine�������뷵���������ͣ���ֵ���Խ������������ĸ�ֵ������

//��ķǳ�Ա�������������ж��壬Ҳ���������������������Ķ���������������ͬһ��ͷ�ļ���
//ʵ���ϲ������౾��
SalesData add(const SalesData& item1, const SalesData& item2) {
	SalesData sum = item1;//�����ǽ����г�Ա��������һ�ݣ���java��ͬ
	sum.combine(item2);
	return sum;
}
ostream & print(ostream & os, const SalesData& item) {
	//��������Ϊ��������ΪIO�಻���Ա�����
	//��ʹ��const����Ϊ�����ʱ���ı���������
	os << item.isbn() << "\t" << item.unitsSold << "\t" << item.revenue;
	return os;
}
//һ����˵��ִ���������ĺ���Ӧ�þ������ٶԸ�ʽ�Ŀ��ƣ���������ȷ�����û������������Ƿ��С�
istream & read(istream & is, SalesData& item) {
	double price = 0;
	cin >> item.bookNo >> item.unitsSold >> price;
	item.revenue = item.unitsSold* price;
	return is;
}

void countItems() {
	SalesData item, trans;
	if (read(cin, item)) {
		while (read(cin, trans)) {
			if (item.isbn() == trans.isbn()) {
				item.combine(trans);
			} else {
				print(cout, item) << endl;
				item = trans;
			}
		}
		print(cout, item) << endl;
	} else {
		cerr << "No data!" << endl;
	}
}
//���캯��
//���캯�������ֺ�������ͬ��û�з������ͣ�Ҳ�в����б�ͺ�����
//�����ж�����صĹ��캯��
//���캯�����ܱ�����Ϊconst�ĺ���
//�����Ǵ������һ��const����ʱ��֪�����캯����ɳ�ʼ�����̣�������������const�ġ���Ҳ����˵ÿһ�������ڹ�����ɺ󶼱�Ϊconst�����ˣ��ڹ�������л�����const�ģ�
//�������û����ʽָ�����캯������ô��������ָ��һ���ϳɵ�Ĭ�Ϲ��캯��������ʵ�Σ���Ա������������ڳ�ʼֵ����ô���г�ʼ����û�оͽ���Ĭ�ϳ�ʼ����
//������������Լ�����Ĭ�ϵĹ��캯��
//ԭ��1.�����Ƕ����������Ĺ��캯�������ͬʱ����Ҳ��Ҫ����һ��Ĭ�ϵĹ��캯��������������Ϊ�����Զ����ɣ�
//2.�ϳɵ�Ĭ�Ϲ��캯������ִ�д���Ĳ���������ָ��������ֵ��δ����ģ����ܳ���
//3.����������ΪĳЩ��ϳ�Ĭ�ϵĹ��캯�����������е�һ����Ա����һ����Ķ�����û��Ĭ�Ϲ��캯������ô����Ϊ��ǰ��ָ��Ĭ�Ϲ��캯����

//Ĭ�Ϲ��캯���﷨��
// ����()= default ;
//��ʾ������캯����Ĭ�Ϲ��캯��
//= default ���Գ���������ڲ�����������Ҳ���Գ���������ⲿ����������
//��ͨ�Ĺ��캯���﷨��
//����(����1������2...): ��Ա����1(����1),��Ա����2(����2)..{...}
//��ʾ����Ա������ֵ����Ϊ������������Ϊ���캯����ʼ���б�ð�źͺ���ĸ�ֵ�������ǿ���ʡ�Եģ�
//���������Ϊ�գ���ʾֻ���и�ֵ����������������

//������ⲿ���幹�캯��
//ͬ����Ҫָ���ù��캯�����ĸ����
SalesData::SalesData(istream & is) {
	read(is, *this);
}
//���this����ָ��ǰ�����ָ�룬��������÷��ص�ֵ������Ϊ����
//������캯��Ҳ��ȫ���Զ���������ڲ���������

//���캯���ĵ��ã�ֻ����������ͬʱ���ù��캯��(��java��ͬ)
//Ĭ�Ϲ��캯��������ʽ����
//�������캯��������֮��дһ�����ţ��������м��ϲ�������

//���Թ��캯��
void testInitialFunc() {
	SalesData item1;//����Ĭ�Ϲ��캯��
	print(cout, item1)<<endl;
	SalesData item2("123-000-1121");//���ù��캯��1
	print(cout, item2)<<endl;
	SalesData item3("123-000-1121", 10, 239.9);//���ù��캯��2
	print(cout, item3)<<endl;
	SalesData item4(cin);//���ù��캯��3
	print(cout, item4)<<endl;
}

//�ù��캯����дcountItems
void countItems2() {
	SalesData item(cin);
	if (!item.isbn().empty()) {
		while (cin) {
			SalesData trans(cin);
			if (item.isbn() == trans.isbn()) {
				item.combine(trans);
			} else {
				print(cout, item) << endl;
				item = trans;
			}
		}
		print(cout, item) << endl;
	} else {
		cerr << "No data" << endl;
	}
}

int main(void) {
	testInitialFunc();
	countItems2();
	return 0;
}




