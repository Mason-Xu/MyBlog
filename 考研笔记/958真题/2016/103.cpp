#include<iostream>
using namespace std;

class Mystery2 {
	int i;
public :
	Mystery2() { i = 1; cout << i++; }
	void disp() { cout << ++i; }
	~Mystery2() { cout << i++; }
};

int main103() {	
	{Mystery2 m;
	m.disp(); }
	system("pause");
	return 0;
}