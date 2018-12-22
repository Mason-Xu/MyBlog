#include<iostream>
using namespace std;
void print(int, char, int);
int main102() {
	print(3, '*', 1);
	print(2, '*', 3);
	print(1, '*', 5);
	print(2, '#', 3);
	print(2, '#', 3);
	system("pause");
	return 0;
}

void print(int begin, char pzf, int n) {
	char a[50];
	for (int i = 0; i < begin; i++) a[i] = ' ';
	for (int i = 0; i < n; i++) a[begin + i] = pzf;
	cout << a << endl;
}