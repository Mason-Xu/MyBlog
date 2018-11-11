#include<iostream>
using namespace std;
class AA {
private:
	int A = 0, B = 0;
public :
	AA(int i, int j) {
		A = i; B = j;
		cout << "Constructor.\n";
	}
	~AA() {
		cout << "Destructor.\n";
	}
	void Print();
};

void AA::Print() {
	cout << A << "," << B << endl;
}

int main202() {
	AA *a1, *a2;
	a1 = new AA(1, 2);
	a2 = new AA(3, 4);
	a1->Print();
	a2->Print();
	delete a1;
	delete a2;
	system("pause");
	return 0;
}