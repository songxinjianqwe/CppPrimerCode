#include <iostream>
#include <string>
using namespace std;
class Person {
	friend istream & read(istream &, Person &);
	friend ostream & print(ostream &, const Person &);
public :
	void display(){

	}
private:
	string name;
	string loc;
public:
	Person() = default;
	Person(const string & n,const string & loc):name(n),loc(loc){}
	Person(istream & is) {
		read(is, *this);
	}
};
istream & read(istream & is , Person & p) {
	cin >> p.name >> p.loc;
	return is;
}
ostream & print(ostream & os , const Person & p) {
	os << p.name << "\t" << p.loc << endl;
	return os;
}



