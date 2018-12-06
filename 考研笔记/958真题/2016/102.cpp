#include<iostream>
using namespace std;

class Mystery1 {
	int x, y;
public :
	void init(int a, int b) { x = a, y = b; }
	void disp() { cout << "x=" << x << "y=" << y << endl; }
};

int main102() {
	Mystery1 s, *p = &s;
	s.init(10, 20);
	s.disp();
	system("pause");
	return 0;
}