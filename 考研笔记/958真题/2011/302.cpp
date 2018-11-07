#include<iostream>
using namespace std;

class Rectangle {
private:
	double width;
	double height;
public:
	Rectangle() { width = 0, height = 0; }
	Rectangle(double w,double h){ 
		width = w;
		height = h;
	}
	double area() { 
		cout << width*height; 
		return width * height;
	}
	bool operator >(const Rectangle &rect) {
		if (width*height> rect.width*rect.height) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main302() {
	Rectangle r1(5, 6), r2(4, 5);
	cout << "r1的面积=";
	r1.area();
	cout << endl;
	cout << "r2的面积=";
	r2.area();
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
