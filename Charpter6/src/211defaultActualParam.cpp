#include <iostream>
#include <string>
using namespace std;
//Ĭ��ʵ��
//��Щ����£��ں����Ķ�ε�������Щ�βζ�������ͬ����һ��ֵ������������ֵ�ֵ����Ĭ��ʵ��
//���ú���Ĭ��ʵ�εĺ���ʱ�����԰�����ʵ�Σ�Ҳ����ʡ�Ը�ʵ��
//�ں�������������ʱ���Ĭ��ֵ
//�����ʹ��Ĭ��ʵ�Σ���ô�ڵ��õ�ʱ��ʡ�Ը�ʵ�μ���
using sz = string::size_type;
string screen(sz height = 231, sz weight = 2313, char background = 'c'){
	
}
void call() {
	string s;
	s = screen();//��������ȫ������Ĭ��ֵ
	s = screen(223);//��һ�������޸ģ�����������ΪĬ��ֵ
	s = screen(212, 32);//��һ���������޸ģ�����������ΪĬ��ֵ
	s = screen(232, 123, '1');//ȫ���޸�
}
//�ɴ˿ɼ�������ʹ��Ĭ��ֵ���β���÷��ں��棬������ʹ��Ĭ��ֵ���β���÷���ǰ��

//���ں�������������Σ��������Ĭ��ֵҲ���Զ�ν���
//����������Ӻ���Ĳ����������ǰ��Ĳ���
//ÿ��������ֻ�ܸ�һ��Ĭ��ֵ
//������Ӧ���ں�������������Ĭ��ʵ�Σ���������������ͷ�ļ��У�һ�μ��ɣ�

//Ĭ��ʵ�ε�ֵ������Ϊ�ֲ�����������Ϊȫ�ֱ������������ͺ�������ֵ
sz weight = 23;
char def = '2';
sz height();
//string screen(sz = height(), sz = weight, char = def);
//��ʽΪ����= ֵ

//6.42


string makePlural(size_t count, const string & word, const string & ending = "s") {
	return count > 1 ? word + ending : word;
}

void foo() {
	cout << makePlural(2, "success") << endl;
	cout << makePlural(1, "success") << endl;
	cout << makePlural(2, "failure") << endl;
	cout << makePlural(1, "failure") << endl;
}



