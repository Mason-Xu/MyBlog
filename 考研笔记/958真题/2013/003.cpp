#include<iostream>
using namespace std;

class A {
	int a;
public:
	A (){ cout <<"������ A �Ĺ��캯��"<<endl; }
};
class B {
		int b;
public:
	B() { cout << "������ B �Ĺ��캯��" << endl; }
};
class C : public A, public B {
	B b;  //
	A a;  //
	int c;
public:
	C() { cout << "������ C �Ĺ��캯��" << endl; }
};

int main() {
	C c;
	system("pause");
	return 0;
}