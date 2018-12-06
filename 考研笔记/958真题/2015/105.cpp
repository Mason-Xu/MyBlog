#include<iostream>
using namespace std;

class Base {
public :
	Base(int i, int j) { x0 = i, y0 = j; }
	void Move(int x, int y) { x0 += x; y0 += y; }
	void show() { cout << "Base(" << x0 << "," << y0 << ")" << endl; }
private:
	int x0, y0;
};

class Derived:private Base {
private:
	int x, y;
public :
	Derived(int i, int j, int m, int n) :Base(i, j) { x = m; y = n; }
	void show(){ cout << "Next(" << x << "," << y << ")" << endl; }
	void Move1(){ Move(2,3); }
	void show1() { Base::show(); }
};
int main105() {
	Base b(1, 2);
	b.show();
	Derived  d(3, 4, 10, 15);
	d.Move1();
	d.show();
	d.show1();
	system("pause");
	return 0;
}