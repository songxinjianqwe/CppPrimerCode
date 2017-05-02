#include <iostream>
#include <fstream>
#include <string>
#include "SalesData.h"
using namespace std;

//�ļ��������

//����ʹ��getline��IO�����>> << ����д����
//����iftream��ofstream��fstream �����²�����
//���캯��������һ���ַ������ַ�����ָ��: ����һ�������򿪸��ļ�
//���صĹ��캯��������һ���ַ�����ģʽ
//open(s) ��һ���ļ�
//close() �ر�һ���ļ�
//is_open() �Ƿ��


//���Գ���
void testFileIO() {
	string file = "D:/test,txt";
	ifstream in(file);
	
}
void testSalesData(string in,string out) {
	ifstream input(in);
	ofstream output(out);
	SalesData total;
	if (read(input, total)) {
		SalesData trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				print(output, total)<<endl;
				total = trans;
			}
		}
		print(output, total)<<endl;
	} else {
		cerr << "No data" << endl;
	}
	input.close();
	output.close();
}
//open�������ܻ����ʧ�ܣ�failbit����λ
//if��out�� ��Ҫ�����ļ��
//��һ��fstream�����뿪��������ʱ����֮�������ļ����Զ��ر�

//�ļ�ģʽ
//in ��ģʽ
//out дģʽ
// app ׷��ģʽ
//ate ���ļ���������λ���ļ���β
//trunc �ض�ģʽ����գ�
//binary ������ģʽ

//ifstream Ĭ��Ϊin��ofstreamĬ��Ϊout
//ÿ�����������ö��ģʽ
//���캯���ĵڶ������ȵȵĲ�����������������ģʽ
//ֻ�е�outģʽ���趨������趨truncģʽ��ofstreamĬ����trunc��Ҳ��������ļ��������Ҫ׷�ӣ���ôӦͬʱ����out��appģʽ
//appģʽ�£���ʹû����ʽָ��outģʽ���ļ�Ҳ�����������ʽ��

//ÿ�δ��ļ�ʱ����Ҫ�����ļ���ʽ����������ʽ�ģ�Ҳ��������ʽ��
void testMode() {
	string file1 = "1.txt";
	string file2 = "2.txt";
	ofstream output(file1);
	ofstream output2(file1, ofstream::out);
	ofstream output3(file1, ofstream::out | ofstream::trunc);
	//���������������out��trunc����ض��ļ�

	ofstream output4(file2, ofstream::app);
	ofstream output5(file2, ofstream::out | ofstream::app);
	//���������������out��app������ض��ļ�

}

int main(void) {
	testSalesData("D:/in.txt", "D:/out.txt");
	return 0;
}
