#include <iostream>
using namespace std;
//��������ֻ�������������ֵ���ã������õ���
//������Ԫ��orָ�룬���ǽ�ʵ�ε�ֵ�������βΣ��βκ�ʵ��������û�й�ϵ�ı���
//�����õ�����ָ�β���ʵ�εı��������ββ���Ҳͬʱ��ʵ�ν��в���

//����Ҫ���ʺ����ⲿ�Ķ���ʱ��C++��ʹ������������ʵ�֣�����ָ������

//ʹ�����õ���һ���ص��ǲ���Ҫ���п������������Ƚϴ���ô������Ч�ʺܵ�
//��������޸ı�����ֵ�Ļ������Խ��β�����Ϊ�����������ͣ������������Ա��⿽����Ҳ���Է�ֹͨ�������޸�ֵ

//ʹ�����û���һ���ص㣺������Ϊһ�ַ���ֵ���ͣ�����return�ķ���ֵ�����β�����Ϊ�������ͻ����Խ������ķ���ֵ������β��У���ȻҲ�ı���ʵ�Σ�
//
void reset(int * pi) {
	*pi = 0;//ͨ��ָ���޸�val��ֵ��pi��ֵ��&val��ֵһ�£�������ͬһ������
	pi = 0;//��&valû��Ӱ��
}

//�����õ���
void reset(int &i) {
	i = 0;
}
void swap(int * a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
bool isShort(const string&  s1, const string &  s2) {
	if (s1.size() < s2.size()) {
		return true;
	} else {
		return false;
	}
}
string::size_type findChar(const string & str, char ch, string::size_type &occurs) {
	//����������ַ����и��ַ���һ�γ��ֵ�λ�ã�����ֵ���ͳ��ִ����������occurs��
	auto index = str.size();
	for (decltype(index) i = 0; i != str.size(); i++) {
		if (str[i] == ch) {
			if (index == str.size()) {
				index = i;
			}
			occurs++;
		}
	}
	return index;
}
int main(void) {
	int val = 20;
	reset(&val);
	cout << val << endl;
	int i = 321, j = 123;
	swap(&i, &j);
	cout << i << "\t" << j << endl;

	reset(i);
	reset(j);
	cout << i << "\t" << j << endl;
	string::size_type occurs = 0;
	
	cout << findChar("I am the king of the world!", 't', occurs) << endl;
	cout << "t occurs " << occurs << " times" << endl;
	return 0;
}
