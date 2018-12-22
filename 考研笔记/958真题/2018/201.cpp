#include<iostream>
using namespace std;

class TestClass {
public :
	TestClass(int i) {
		number = i;
	}
	void SetNumber(int m) {
		number = m;
	}
	int GetNumber()const {
		return number;
	}
	void Print()const { cout << "numer=" << number << endl; }
private:
	int number;
};
int main201() {
	TestClass obj1(1);
	obj1.Print();
	TestClass obj2(3);
	obj1.SetNumber(10);
	obj2.SetNumber(100);
	obj1.Print();
	obj2.Print();

	system("pause");
	return 0;
}