#include<iostream>
using namespace std;
int a[8] = { 1,2,3,4,5,6,7 };
void fun(int *pa, int n);
int main101() {
	int m = 8;
	fun(a, m);
	cout << a[7] << endl;
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

void fun(int *pa, int n) {
	for (int j = 0; j < n - 1; j++) {
		*(pa + 7) += *(pa + j);
	}
}