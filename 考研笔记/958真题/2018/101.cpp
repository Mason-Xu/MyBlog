#include<iostream>
using namespace std;


int main101() {
	char ch;
	char title[] = "Titanic";
	ch = title[1];
	title[3] = ch;
	cout << title << endl;
	cout << ch << endl;
	system("pause");
	return 0;
}