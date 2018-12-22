#pragma warning(disable:4996)
#include<iostream>
#include<string>
using namespace std;

void fun(char *p) {
	char *p1;
	p1 = p;
	while (*p1 != '\0') {
		if (*p1 == ' '&&*(p1 + 1) == ' ') strcpy(p1, p1 + 1);
		else p1++;
	}
}

int main103() {
	char aa[] = "aa  bb  cccc    ddd   efg   h";
	cout << aa << endl;
	fun(aa);
	cout << aa << endl;
	system("pause");
	return 0;
}