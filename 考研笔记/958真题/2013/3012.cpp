#include<iostream>
#include<algorithm>
using namespace std;

void fun(char a[]) {
	sort(a + 1, a + 6, [](char x1, char x2) {
		return x1 > x2;
	});
}

int main() {
	char str[8] = "abcdefg";
	/*for (int i = 0; i < 6; i++) {
		cout << a[i] << endl;
	}*/
	cout << str << endl;
	fun(str);
	cout << str << endl;
	system("pause");
	return 0;
}