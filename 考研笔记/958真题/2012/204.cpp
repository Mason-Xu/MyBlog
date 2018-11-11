#include<iostream>
using namespace std;

class local {
	int x, y;
	
public :
	void init() { x = 0; y = 1; }
	void printX() { cout << x; }
	void printY() {
		cout << y;
	}
};

int main() {
	local a, b, c;
	a.init();
	a.printX();
	a.printY();
	system("pause");
	return 0;
}