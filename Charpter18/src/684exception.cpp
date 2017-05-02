/*
 * 684exception.cpp
 *
 *  Created on: 2016��10��1��
 *      Author: songx
 */

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
//�쳣
//ͨ���׳�һ�����ʽ������һ���쳣
//��ִ��һ��throwʱ������throw�������䲻�ٱ�ִ�С��෴������Ŀ���Ȩ��throwת�Ƶ���֮ƥ���catchģ�顣
//��catch������ͬһ�������еľֲ�catch��Ҳ����λ��ֱ�ӻ��ӵ����˷����쳣�ĺ�������һ�������С�
/*

 catch(my_error & obj){
 obj.status = errCodes::severeErr;
 throw;
 }catch(other_error obj){
 obj.status = errCodes::badErr;//ֻ�޸����쳣����ľֲ��������쳣����û�иı�
 throw;
 }
 */
void manip() {
	try {
		//
	} catch (...) {
		//
	}
}
//try��͹��캯��
//���캯���ڽ��뺯����֮ǰ����ִ�г�ʼֵ�б���Ϊ�ڳ�ʼֵ�б��׳��쳣ʱ���캯�����ڵ�try�黹û��Ч������catch����޷�����
//�ڹ��캯����ʼֵ�б��׳����쳣
//����취�ǽ����캯��Я�̺���try�������ʽ��
//����try���ʹ��һ��catch�����ܴ����캯���壬Ҳ�ܴ����캯���ĳ�ʼ�����̡�
template<typename T>
Blob<T>::Blob(initializer_list<T> il)
try :
		data(make_shared < vector < T >> (il)) {
}
catch (bad_alloc & e) {
	handle_out_of_memory(e);
}
//�����캯����ʼֵ��Ψһ�����ǽ����캯��д�ɺ���try����
//*****************************************************************************
//noexcept�쳣˵��
//����ͨ���ṩnoexcept˵��ָ��ĳ�����������׳��쳣����ʽ�ǹؼ���noexcept�����ں����Ĳ����б���棬���Ա�ʶ�ú��������׳��쳣
void recoup(int) noexcept;
//��һ����������noexcept˵��Ҫô�����ڸú����������������Ͷ�������У�Ҫôһ��Ҳ�����֡���˵���ں�����β�÷�������֮ǰ��
//�ڳ�Ա�����У�noexcept˵������Ҫ����const�������޶���֮�󣬶���final��override���麯��=0֮ǰ��

//Υ���쳣˵��
//�������������ڱ���ʱ���noexcept˵�������һ��������˵����noexcept��ͬʱ�ֺ���throw��������˿����׳��쳣����������
//��������˳������ͨ����
void f() noexcept{
	throw exception();
}

//һ��һ��noexcept�����׳����쳣������ͻ����terminate��ȷ�����ز�������ʱ�׳��쳣�ĳ�ŵ��
//�쳣˵����ʵ��
//noexcept˵��������һ����ѡ��ʵ�Ρ���ʵ����Ҫ��תΪbool���͡�
//���ʵ����true�����������׳��쳣�������false����ô���������׳��쳣��
void recoup(int) noexcept(true);
void alloc(int ) noexcept(false);
void g();
//noexcept�����
//noexcept˵������ʵ�γ�����noexcept��������ʹ�á�
//noexcept�������һ��һԪ����������ķ���ֵ��һ��bool���͵���ֵ�������ʽ
//���ڱ�ʾ�����ı��ʽ�Ƿ���׳��쳣��
//��sizeof���ͣ�noexceptҲ����������������ֵ
int i = 2;
noexcept(recoup(i));//����true
noexcept(e);//��e���õ����к��������˲��׳�˵����e��������throw���ʱ���������ʽΪtrue������Ϊfalse

void f() noexcept(noexcept(g()));//f��g���쳣˵��һ��
//�������g��ŵ�˲����׳��쳣����fҲ�����׳��쳣�����gû���쳣˵����������g���쳣˵�������������׳��쳣����fҲ�����׳��쳣
//noexcept�����㺬�壺�����ں��������б����ʱ�����쳣˵������������Ϊnoexcept�쳣˵����boolʵ�γ���ʱ������һ�������

//�쳣˵����ָ�롢�麯���Ϳ�������
//����ָ�뼸��ָ����ָ��ĺ����������һ�µ��쳣˵�����������Ϊĳ��ָ�����˲��׳��쳣�����������ָ��ֻ��ָ���׳��쳣�ĺ�����
//�෴�����������ʽ����ʽ˵����ָ������׳��쳣�����ָ�����ָ���κκ�������ʹ��ŵ�˲��׳��쳣�ĺ���Ҳ����

void test(){
	void (*pf1)(int) noexcept = recoup;
	void (*pf2)(int) = recoup;
	//ok
//	pf1 = alloc;//error
	pf2 = alloc;
}
//���һ���麯����ŵ���������׳��쳣������������������麯��Ҳ��������ͬ���ĳ�ŵ��
//��֮�෴�����������麯�������׳��쳣�����������Ӧ�����ȿ����׳��쳣��Ҳ���Բ������׳��쳣��
class Base{
public:
	virtual double f1(double) noexcept;
	virtual int f2() noexcept(false);
	virtual void f3();
};
class Derived:public Base{
public:
//	double f1(double);//error
	int f2() noexcept(false);//ok
	void f3() noexcept;//ok
};
//���������ϳɿ������Ƴ�Աʱ��ͬʱҲ����һ���쳣��������������г�Ա�ͻ�������в�������ŵ�˲����׳�һ������ϳɵĳ�Ա��noexcept
//����ϳɳ�Ա���õ�����һ�����������׳�һ������ϳɵĳ�Ա��noexcept(false);

//�쳣����
//               exception
//             /           \
//        bad_cast /  \     bad_alloc
//                /    \
//       runtime_error logic_error
//            |             |
//            |             |
//    overflow_error    domain_error
//    underflow_error   invalid_argument
//    range_error       out_of_range
//                      length_error

//exception�����˿������캯����������ֵ�������һ��������������һ����Ϊwhat���Ա��
//what��������һ��const char *����ָ��ָ��һ����null��β���ַ����飬����ȷ�������׳��κ��쳣��
//exception ��bad_alloc��bad_cast������Ĭ�Ϲ��캯����runtime_error�� logic_errorû��Ĭ�Ϲ��캯��
//������һ�����Խ���C����ַ�����string�Ĺ��캯������Щʵ�θ����ṩ���ڴ���ĸ�����Ϣ��
//what���𷵻����ڳ�ʼ���쳣�������Ϣ����Ϊwhat���麯�������Ե����ǲ�����������ʱ����what�����ĵ��ý�ִ�����쳣����̬���Ͷ�Ӧ�İ汾
//Ϊ������дһ���쳣��
class out_of_stock:public runtime_error{
public:
	explicit out_of_stock(const string & s):runtime_error(s){}
};
class isbn_mismatch:public logic_error{
public:
	explicit isbn_mismatch(const string & s):logic_error(s){}
	isbn_mismatch(const string & s,const string & lhs,const string & rhs):
		logic_error(s),left(lhs),right(rhs){}
	const string left,right;
};
class SalesData{
	friend istream & operator>>(istream & is,SalesData & sd);
	friend SalesData operator+(const SalesData & lhs,const SalesData & rhs);
public:
	SalesData() = default;
	string  isbn() const{
		return bookNo;
	}
	SalesData & operator+=(const SalesData & rhs);
private:
	string bookNo;
	unsigned unitsSold;
	double revenue;
};
SalesData & SalesData::operator+=(const SalesData & rhs){
	if(isbn() != rhs.isbn()){
		throw isbn_mismatch("wrong isbns",isbn(),rhs.isbn());
	}
	unitsSold += rhs.unitsSold;
	revenue += rhs.revenue;
	return *this;
}
void test2(){
	SalesData item1,item2,sum;
	while(cin>>item1>>item2){
		try{
			sum = item1 + item2;
		}catch(const isbn_mismatch & e){
			cerr<<e.what()<<e.left<<e.right<<endl;
		}
	}
}






