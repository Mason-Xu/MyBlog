#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main101() {
	int a[4] = { 25,-2,13,7 };
	int i, y;
	for (int i = 0; i < 4; i++) {
		if (a[i] <= 0) { y = sqrt(a[0]) + a[1]; }
		else if (a[i] > 0 && a[i] <= 10) { y = ++a[2] * 2 - 1; }
		else if (a[i] > 10 && a[i] <= 20) { y = a[3] < a[2] ? a[3] : a[2]; }
		else { y = a[0] % 10 + a[0] / 10 + 1; }
		cout << setw(5) << a[i] << setw(5) << y << endl;
	}
	cout << a[2] * 2 <<endl;
	cout << ++a[2] * 2 <<endl;
	system("pause");
	return 0;
}