#include <iostream>
#include <string>
//ʹ��string��������string���ͷ�ļ�
using namespace std;
void testString() {
	string s1;
	string s2(10, 'c');//���ų�ʼ������һ���������ظ��������ڶ���������һ���ַ�
	s1 = "helloworld";
	cout << s1 << endl;
	cout << s2 << endl;
	s2 = s1;//�����൱�ڽ�s1�����ݸ���һ�ݣ�����s2��
	cout << s2 << endl;
	//ʹ�õȺţ����ڿ�����ʼ������ʹ�õȺţ�����ֱ�ӳ�ʼ��

	//��ʼ��֮��ĸ�ֵ�����Բ���=�ķ�ʽ������
	s2 = "haha";
	//Ҳ���Բ��ÿ�����ʼ�������ŵķ�ʽ���൱�ڴ���һ����ʱ������ʼ��Ϊ10��c��Ȼ�󿽱���ʼ����s2�ϡ�
	s2 = string(10, 'c');
}
int main(void) {
	string str;

	cin >> str;
	cout << str << endl;
	//cin��ȡ��ʱ���ӵ�һ���ǿհ׷���֮��ĵ�һ���հ׷���Ȼ���ȡ�����ַ��в�����ǰ��Ŀհ׷���һ���������ַ���ʱ�հ׷�������������
	string s1, s2;
	cin >> s1 >> s2;
	cout << s1 << s2 << endl;

	//��ȡδ֪�������ַ��������ʣ������հ׷��ͽ�����
	while (cin >> str) {
		cout << str << endl;
	}

	//ʹ��getline������ȡһ���У������հ׷�
	//��һ��������һ����������cin���ڶ����������ַ���
	//�������з�ʱ��ȡ�����������ַ����ϣ��������з�
	//���һ��ʼ���ǻ��з�����ô�ַ�������һ���մ�
	while (getline(cin, str)) {
		cout << str << endl;
	}

	//string�໹��empty��size����
	while (getline(cin, str)) {
		if (!str.empty()) {
			cout << str << endl;
		}
	}
	//size��������ֵ��������size_type���ͣ���һ���޷������ͣ�������int���ͻ���
	//����ʹ��auto���ͱ������������ķ���ֵ
	cin >> str;
	auto len = str.size();
	cout << len << endl;


	//string��������== != < > <= >= �������
	//������+ ��+= ������������ַ�����ƴ��
	string s2 = "Hello";
	string s3 = "World";
	s3 += s2;
	cout << s3 << endl;
	//�ַ�����ƴ�Ӳ����������ַ���֮�䣬Ҳ�����������������������ַ����ַ�������
	//Ҫ����+������������һ����string
	s3 += '2';
	s3 += "!";
	cout << s3 << endl;
	//���ǲ����ַ������������
//	string s4 = "hlo" + "wol";//error
	return 0;
}
