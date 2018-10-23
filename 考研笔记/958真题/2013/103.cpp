#include<iostream>
using namespace std;

void f(int *s) {
	static int j = 0;		// static 存储类，保持局部变量不变  s
	do {
		s[j] += s[j + 1];
	} while (++j < 2);
}

int main103() {
	int k, a[10] = { 1,2,3,4,5 };
	for (k = 1; k < 3; k++) {
		f(a);
	} 
	for (k = 0; k < 5; k++) cout << a[k];
	system("pause");
	return 0;
}