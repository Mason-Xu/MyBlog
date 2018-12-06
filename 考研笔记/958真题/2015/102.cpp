#include<iostream>
using namespace std;

void f2(int &x, int &y) {
	int z = x; x = y; y = z;
}

void f3(int *x,int *y) {
	int z = *x; *x = *y; *y = z;
}
int main102() {
	int x = 10, y = 26;
	cout << "x,y=" << x << "," << y << endl;
	f2(x, y);
	cout << "x,y=" << x << "," << y << endl;
	f3(&x, &y);
	cout << "x,y=" << x << "," << y << endl;
	x++, y--;
	f2(x, y);
	cout << "x,y=" << x << "," << y << endl;
	system("pause");
	return 0;
}