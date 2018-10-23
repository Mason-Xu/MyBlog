#include<iostream>
using namespace std;

class A1 {
	int num;
public:
	A1() { num = 0; cout << "缺省构造函数" << endl; }
	A1(int n) { num = n; cout << "带参构造函数，num=" << n << endl; }
	~A1() { cout << "析构函数，num=" << num << endl; }
};

int main105() {
	A1 a, *p;	
	p = new A1(2);
	a = *p;
	delete p;
	cout << "退出" << endl;
	system("pause");
	return 0;
}
