#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
//���������������������string
//�������string������������begin()��end()�����ǿ��Է��ص�����
//beginָ���һ��Ԫ�أ�endָ�����һ��Ԫ�صĺ�һ��Ԫ��
//��������������������ͬ����ͬ
//�������ķ�����������ָ��):*iter ȡֵ ;iter->���Ի򷽷�;++ -- �ƶ�����һ������һ��λ�� ;== != ���������жϺ�ʱ���������ô���С�ڣ���Ϊ����ȫ��������֧�֣�
//����Ϊ��ʱbegin��end���
//ʹ�ý����������*�����޸�ֵ
//cbegin cend�ǲ��ɱ�ĵ�����������ʹ�õ�����ȥ�ı�ֵ��ֻ��
//�������������const����ôbegin��end��cbein��cend����const�ģ��������������const����ôbegin��end����const��cbegin��cend��const��
//ʹ�õ�����ʱ�������Ըı������Ĵ�С������vector����ʹ��push_back������
void test1() {
	//��һ���ַ���������ĸ���д
	string str = "some string";
	if (str.begin() != str.end()) {
		auto it = str.begin();
		*it = toupper(*it);
	}
	cout << str << endl;
}
void test2() {
	//���ַ����ĵ�һ���ո�֮ǰ���ַ�תΪ��д
	string str = "some string";
	for (auto it = str.begin(); it != str.end() && !isspace(*it); it++) {
		*it = toupper(*it);
	}
	cout << str << endl;
}
void test3() {
	//���string��vector�������һ�����ַ���֮ǰ�������ַ���
	vector<string> sVec = { "HW","Try","","2","HEl","45545" };
	for (auto it = sVec.begin(); it != sVec.end() && !it->empty(); it++) {
		cout << *it << endl;
	}
}

