#include<iostream>
using namespace std;

int a = 10;

class CObj {
private:
	int a, b;
public :
	CObj() {
		a = b = 0;
	}
	void display() {
		cout << a << b << endl;
	}

	void func(int a) {
		this->a= a;
	}

	void func2() {
		a = a + ::a;
	}
};
int main201() {
	CObj obj;
	obj.func(3);
	obj.display();
	obj.func2();
	obj.display();
	system("pause");
	return 0;
}

//输出 
//30
//130