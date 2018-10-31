#include<iostream>

using namespace std;

struct S{
	int grades;
	S *next;
};

int fun(S *h) {
	if (h == nullptr) {
		return -1;
	}
	int max;
	S *node = h;
	max = node->grades;
	node = node->next;
	while (node != nullptr) {
		if (node->grades > max) {
			max = node->grades;
		}
		node = node->next;
	}
	return max;
}

int main302() {
	S s1;
	S s2;
	S s3;
	S s4;
	s1.next = &s2;
	s1.grades = 30;
	s2.next = &s3;
	s2.grades = 80;
	s3.next = &s4;
	s3.grades = 70;
	s4.next = nullptr;
	s4.grades = 40;
	cout << fun(&s1) << endl;
	system("pause");
	return 0;
}