#include<iostream>
#include<cmath>
using namespace std;

class Point {
private:
	double X, Y;
public :
	Point(double xx = 0, double yy = 0) {
		X = xx; Y = yy;
		cout << "Point(" << X << "," << Y << ")" << endl;
	}
	Point(Point &p) {
		X = p.X; Y = p.Y;
		cout << "Point is copied" << endl;
	}
	double Distance(Point &p);
};

double Point::Distance(Point &p) {
	double dx, dy;
	dx = X - p.X;
	dy = Y - p.Y;
	return sqrt(dx * dx + dy * dy);
}

Point f(double x, double y) {
	Point p(x, y);
	return p;
}

int main103() {
	Point A(0, 0);
	Point &&B = f(3, 4);
	//f(3,4) error �ǳ����ĳ�ʼֵ����Ϊ��ֵ
	cout << "Distance is " << A.Distance(B) << endl;
	system("pause");
	return 0;
}
