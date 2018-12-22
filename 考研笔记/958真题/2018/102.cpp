#include<iostream>
using namespace std;

void f(int x) {
	x = x + 5;
	if (x % 2 == 0) x += 6;
	if (x % 3 == 0) x += 7;
	if (x % 5 == 0) x += 8;
}

int main102() {
	int x = 5;
	f(x);
	cout << x << endl;
	system("pause");
	return 0;
}