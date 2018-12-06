#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
using namespace std;

class CD {
	char *a;
	int b;
public :
	void Init(char* aa,int bb) {
		a = new char[strlen(aa) + 1];
		strcpy(a, aa);
		b = bb;
	}
	char* Geta() { return a; }
	int Getb() { return b; }
	void Output() { cout << a << ' ' << b << endl; }
};

int main103() {
	CD dx, dy;
	char a[20];
	char aa[] = "abcdef";
	dx.Init(aa, 30);
	strcpy(a, dx.Geta());
	strcat(a, "xyz");
	dy.Init(a, dx.Getb() + 20);
	dx.Output();
	dy.Output();

	system("pause");
	return 0;
}