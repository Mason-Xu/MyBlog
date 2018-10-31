#include<iostream>
using namespace std;

class CRectangle {
private:
	double length, width;
public :
	CRectangle() {
		cout << "Default constructor.\n";
	}
	CRectangle(double l, double w) {
		length = l; width = w;
		cout << "Constructor.\n";
	}
	void set(double l, double w) {
		this->length = l;
		this->width = w;
	}
	void GetArea() {
		cout << "Area is " << length * width << endl;
	}

};

int main202() {
	CRectangle Rect1(3.0, 4.0);
	CRectangle Rect2;
	CRectangle Rect3 = Rect1;	// CRectangle Rect3; 会再次构造函数或者带参构造函数
	Rect1.GetArea();
	Rect2.set(0, 1);
	Rect2.GetArea();
	Rect3.GetArea();
	system("pause");
	return 0;

}