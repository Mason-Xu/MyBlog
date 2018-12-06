#include<iostream>
using namespace std;

int f(int i) {
	return ++i;
}
int g(int &i) {
	return ++i;
}
int main104() {
	int a, b;
	a = b = 0;
	a += f(g(a));
	b += f(f(b));
	cout << "a=" << a << "b=" << b << endl;
	system("pause");
	return 0;
}