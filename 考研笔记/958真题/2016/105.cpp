#include<iostream>
using namespace std;

class Base {
private:
	int b;
public :
	Base() {}
	Base(int i) { b = i; }
	virtual void vfun() {
		cout << "Base::vfun() called.\n";
	}
};
class Dervived :public Base {
private:
	int d;
	void vfun() {
		cout << "Dervived::vfun() called.\n";
	}
public :
	Dervived() {}
	Dervived(int i, int j) :Base(i) { d = j; }
};
void fun(Base *obj) {
	obj->vfun();
}
int main105() {
	Base *pb = new Base;
	fun(pb);
	Dervived *pd = new Dervived;
	fun(pd);
	system("pause");
	return 0;
}

//Base::vfun() called.
//Dervived::vfun() called.

