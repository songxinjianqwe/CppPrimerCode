#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(void) {
	//ʹ��rangeForѭ����cctype�������һ���ַ����б����ŵ���Ŀ

	string str = "!!!HelloWorld!!!";
	decltype(str.size()) sizeCount = 0;
	for (auto ch : str) {
		if (ispunct(ch)) {
			sizeCount++;
		}
	}
	cout << sizeCount << " punctuation characters in " << str << endl;

	//ʹ��rangeFor���������޸��ַ����е��ַ�
	//ȫ��תΪ��д
	//���ÿ����޸�ֵ
	string s2 = "HelloWorld";
	for (auto & ch : s2) {
		ch = toupper(ch);
	}
	cout << s2 << endl;


	//ע��rangeForѭ���������ÿһ���ַ�����������һ�����ַ�����ô����ʹ���±�������
	//ʹ���±�ķ�ʽҲ�����޸��ַ����е��ַ�
	string s3 = "hahahaha";
	if (!s3.empty()) {
		cout << s3[0] << endl;
		s3[0] = toupper(s3[0]);
		cout << s3 << endl;
	}
	
	
	//ʹ����ͨforѭ�����±�ķ�ʽ�������ַ���
	//���ַ�����һ���հ��ַ�֮ǰ�Ĳ���תΪ��д
	string s4 = "hello World";
	for (decltype(s4.size()) index = 0; index < s4.size() && !ispunct(s4[index]); index++){
		s4[index] = toupper(s4[index]);
	}
	cout << s4 << endl;

	//�������ʮ������תΪʮ�����Ʋ����
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15 separated by spaces .Hit Enter when finished." << endl;
	string result;
	string::size_type n;
	while (cin >> n) {
		if (n < hexdigits.size()) {
			result += hexdigits[n];
		}
	}
	cout << result << endl;
	return 0;
}
