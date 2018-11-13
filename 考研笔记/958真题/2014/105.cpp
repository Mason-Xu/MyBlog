#include<iostream>
using namespace std;
class base {
	int n;
public :
	base() {};
	base(int a) { cout << "基类构造函数"; n = a; cout << "n=" << n << endl; }
	~base() { cout << "基类析构函数" << endl; }
};


class subs :public base {
	int m;
public :
	subs(int a, int b) :base(a) {
		cout << "子类构造函数" << endl;
		m = b;
		cout << "m=" << m << endl;
	}
};
int main105() {
	{subs s(1, 2); }
	system("pause");
	return 0;
}


// main函数 加大括号是为了在system("pause")前执行析构函数