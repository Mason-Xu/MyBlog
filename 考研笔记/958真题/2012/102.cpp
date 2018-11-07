#include<iostream>
using namespace std;

class A {
public :
	A(int i, int j) {
		a = i, b = j;
	}
	void Move(int x, int y) {
		a += x;
		b += y;
	}
	void Show() {
		cout << "(" << a << "," << b << ")" << endl;
	}
private:
	int a, b;
};

class B :public A {
public :
	B(int i, int j, int k, int l) :A(i, j), x(k), y(l){
		
	}
	void Show() { cout << x << "," << y << endl; }
	void F1() { Move(3, 5); A::Show(); }
private:
	int x, y;
};

int main102() {
	A a(1, 2);
	a.Show();
	B b(3, 4, 5, 6);
	b.A::Show();
	b.B::Show();
	b.F1();
	system("pause");
	return 0;
}