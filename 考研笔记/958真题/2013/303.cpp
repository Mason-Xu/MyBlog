#include<iostream>
#include<cmath>
using namespace std;

#define MY_PAI 3.1415926

class Shape {
public :
	virtual double getArea() { return 0.0; }
	virtual ~Shape() {}

};

class Circle :public Shape {
private :
	double radius;
public:
	Circle(double r){radius =r;}
	virtual double getArea() { return MY_PAI * radius*radius; }
};
class Square :public Shape {
private:
	double side;
public:
	Square(double s) { side = s;}
	virtual double getArea() { return side*side; }
};
class Rectangle :public Shape {
private:
	double height;
	double width;
public:
	Rectangle(double h, double w) { height = h; width = w; }
	virtual double getArea() { return height * width; }
};
class Triangle :public Shape {
private:
	double a;
	double b;
	double c;
public:
	Triangle(double l1, double l2, double l3) { a = l1; b = l2; c = l3; }
	double p = (a + b + c) / 2;
	virtual double getArea() { return sqrt(p*(p - a)*(p - b)*(p - c)); }
};

double getAreaTotal(Shape *a[], int count) {
	double sum = 0;
	for (int i = 0; i < count; i++) {
		sum += a[i]->getArea();
	}
	return sum;
}


int main() {
	Circle c(1);
	cout << c.getArea() << endl;
	Square s(2);
	cout << s.getArea() << endl;
	Rectangle r(3, 5);
	cout << r.getArea() << endl;
	Triangle t(3, 4, 5);
	cout << t.getArea() << endl;
	Shape *a[] = { &c,&s,&r,&t };
	cout << getAreaTotal(a, 4) << endl;
	system("pause");
	return 0;
}