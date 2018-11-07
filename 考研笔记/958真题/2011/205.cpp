#include<iostream>
using namespace std;

int main205() {
	int *a;
	int *&p = a;
	int b = 20;
	p = &b;
	cout <<"*a="<< *a<<endl;
	/*cout <<"a="<< a<<endl;
	cout <<"&a="<< &a<<endl;
	cout <<"&b="<< &b<<endl;
	cout <<"b="<< b<<endl;
	cout <<"p="<< p<<endl;
	cout <<"*p="<< *p<<endl;*/
	system("pause");
	return 0;
}