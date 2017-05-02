#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using namespace std;
//10.12
class SalesData{
private:
	string bookNo;
public:
	string  isbn()const {
		return bookNo;
	}
	SalesData(const string & s):bookNo(s){}
};

bool compareIsbn(const SalesData & sd1,const SalesData & sd2){
	return sd1.isbn().size() - sd2.isbn().size();
}

void test13(){
	vector<SalesData> sds = {SalesData("123"),SalesData("1234"),SalesData("12345"),SalesData("1234567")};
	sort(sds.begin(),sds.end(),compareIsbn);
	for(const auto & data:sds){
		cout<<data.isbn()<<"\t";
	}
	cout<<endl;
}
//10.13
bool isLongerThan5(const string &s){
	return s.size() > 5;
}
//�㷨partition����
//����һ����Χ��һ��һԪν��
//��ν�ʷ���true�������е�ǰ�棬��ν�ʷ���false�������еĺ��棬����һ��ָ�����һ��ʹν��Ϊtrue��Ԫ�ص�֮���λ�õĵ�����
void test14(){
	vector<string> sVec = {"21334","123","2312312","123","32","1","123125"};
	auto partiEnd = partition(sVec.begin(),sVec.end(),isLongerThan5);
	auto begin = sVec.begin();
	while(begin != partiEnd){
		cout<<*begin<<"\t";
		begin++;
	}
	cout<<endl;
}

