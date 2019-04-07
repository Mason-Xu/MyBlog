#include<iostream>
using namespace std;

class Divived {
private:
	int x;
public :
	Divived(int a) {
		x = a;
	}
	void yingzi() {
		if (x > 0) {
			for (int i = x - 1; i >= 1; i--) {
				if (x%i == 0) {
					cout << i << endl;
				}
			}
		}
		else {
			cout << x << "不是一个正整数。" << endl;
		}
		
	}
};

int main() {
	cout << "请输入一个正整数：";
	int x;
	cin >> x;
	Divived a(x);
	do {
		a.yingzi();
		char y;
		cout << "你想看另一个整数（Y/N)的除数吗？";
		cin >> y;
		if (y == 'Y' || y == 'y') {
			cout << "请输入一个正整数：";
			int x;
		}
	}while();
	system("pause");
	return 0;
}