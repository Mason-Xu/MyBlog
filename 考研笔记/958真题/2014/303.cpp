#include<iostream>
using namespace std;

void fun(char *a, int b[]) {
	int i;
	for (i = 0; i < 10; i++) {
		b[i] = 0;		// b[] 初始化
	}
	while (*a) {		// 字符串首位
		int j = *a - '0';	
		if (j >= 0 && j <= 9) b[j]++;
		a++;	// 字符串下个位置
	}
}

int main303() {
	char str[] = {'4','5','6','7'};
	int b[10];
	fun(str, b);
	for (auto c : b) {
		cout << c << endl;
	}
	system("pause");
	return 0;
}