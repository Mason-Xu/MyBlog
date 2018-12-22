#include<iostream>
using namespace std;

int sum_from_to(int first, int last) {
	int sum = 0;
	if (first > last) {
		int temp = first;
		first = last;
		last = temp;
	}
	for (int i = first; i <= last; i++) {
		sum += i;
	}
	return sum;
}

int main302(){
	cout << sum_from_to(4, 7) << endl;
	cout << sum_from_to(-3, 1) << endl;
	cout << sum_from_to(7, 4) << endl;
	cout << sum_from_to(9, 9) << endl;
	system("pause");
	return 0;
}