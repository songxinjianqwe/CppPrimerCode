#include <iostream>
#include <stdexcept>
using namespace std;
//�쳣����
//stdexceptͷ�ļ������˼��ֳ��õ��쳣��
//�������⼸���쳣��ʱ�������ṩһ���ַ�����Ϊ���������ַ������ᱻ����Ϊ���쳣������ڲ��쳣��Ϣ
//�쳣�඼����what������������������᷵���ڲ����쳣��Ϣ(�ַ���)
//5.23 
void except1() {
	int i = 0, j = 0;
	while (cin >> i >> j) {
		cout << i / static_cast<double>(j) << endl;
		cout << static_cast<double>(i) / j << endl;
		//�������ַ�ʽ������
		//��iתΪdouble��Ч����jҲҪתΪdouble
		//��ʹ��ĸΪ0��Ҳ���ɽ�����0�����֣���ô���Ľ���Ͳ���ֱ��ֹͣ���ж������infinity
	}
}
//5.25
void except2() {
	int i = 0, j = 0;
	while (cin >> i >> j) {
		try {
			if (j == 0) {
				throw runtime_error("The denominator can not be zero!");
			}
			cout << "The result:" << i / j << endl;
		} catch (runtime_error err) {
			cout << err.what();
			cout << " Please enter again" << endl;
		}
	}
}
int main(void) {
	except2();
	return 0;
}