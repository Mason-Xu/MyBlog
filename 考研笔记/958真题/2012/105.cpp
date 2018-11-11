#include<iostream>
using namespace std;

class Sample {
	int A;
	static int B;
public :
	Sample(int a) { 
		A = a;
		B += a;
	}
	static void func(Sample& s);
};
int Sample::B = 0;
void Sample::func(Sample& s) {
	cout << "A=" << s.A << ",B=" << B << endl;
}

int main105() {
	Sample s1(2), s2(7);
	Sample::func(s1);
	Sample::func(s2);
	system("pause");
	return 0;
}