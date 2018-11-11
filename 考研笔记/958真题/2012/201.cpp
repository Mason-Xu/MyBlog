#include<iostream>
using namespace std;

double f(double a[],double b[],int n) {
	double s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i] * b[i];
	}
	return s;
}
int main201() {
	double c[4] = { 1.1,2.2,3.3,4.4 }, d[4] = { 10,0,100,0 };
	cout << f(c, d, 4) << endl;
	system("pause");

	return 0;
}