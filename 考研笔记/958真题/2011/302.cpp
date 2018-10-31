#include<iostream>
using namespace std;

class Rectangle {
private:
	double width;
	double height;
	double a;
public:
	Rectangle() { a = 0, width = 0, height = 0; }
	Rectangle(double w,double h){ 
		width = w;
		height = h;
	}
	double a() { 
		a = width * height;
		cout << a; 
		return a;
	}
	bool operator >(const Rectangle &r) {
		if (a> r.a) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Rectangle r1(5, 6), r2(4, 5);
	cout << "r1的面积=";
	r1.a();
	cout << endl;
	cout << "r2的面积=";
	r2.a();
	cout << endl;
	if (r1 > r2) {
		cout << "r1>r2" << endl;
	}
	else {
		cout << "r1<r2" << endl;

	}
	system("pause");
	return 0;

}