#include<iostream>
using namespace std;


int main103() {
	int array_size = 10;
	int *a;
	a = new int[array_size];
	int i;
	for (i = 0; i < array_size; i++) {
		*(a + i) = i;
	}
	for (i = 0; i < array_size; i++) {
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}

// *(a+i) 数组的位置  *a 代表 数组首位地址