#include<iostream>
using namespace std;

class BaseClass {
public :
	BaseClass() { cout << "构造A对象!" << endl; }
	~BaseClass() { cout << "析构A对象!" << endl; }
};
class DerivedClass : public BaseClass {
public:
	DerivedClass() { cout << "构造C对象!" << endl; }
	~DerivedClass() { cout << "构造C对象!" << endl; }
};

int main102() {
	DerivedClass c;
	
	
	return 0;
}