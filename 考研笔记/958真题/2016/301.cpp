#include<iostream>
using namespace std;


int main301() {
	double x;
	int c1=0, c2=0, c3=0;
	do {
		cin >> x;
		if (x>=0&&x < 12) {
			c1++;
		}else if(x >= 12 && x <= 15) {
			c2++;
		}else if (x > 15) {
			c3++;
		}
	} while (x >= 0);
	cout << "优秀:" << c1 << endl;
	cout << "达标:" << c2 << endl;
	cout << "不达标:" << c3 << endl;
	system("pause");
	return 0;
}