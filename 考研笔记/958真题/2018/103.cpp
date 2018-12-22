#pragma warning(disable:4996)
#include<iostream>
#include<string>
using namespace std;
class Film {
	char *a;
	int b;
public :
	void Init(char* pa, int ib) {
		a = new char[strlen(pa) + 1]; strcpy(a, pa);
		b = ib;
	}
	char* Geta() { return a; }
	int Getb() { return b; }
	void Output() { cout << a << ' ' << b << endl; }
}dx;

int main103() {
	Film dy;
	char LA[] = "LA LA LAND";
	dx.Init(LA, 30);
	char RO[] = "Robot";
	dy.Init(RO, 3 * dx.Getb() + 5);
	dx.Output();
	dy.Output();
	system("pause");
	return 0;
}