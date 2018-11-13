#include<iostream>
using namespace std;

class Sample {
	int x, y;
public:
	Sample() { x = y = 0; }
	Sample(int a, int b) { x = a; y = b; }
	void disp() { cout << "x=" << x << ",y=" << y << endl; }
};

int main104() {
	Sample s1, s2(2, 3);
	s1.disp();
	s2.disp();
	system("pause");
	return 0;
}