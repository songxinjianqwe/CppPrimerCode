#include <iostream>
#include <string>
using namespace std;
void p1() {
	char ch;
	int vowelCount = 0;
	int otherCount = 0;
	while (cin >> ch) {
		switch (ch) {
		case 'a':case 'e':case 'i':case 'o':case 'u'://����д��Ҳ�ǿ��Ե�
			++vowelCount;
			break;
		default:
			++otherCount;
		}
	}
	cout << "Ԫ���ַ�����:" << vowelCount << endl;
	cout << "�����ַ�����:" << otherCount << endl;
}
//switch�ڲ��ı�������
//�����ĳ��һ�����г�ֵ�ı���λ��������֮�⣬����һ���ñ���λ��������֮�ڣ����ǰһ����ת����һ������Ϊ�ǷǷ���Ϊ
void p2() {
	bool t = false;
	switch (t) {
	case true:
		string fileName;//error �������������ĳ�ʼ�����ֱ����ת���ñ������������һ��λ��
		int i = 0;//error ������i�ĳ�ʼ��
		int j;
		break;
	case false:
		j = 32;
		if (fileName.empty()) {
			//
		}
		break;
	}
}
//�����ҪΪһ��case��֧���岢��ʼ��һ����������ôӦ�ðѱ��������ڴ�����У��Ӷ���֤���������case��ǩ���ڱ�����������֮��
void p3() {
	bool t = false;
	switch (t) {
	case true: 
		{
			string fileName;//error �������������ĳ�ʼ�����ֱ����ת���ñ������������һ��λ��
			int i = 0;
			int j;
		}
		break;
	case false:
		
		break;
	}
}
