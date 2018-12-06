#include<iostream>
using namespace std;

class TestClass1 {
public :
	TestClass1(int i = 0) {
		m_i = i;
	}
	void print() {
		cout << "TestClass1:" << m_i << endl;
	}
	int m_i;
};

class TestClass2 {
public :
	TestClass2() {}
	void printf() {
		cout << "TestClass2" << endl;
	}
};
int main201() {
	TestClass1 obj1;
	TestClass2 obj2;
	obj1.print();
	obj2.printf();
	
	system("pause");
	return 0;
}