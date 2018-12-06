#define SIZE 10
#include<iostream>
using namespace std;

class Stack {
	char stck[SIZE];
	int tos;
public :
	Stack() { tos = 0; }
	bool Push(char x);
	char Pop();
};

bool Stack::Push(char x) {
	if (tos == SIZE) {
		return false;
	}
	else {
		stck[tos++] = x;
		return true;
	}
}

char Stack::Pop() {
	if (tos == 0) {
		return 'f';
	}
	else {
		return stck[--tos];
	}
}

int main301() {
	Stack s;
	s.Push('0');
	s.Push('1');
	s.Push('2');
	s.Push('3');
	s.Push('4');
	s.Push('5');
	s.Push('6');
	s.Push('7');
	s.Push('8');
	s.Push('9');
	cout << s.Pop()<< endl;
	cout << s.Pop()<< endl;
	cout << s.Pop()<< endl;
	system("pause");
	return 0;
}