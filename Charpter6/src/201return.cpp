#include <iostream>
#include <string>
#include <vector>
using namespace std;
//�������Ϳ������������ͣ�Ҳ���Ǳ������������ֵ�Ŀ���
//�����Է��ؾֲ���������û�ָ��

const string & shorterString(const string& s1, const string & s2) {
	if (s1.size() < s2.size()) {
		return s1;
	} else {
		return s2;
	}
} 
//��������ķ������������ã���ô��������ֵ������Ϊ��ֵ
//����֮�⣬��������ֵͳһΪ��ֵ
char & getChar(string & str, string::size_type index) {
	return str[index];
}
int main(void) {
	string s = "Hello";
	getChar(s, 2) = 'A';
	cout << s << endl;
}
//�б��ʼ������ֵ
//����ֵ�������б����ʽ
//������������ͣ���ô�б���������һ��Ԫ�أ�����������ͣ���ô�������ʼ������ʽ
//���Է���һ���յ��б���ʾ�Է���ֵ����ֵ��ʼ��
vector<string> process() {
	string excepted, actual;
	if (excepted.empty()) {
		return{};
	} else if(excepted == actual ){
		return{ "functionX","okay" };
	} else {
		return{ "functionX",excepted,actual };
	}
}

