#include<iostream>
using namespace std;

class  A {
public :
	A() {}
	A(const A &) {
		cout << "A::A(const A &)" << endl;
	}
	A & operator = (const A &) {
		cout << "A::operator=" << endl;
		return *this;
	}
};

int main104() {
	A a;
	A b=a ;
	system("pause");
	return 0;
}