#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//istringstream 从字符串中读取数据
//ostringstream 向字符串中写入数据
//stringstream 可读可写
//构造方法(s)，参数是一个字符串，流中保存了该字符串的拷贝
//str() 方法，返回流中保存的字符串的拷贝
//str(s) 将s保存到流中
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
		record >> person.name;//从字符串中读一个单词
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
				//如果号码无效
				badNums << "\t" << nums;//无效号码存到badNums中
			} else {
				formatted << "\t" << nums;//有效号码存到formatted中
			}
		}
		if (badNums.str().empty()) {
			cout << p.name <<"\t"<< formatted.str() << endl;//如果这条记录没有无效号码， 那么将这个人的姓名和有效号码输出
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
