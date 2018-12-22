#include<iostream>
using namespace std;
class A {
	int i;
public :
	virtual void fun() = 0;
	A(int a) { i = a; }
};
class B :public A {
	int j;
public :
	void fun() { cout << "B:fun()\n"; }
	B(int m, int n = 0) :A(m), j(n) {}
};
int main202() {
	A *pa;
	B b(7);
	pa = &b;
	pa->fun();
	system("pause");
	return 0;
}