#include <iostream>
#include <string>
using namespace std;
//֮ǰѧ����constexpr���������Ĳ����ͷ���ֵ������������ֵ����
//��Ҳ����������ֵ���͵�
//����ֵ���͵�����ܺ���constexpr��Ա�����������ĳ�Ա�����������constexpr����������Ҫ����������ʽconst��

//���ݳ�Ա��������ֵ���͵ľۺ���������ֵ������
//���һ���಻�Ǿۺ��࣬����������Ҫ��Ҳ������ֵ������
//1.���ݳ�Ա������������ֵ����
//2.��������ٺ���һ��constexpr���캯��
//3.���һ�����ݳ�Ա�������ڳ�ʼֵ�����������ͳ�Ա�ĳ�ʼֵ����Ϊһ���������ʽ�����������Ա����ĳ�������ͣ����ʼֵ����ʹ�ó�Ա�Լ���constexpr���캯��
//4.�����ʹ������������Ĭ�϶��壬�ó�Ա����������Ķ���

//���캯��������const�ģ�������ֵ������Ĺ��캯��������constexpr�ĺ���
//constexpr���캯����������Ϊ= default����ɾ����������ʽ
//����֮�⣬constexpr���캯������ȷ��Ϲ��캯����Ҫ��û�з�����䣩���ַ���constexpr������Ҫ��(Ψһ�Ŀ�ִ�������Ƿ������)
//��ˣ�constexpr���캯����һ���ǿյ�

class Debug {
public:
	constexpr Debug(bool b = false) :hardWare(b), io(b), other(b){}
	constexpr Debug(bool hw,bool io,bool oth) : hardWare(hw), io(io), other(oth) {}
	constexpr bool any() {
		return hardWare || io || other;
	}
	void setHardWare(bool b) {
		hardWare = b;
	}
	void setIO(bool b) {
		io = b;
	}
	void setOther(bool b) {
		other = b;
	}
private:
	bool hardWare;
	bool io;
	bool other;
};

void test5() {
	constexpr Debug ioSub(false, true, false);
	if (ioSub.any()) {
		cout << "print approprivate error messages" << endl;
	}
	constexpr Debug prod(false);
	if (prod.any()) {
		cout << "print an error message" << endl;
	}
}

