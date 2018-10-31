#include<iostream>
using namespace std;

void Swap1(int a, int b) {
	int j = a;
	a = b;
	b = j;
}
void Swap2(int &a, int &b) {
	int j = a;
	a = b;
	b = j;
}
int main101() {
	int x(3), y(30);
	Swap1(x, y);
	cout << "x=" << x << ",y=" << y << endl;
	Swap2(x, y);
	cout << "x=" << x << ",y=" << y << endl;
	system("pause");
	return 0;
}