#include<iostream>
using namespace std;

void fun(char a[]) {
	for (int i = 1; i < 5; i++) {	// ÅÅÐò4´Î
		for (int j = 1; j <= 4; j++) {	// Ã°ÅÝÅÅÐò
			if (a[j] < a[j + 1]) {
				char temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main301() {
	char a[8] = { 'e','b','c','a','d','g','f','\0'};
	/*for (int i = 0; i < 6; i++) {
		cout << a[i] << endl;
	}*/
	cout << a << endl;
	fun(a);
	cout << a << endl;
	system("pause");
	return 0;
}