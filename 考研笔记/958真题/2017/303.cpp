#include<iostream>
#include<cmath>

#define PI 3.14
using namespace std;

class Shape {
public:
	Shape() {}
	virtual double getArea() const = 0;
};

class Circle :public Shape {
private:
	double radius;
public :
	Circle(int r) { radius = r; }
	double getArea()const{ return PI * radius*radius; }
};

void printArea(Shape &s) {
	cout << s.getArea() << endl;
}

int main303() {
	Circle c(3);
	printArea(c);
	system("pause");
	return 0;
}