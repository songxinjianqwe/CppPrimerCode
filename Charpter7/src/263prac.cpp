using namespace std;

class NoDefault {
	NoDefault(int i){}
};
class C {
private:
	NoDefault noDefault;
public:
	C(NoDefault nd) :noDefault(nd){}
};
