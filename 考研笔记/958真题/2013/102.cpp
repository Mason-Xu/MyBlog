#include<iostream>
using namespace std;

int main2() {
	int i, j, x = 0;
	for (i = 0; i < 2; i++) {
		x++;
		for (j = 0; j < 3; j++) {
			if (j % 2) continue;
			x++;
		}
		x++;
	}
	cout << "x=" << x << endl;

	system("pause");
	return 0;
}