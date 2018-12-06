#include<iostream>
using namespace std;


int main101() {
	int n = 2048;
	int lg = 0;
	for (int i = 1; i < n; i = i * 2) {
		lg++;
		cout <<i<<" "<< lg << endl;
	}
	cout << n << " " << lg << endl;
	system("pause");
	return 0;
}