#include<iostream>
using namespace std;

class A {
	int a;
public:
	A (){ cout <<"调用了 A 的构造函数"<<endl; }
};
class B {
		int b;
public:
	B() { cout << "调用了 B 的构造函数" << endl; }
};
class C : public A, public B {
	B b;  //
	A a;  //
	int c;
public:
	C() { cout << "调用了 C 的构造函数" << endl; }
};

int main() {
	C c;
	system("pause");
	return 0;
}