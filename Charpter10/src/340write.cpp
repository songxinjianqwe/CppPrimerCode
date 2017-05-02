#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>


using namespace std;
//д�����㷨
//��Ҫ����Ա����֤������С���ٲ���������Ҫ���㷨д���Ԫ����Ŀ
//fill�㷨������һ�Ե�������������������Ҫд���ֵ���������Χ��Ԫ�ض���Ϊ������������ֵ
void test6() {
	vector<int> iVec = { 2, 3, 4 };
	fill(iVec.begin(), iVec.end(), 0);
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;
}
//fill_n�㷨
//������������һ����������������ʼ���������ڶ���������Ҫ����Ԫ�ظ�����������������Ҫ�����Ԫ��
//Ҫ�����Ա��֤��������������ô���Ԫ��
void test7() {
	vector<int> iVec = { 2, 3, 3, 5, 5, 6, 6, 7, 8, 9, 9, 0 };
	fill_n(iVec.begin(), iVec.size(), 0);
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;
}
//���������
//������ͨ�������Ĺ��ܣ�������ͨ���˵�������ֵʱ����ֵ����������push_back��һ�����и���ֵ��Ԫ����ӵ�������
//����back_inserter�����Է���һ�������������������ͷ�ļ�iterator
void test8() {
	vector<int> iVec;
	fill_n(back_inserter(iVec), 10, 0);
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;
}
//�����㷨
//������ķ�Χ�ڵ�Ԫ�ؿ�����Ŀ��������
//������������ǰ����������ʾһ����Χ��������������ʾĿ�����е���ʼλ��
//ͬ����Ҫ����Ա��֤Ŀ�����еĳ����㹻�����ЩԪ��
void test9() {
	vector<int> iVec = { 2, 3, 3, 4, 5, 6 };
	list<int> iList;
	copy(iVec.begin(), iVec.end(), back_inserter(iList));
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;
}

//����㷨���ṩ�����汾����Щ�㷨������Ԫ�ص�ֵ�����ǲ��ǽ����Ƿ������������е�ĩβ�����Ǵ���һ�������б�����Щ���
//replace�㷨
//���Խ���4��������ǰ������ʾ��Χ���������Ǿ�ֵ�����ĸ�����ֵ

//replace_copy���Խ���5�����������һ�������������������ĵ����������޸�ԭ�������������ǽ��޸ĺ����ֵ��д�����������
//���������Ҫ���ǲ��������
void test10() {
	vector<int> iVec = { 2, 3, 4, 5, 5, 5, 5, 5 };
	replace(iVec.begin(), iVec.end(), 5, 0);
	for (auto i : iVec) {
		cout << i << "\t";
	}
	cout << endl;

	vector<int> iVec2 = { 2, 3, 4, 5, 5, 5, 5, 5 };
	vector<int> iVec3;
	replace_copy(iVec2.cbegin(), iVec2.cend(), back_inserter(iVec3), 5, 0);
	for (auto i : iVec3) {
		cout << i << "\t";
	}
	cout << endl;
}
//sort�㷨
//���򣬽���������������ʾ��Χ
//��ʹ�ö������ص�<�����
//unique�㷨
//�ƶ�Ԫ�أ��������ڵ��ظ�Ԫ�أ�ʹ�ò��ظ�Ԫ�س��������п�ʼλ�ã����صĵ�����ָ�����һ�����ظ�Ԫ��֮���λ�á���λ��֮���Ԫ����Ȼ���ڣ����ǲ�֪�����ǵ�ֵ

//ȥ���ظ�Ԫ��
//�������ظ�Ԫ�ط���һ��Ȼ�����unique��������ظ�Ԫ�طŵ��������Ȼ�����������ɾ����������ЩԪ��ɾ��
void test11() {
	vector<string> sVec = { "the", "quick", "red", "fox", "jumps", "over",
			"the", "slow", "red", "turtle" };
	sort(sVec.begin(), sVec.end());
	auto endUnique = unique(sVec.begin(), sVec.end());
	sVec.erase(endUnique, sVec.end());
	for (auto s : sVec) {
		cout << s << "\t";
	}
	cout << endl;
}
void deDuplication(vector<string> & sVec) {
	sort(sVec.begin(), sVec.end());
	sVec.erase(unique(sVec.begin(), sVec.end()), sVec.end());
}



