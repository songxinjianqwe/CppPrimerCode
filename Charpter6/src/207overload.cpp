#include <iostream>
#include <string>
using namespace std;
//��������
//Ҫ���βε����ͻ������ͬ
//���غ�const�β�
//���β�Ϊ����const������const�������߳���ָ�룩���������const���βεĺ�����������
//���β�Ϊ�ײ�const������ָ������ָ��������ã����������const���βεĺ�����������

string lookup(int i);
string lookup(const int i);//error ��������

string lookup(int * p);
string lookup(int * const p);//error ��������

string lookup(int * p);
string lookup(const int * p);//ok

string lookup(int &r);
string lookup(const int & r);//ok

//ʵ��Ϊ����ʱ���βο����ǳ�����Ҳ�����Ƿǳ���
//�����Ǵ���һ���ǳ�������ָ��ǳ��������ָ��ʱ��������������ѡ�÷ǳ����汾�ĺ���
