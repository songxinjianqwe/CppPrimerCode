#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
//���Ǳ��룬����ʹ�õ����ݼ�������ĺ��ð汾
//��Ϊǰ�ð汾�����ֱ�ӷ��أ������ð汾��Ҫ��ԭʼֵ�洢�����Ա��ڷ������δ�޸ĵ����ݣ��������Ҫ�޸�ǰ�����ݣ��Ǿ���һ���˷�
//��������ʹ��ǰ�ð汾��ϰ��

//���ý����ú͵��������
//���õ�����������ȼ����ڽ����������

//���һ���ӱ���ʽ�ı���ĳ����������ֵ����һ���ӱ���ʽ��Ҫʹ�ø�ֵ�Ļ�������������ֵ˳��ͺܹؼ���

//��Ա��������� p��һ��ָ�룬���pָ��һ����Ķ����ṹ�������ô(*p).member == p->member
//����������������ȼ����ڵ�����������Ա���Ҫ����һ������

//��������� ?:�����ȼ��ǳ��ͣ�����Ҫ�������ţ�����������ᱨ��
void simplify() {
	vector<int> iVec = { 2,2,3,-2,1,2,4 };
	auto begin = iVec.begin();
	while (begin != iVec.end()) {
		cout << *begin++ << endl;
	}
	//*begin++ �͵ȼ��� *(begin++)
	//�Ƚ�begin+1��Ȼ�󷵻�begin�ĳ�ʼֵ�ĸ�����Ϊ��ֵ�����Ȼ�����������������������beginδ����֮ǰ��ֵ
	//Ч�����ȷ���ֵ�����ƶ�
	//begin = iVec.begin();
	//while (begin != iVec.end()) {
	//	*begin = toupper(*begin++);
	//	//������������ģ��������ط����õ���begin��ֵ���ø�ֵ�����δ����ģ�����ȡ���ڱ�����
	//}
	int val = -1;
	cout << (val++ && val) << endl;
	//ע�� ���++�ĸ�ֵ��&&֮ǰ����Ч�ˣ�&&��||�����ڹؽڵ�

	//���������
	int grade = 23;
	cout << (grade < 60 ? "fail" : "pass" )<< endl;
}