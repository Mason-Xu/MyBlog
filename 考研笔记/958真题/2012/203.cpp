#include<iostream>
using namespace std;

void f(char *p) {
	p++;									// de 指针指向e
	char &c = *p;							// c的地址赋值p的值
	c += 'A' - 'a';							// e变为E
}

int main203() {
	char str[] = "abcde";
	//cout <<"*(str+3)="<< *(str+3) << endl;	// 输出 d
	//cout <<"*str+3="<< *str+3 << endl;		// 输出 100 
	//cout <<"str+3="<< str+3 << endl;		// 输出de
	f(str + 3);								// de传入函数
	char d = 'A';
	cout << "d="<<d << endl;
	cout << "d+2="<<d+2 << endl;
	cout << str << endl;
	system("pause");
	return 0;
}