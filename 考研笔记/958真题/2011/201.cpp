#include<iostream>
using namespace std;

class Tany {
	int x, y;
public :
	Tany(int a, int b) { x = a; y = b; }
	int Tsum() { return x + y; }
};

int main201() {
	Tany p(1, 2);
	cout << p.Tsum() << endl;
	system("pause");
	return 0;
}