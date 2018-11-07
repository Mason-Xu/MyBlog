#include<iostream>
using namespace std;

class A {
public :
	void fun() { cout << "a.fun" << endl; }
};

class B {
public:
	void fun() { cout << "b.fun" << endl; }
	void gun() { cout << "b.gun" << endl; }
};

class C:public A,public B{
private:
	int b;
public:
	void gun() { cout << "c.gun" << endl; }
	void hun() { gun(); }
};

int main202() {
	C cc;
	cc.gun();
	cc.hun();
	system("pause");
	return 0;
}