/*
 * 320string.cpp
 *
 *  Created on: 2016��10��3��
 *      Author: songx
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

//����string
//���캯������һ��string��һ��const char *������
void test20(){
	const char * pc = "HelloWorld";
	char noNull[] = {'H','i'};
	string s1(pc);
	string s2(noNull,2);//s2 = "Hi"
	string s3(noNull);//error
	string s4(pc+5,5);
	string s5(s1,5,5);
	string s6(s1,5);
	string s7(s1,6,20);//ֻ������s1��ĩβ
//	string s8(s1,16);//error�׳��쳣
}

//substr ����һ��string��һ���ֻ���ȫ���Ŀ���
//���Դ��ݸ�stringһ����ѡ�Ŀ�ʼλ�úͼ���ֵ
void test21(){
	string s("Hello World");
	string s2 = s.substr(0,5);
	string s3 = s.substr(6);
	string s4 = s.substr(6,11);
//	string s5 = s.substr(12);//error �׳��쳣
}
//��һ��vector<char>����һ��string
void test22(vector<char> cVec){
	string s(cVec.begin(),cVec.end());
	cout<<s<<endl;
}
//******************************************************************
//�ı�string
//֧�ָ�ֵ�������assign��insert��erase����
//����֮�⣬�������˶����insert��erase����
void test23(){
	string s = "Hello World";
	//string���еĽ����±��insert�汾���±�ָ���˿�ʼλ��
	s.insert(s.size(),5,'!');
	s.erase(s.size()-5,5);
	cout<<s<<endl;
	//string���ṩ�˽���C����ַ������insert��assign
	const char * pc = "Shush....";
	string s2;
	s2.assign(pc,5);//��pc��ʼ��ǰ5���ַ�
	s2.insert(s2.size(),pc+5);//��pc+5ָ����ַ�������ַ�������s2��β��
	cout<<s2<<endl;
}
void test24(){
	string s = "some",s2 = "thing";
	s.insert(0,s2);
	cout<<s<<endl;
	s.insert(0,s2,0,s2.size());//��һ�������ǿ�ʼλ�ã��ڶ��������Ǵ������ַ����������ĸ��Ǵ������ַ����Ŀ�ʼ����λ��
	cout<<s<<endl;
}


//append��replace����
//append��ĩβ��ӣ�replace���滻
//ע���ʾ��Χ��������±꣬����start��len������ǵ�����������being��end
void test25(){
	string s("C++ Primer"),s2 = s;
	s.insert(s.size()," 5th Ed.");
	s2.append(" 5th Ed.");
	cout<<s<<endl;
	cout<<s2<<endl;
	
	s.replace(11,3,"4th");//��һ�������ǿ�ʼλ�ã��ڶ���������ɾ���ַ��������������滻Ϊ���ַ���
	cout<<s<<endl;
}
//��һ���ַ����еľ��Ӵ��滻Ϊ���Ӵ�
void test26(string & s,const string & oldStr,const string & newStr){
	for(string::size_type i = 0; i != s.size(); ){
		if(s.substr(i,oldStr.size()) == oldStr){
			s.replace(i,oldStr.size(),newStr);
			i += newStr.size();
		}else{
			++i;
		}
	}
	cout<<s<<endl;
}

//��һ���ַ�����ǰ׺�ͺ�׺��Ӻ󷵻�
string test27(const string & s,const string & prefix,const string &suffix){
	string newStr(s);
	newStr.insert(0,prefix);
	newStr.append(suffix);
	return newStr;
}
//**************************************************************************88
//string����
//ÿ����������������һ��string::size_typeֵ����ʾƥ�䷢��λ�õ��±ꡣ
//�������ʧ�ܣ��򷵻�һ��string::npos�ľ�̬��Ա������ʼ��ֵΪ-1
void test28(){
	string name = "AnnaBella";
	auto pos1 = name.find("Anna");//pos1 == 0
	string lowercase("annabella");
	pos1 = lowercase.find("Anna");//pos1 == npos
	string numbers("0123456789");
	name = "r2d2";
	auto pos = name.find_first_of(numbers);
	//����name�еĵ�һ�����ֵ�λ��
	auto pos2 = name.find_first_not_of(numbers);
	//����name�еĵ�һ���������ֵ�λ��
}
//ָ��������Χ
void test29(){
	string name("r2d2");
	string numbers("0123456789");
	string::size_type pos = 0;
	while((pos = name.find_first_not_of(numbers,pos)) != string::npos){
		cout<<"found number at index:"<<pos<<" element is "<<name[pos]<<endl;
		++pos;
	}
}
//��������
void test30(){
	//rfind�����������һ��ƥ��
	string river("Mississippi");
	auto firstPos = river.find("is");
	auto lastPos = river.rfind("is");//�ַ����ᵹ���������ص�λ���Ǵ�������λ��
	cout<<"firstPos "<<firstPos<<endl;//1
	cout<<"lastPos "<<lastPos<<endl;//4
}
int main(){
//	vector<char> cVec = {'H','i'};
//	test22(cVec);
//	test23();
//	test24();
//	string s = "PlusPlusPlusHahhahahahahahha....";
//	string s1 = "Plus",s2 = "Sub";
//	test26(s,s1,s2);
//	string s = "NewSong";
//	string s1 = "Mr.";
//	string s2 = "III";
//	cout<<test27(s,s1,s2)<<endl;
	test30();
}
