#include<iostream>
using namespace std;

void f(char *p) {
	p++;									// de ָ��ָ��e
	char &c = *p;							// c�ĵ�ַ��ֵp��ֵ
	c += 'A' - 'a';							// e��ΪE
}

int main203() {
	char str[] = "abcde";
	//cout <<"*(str+3)="<< *(str+3) << endl;	// ��� d
	//cout <<"*str+3="<< *str+3 << endl;		// ��� 100 
	//cout <<"str+3="<< str+3 << endl;		// ���de
	f(str + 3);								// de���뺯��
	char d = 'A';
	cout << "d="<<d << endl;
	cout << "d+2="<<d+2 << endl;
	cout << str << endl;
	system("pause");
	return 0;
}