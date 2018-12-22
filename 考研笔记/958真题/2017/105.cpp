#include<iostream>
using namespace std;

class Base {
private :
	int x;
public :
	Base(int i) { x = i; cout << "Constructor of Base" << endl; }
	~Base() { cout << "Destuctor of Base" << endl; }
	void show() { cout << "x=" << x << endl; }
};
class Derived :public Base {
private :
	Base d;
public :
	Derived(int i) :Base(i), d(i) { cout << "Constructor of Derived" << endl; }
	~Derived() { cout << "Destructor of Derived" << endl; }
};
int main105() {
	{
		Derived obj(5);
		obj.show();
	}
	system("pause");
	return 0;
}