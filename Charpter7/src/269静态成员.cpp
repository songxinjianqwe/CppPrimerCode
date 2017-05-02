#include <iostream>
#include <string>
using namespace std;

//��̬��Ա��������̬��Ա�����;�̬��Ա����
//�ؼ���static
class Account {
public:
	void calculate() {
		amount += amount*interestRate;
	}
	static double rate() {
		return interestRate;
	}
	static void rate(double);
private:
	string owner;
	double amount;
	static double interestRate;//���Ϊ��̬��Ա����������
	static double initRate();
};
//��̬��Ա���������κζ������һ�����ǲ�����thisָ�룬��������Ϊconst������Ҳ������static��������ʹ��thisָ��

//******************************************************************************************************************************

//�����ڴ�����Ķ����ʱ���ʼ����̬��Ա����
//����������ڲ���ʼ����̬��Ա����
//����������ⲿ��ʼ��ÿ����̬��Ա����������ֱ�Ӹ�ֵҲ����ͨ����̬��Ա������ֵ
double Account::interestRate = initRate();//���Ϊ��̬��Ա�����Ķ���ͳ�ʼ��


//��̬��Ա��������������ڲ����壬Ҳ����������ⲿ����
//������ⲿ���徲̬��Ա����ʱ�������ظ�static�ؼ��֣�static�ؼ���ֻ���������ڲ������������
void Account::rate(double newRate) {
	interestRate = newRate;
}
double Account::initRate() {
	return 0.08;
}

//******************************************************************************************************************************
//ͨ������£���ľ�̬��Ա������Ӧ�������ڳ�ʼ�������ǿ���Ϊ���ṩconst�������͵����ڳ�ʼֵ������Ҫ��̬��Ա����������ֵ�������͵�constexpr����ʼֵ�����ǳ������ʽ
class Account2{
public:
	/*static double rate() {
		return interestRate;
	}
	static void rate(double);*/
private:
	static constexpr int period = 20;//period�ǳ������ʽ
	static const int period2 = 20;//���Ҳ�ǿ��Ե�
	double dailyTtable[period2];
};
constexpr int Account2::period;
//��ʹһ����̬������Ա���������ڲ�����ʼ���ˣ�ҲӦ��������ⲿ���ж��塣



//******************************************************************************************************************************
//��̬��Ա�����Ĳ�֮ͬ���������ǲ���ȫ���ͣ�����֮�󣬶���֮ǰ��
class Bar {
private:
	static Bar mem1;
	Bar * mem2;
//	Bar mem3;//error ��Ա������������ȫ����
};
//��һ����֮ͬ��������ʹ�þ�̬��Ա������ΪĬ��ʵ��
class Screen {
public:
	Screen & clear(char = background);
private:
	static const char background;
};


//******************************************************************************************************************************
//�����⣬ʹ����������������ʾ�̬��Ա��Ҳ����ʹ�ö�������û�ָ����ʾ�̬��Ա
void test8() {
	double r;
	r = Account::rate();//ͨ��һ����̬��Ա��������һ����̬��Ա����
	Account a;
	Account * pA = &a;
	r = a.rate();
	r = pA->rate();
}
//��Ա������ʹ�����������������ֱ��ʹ�þ�̬��Ա
int main(void) {
	return 0;
}