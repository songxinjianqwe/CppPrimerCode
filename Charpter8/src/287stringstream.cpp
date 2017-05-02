#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//istringstream ���ַ����ж�ȡ����
//ostringstream ���ַ�����д������
//stringstream �ɶ���д
//���췽��(s)��������һ���ַ��������б����˸��ַ����Ŀ���
//str() �������������б�����ַ����Ŀ���
//str(s) ��s���浽����
struct PersonInfo {
	string name;
	vector<string> phones;
};

vector<PersonInfo> readPersonInfo(string fileName) {
	vector<PersonInfo> persons;
	string line, word;
	ifstream ifstrm(fileName);
	while (getline(ifstrm, line)) {
		PersonInfo person;
		istringstream record (line);
		record >> person.name;//���ַ����ж�һ������
		while (record >> word) {
			person.phones.push_back(word);
		}
		persons.push_back(person);
	}
	return persons;
}
bool valid(string phone);
string format(string str);

void writeToMemory(vector<PersonInfo> persons) {
	for (const auto & p : persons) {
		ostringstream formatted, badNums;
		for (const auto & nums : p.phones) {
			if (!valid(nums)) {
				//���������Ч
				badNums << "\t" << nums;//��Ч����浽badNums��
			} else {
				formatted << "\t" << nums;//��Ч����浽formatted��
			}
		}
		if (badNums.str().empty()) {
			cout << p.name <<"\t"<< formatted.str() << endl;//���������¼û����Ч���룬 ��ô������˵���������Ч�������
		} else {
			cerr << "input error:" << p.name << "\t" << "invalid numbers  " << badNums.str() << endl;
		}
	}
}
int main(void) {
	vector<PersonInfo>  persons = readPersonInfo("D:/persons.txt");
	for (const auto & p : persons) {
		cout << p.name << endl;
	}
	return 0;
}
