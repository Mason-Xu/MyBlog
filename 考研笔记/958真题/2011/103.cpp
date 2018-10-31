#include<iostream>
using namespace std;

class A {
public:
	A() {}
	virtual void f() { cout << "Destructor A" << endl; }
	~A() { f(); }
};
class  B :public A {
public:
	B() {}
	void f() { cout << "Destructor B" << endl; }
	~B() { f(); }
};

int main103() {
	B b;
	A a = b;
	return 0;
}