#include<iostream>
#include<algorithm>
using namespace std;


int main301() {
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		cin >> a[i];
	}
	int count=0;	// 重复个数
	for (int i = 0; i < 20; i++) {
		for (int j = i + 1; j < 20; j++) {
			if (a[i] = a[j]) {
				for (int k = j + 1; k < 20; k++) {
					a[k - 1] = a[k];	// 将重复的往后移
				}
				count++;
				j--;	//	进行自检
			}
		}
	}
	for (int i = 0; i < 20-count; i++) {
		cin >> a[i];
	}
	system("pause");
	return 0;
}