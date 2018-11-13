#include<iostream>
using namespace std;


int main102() {
	int n = 5;
	while (--n > 0) {
		if (n == 2) exit(0);
		cout << n << " ";
	}
	cout <<"End.";
	system("pause");
	return 0;
}

//  exit(0) 非正常结束进程