#include<iostream>
#include<algorithm>
using namespace std;

// 先排序后删除
// 新建一个新数组

int main301() {
	int a[20];
	for (int i = 0; i < 20; i++) {
		cin >> a[i];
	}
	sort(a, a + 20);
	int index=0;
	int a_copy[20];

	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < 20; i++) {
		if (a[i] != a[i + 1]) {
			a_copy[index++] = a[i];
		}
	}

	for (int i = 0; i < index;i++) {
		cout << a_copy[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}