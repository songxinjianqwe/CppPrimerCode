#include <iostream>
using namespace std;

//������const_cast
//�����һ���������Ĳ����ͷ���ֵ���ǳ������ã�Ȼ������������һ�������������ͷ���ֵ������ͨ���ã����������������е���ǰһ������
//��������const_cast���Խ�constתΪ��const��Ҳ���Խ���constתΪconst

//�汾1
const string & shorterString2(const string & s1, const string & s2) {
	return s1.size() > s2.size() ? s2 : s1;
}
//���ذ汾
string & shorterString2(string &s1, string &s2) {
	auto & r = shorterString2(const_cast<const string &>(s1), const_cast<const string &>(s2));
	return const_cast<string &>(r);
}
//����ת���ǰ�ȫ��


