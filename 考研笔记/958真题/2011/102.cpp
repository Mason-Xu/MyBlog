#include<iostream>
using namespace std;

class BaseClass {
public :
	BaseClass() { cout << "����A����!" << endl; }
	~BaseClass() { cout << "����A����!" << endl; }
};
class DerivedClass : public BaseClass {
public:
	DerivedClass() { cout << "����C����!" << endl; }
	~DerivedClass() { cout << "����C����!" << endl; }
};

int main102() {
	DerivedClass c;
	
	
	return 0;
}