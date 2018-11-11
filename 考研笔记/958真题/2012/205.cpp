#include<iostream>
using namespace std;

class Base {
public:
	Base() {}
	Base(int c) :count(c) {}
	virtual void print() const = 0;
private :
	int count;
};

class Derived : public Base {
public :
	Derived():Base(0){}
	Derived(int c) :Base(c) {}
	void print() const { cout << "Derived" << endl; }
};
int main205() {
	Derived d(10);
	// Base dd(1);			// Base含有纯虚拟函数,不能创建对象
	Base *pb;
	pb = &d;
	pb->print();
	Base &cd = d;
	Derived *ddd = static_cast<Derived*>(pb);			// 强制类型转换
	system("pause");
	return 0;
}