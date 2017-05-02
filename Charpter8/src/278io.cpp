#include <iostream>
#include <string>
using namespace std;

//����istream��ostream֮�⣬��׼�⻹�ṩ������һЩIO���͡��������Ͷ���������ͷ�ļ���
//iostream :istream/ostream/iostream �����ж�д
//fstream  :ifstream/ofstream/fstream ��д�ļ�
//sstream  :istringstream/ostringstream/stringstream ��д�ַ���

//����һ�Կ��ַ��汾�������ֵ�ǰ���һ��w
//wcin wcout wcerr�ֱ��Ӧcin��cout��cerr

//����������IO���Ͷ��ԣ����ǵĲ���������ͬ�ģ���Ϊifstream,istringstream �̳���istream��
//ofstream,ostringstream �̳���ostream

//IO���󲻿��Կ�������ֵ��
//���ܽ��βλ򷵻���������Ϊ������
//ֻ�������÷�ʽ���ݺͷ���������Ϊ����ʹ��ʱ��ı������ݣ����Բ�����const��

//����״̬
//���ж���״̬
//strm::iostate��һ��IO���ͣ���ʾ��IO�����ʱ��״̬
//�ڲ�����ж��������λ��ÿ��λ��ʾ��һ��״̬
//�ж���������Է�����Щ״̬:eof() ����ﵽ�ļ�ĩβ����ôeofbit����λ������true
//fail()���һ��IO����ʧ����(�ɻָ�����)��failbit����λ������true
//bad() ������ѱ���(ϵͳ������)��badbit����λ������true
//good() �����������Ч״̬����ô����true
//clear() ����������״̬λ��λ������״̬����Ϊ��Ч������void
//clear(iostate) ������״̬����Ϊ������״̬
//setstate(iostate) ͬ��
//rdstate() �������ĵ�ǰ״̬������ֵ����Ϊstrm::iostate

//while(cin>>string)���ַ�ʽ���Լ�����Ƿ�����Ч״̬�����ǲ��ܸ������Ǿ��巢����ʲô��
//��Щ���庯�����Է���״̬��Ҳ������������״̬
void processInput(istream & is) {
	string s;
	is >> s;
}
void test() {
	auto oldState = cin.rdstate();
	cin.clear();
	processInput(cin);
	cin.setstate(oldState);
	//����ĳЩ״̬λ
	cin.clear(cin.rdstate()& ~cin.failbit&~cin.badbit);//��failbit��badbit��λ������λ����
}

istream & prac(istream& is) {
	string s;
	while (!is.eof()) {
		is >> s;
		cout << s << endl;
	}
	is.clear();
	return is;
}
//�����������
//ÿ�������������һ����������������������д������
//���»���ˢ�µ�ԭ��
//1.������������(main)
//2.��������
//3.endl��ʽˢ��
//4.ʹ�ò�����unitbuf��������״̬����ջ�����
//cerrĬ��������unitbuf������cerr������ˢ�µ�
//5.һ����������ܹ�������һ����������д����������ʱ�������������ᱻˢ��
//Ĭ��cin��cerr��������cout�����Զ�cin��дcerr���ᵼ��cout�Ļ�������ˢ��

//IO����������endl�Ĳ�������flush��ends
//flushˢ�»�����
//ends�򻺳�������һ�����ַ���Ȼ��ˢ�»�����
void test23() {
	cout << "hi" << flush;
	cout << "hi!" << ends;
}
//unitbuf
//�������ڽ�������ÿ��д����֮�󶼽���һ��flush����
//nounitbuf��������������
void t(){
	cout << unitbuf;
	cout << nounitbuf;
}
//�������������쳣��ֹ����������������ᱻˢ��

//��������������
//tie����
//ÿ������������һ�����������������ͬʱ������һ��ostream
void tt() {
	cin.tie(&cout);//cin�󶨵�cout�ϣ�Ĭ�Ͼ���������
	ostream * oldTie = cin.tie(nullptr);//����󶨣�������֮ǰ�󶨵������
	cin.tie(&cerr);//cin������cerr��
	cin.tie(oldTie);
}

int main(void) {
	prac(cin);
	return 0;
}
