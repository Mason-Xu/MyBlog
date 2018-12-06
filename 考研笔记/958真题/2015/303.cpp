#include <iostream>
#define PI 3.14159
using namespace std;

class Body {
protected:
	double data;
public:
	virtual double SurfaceArea() = 0;
	virtual double Volume() = 0;
};

class CCube :public Body {
public:
	CCube(double a = 0.0) {
		data = a;
	}
	double SurfaceArea() {
		return 6 * data*data;
	}
	double Volume() {
		return data * data*data;
	}
};

class CCylinder :public Body {
public:
	CCylinder(double r = 0.0, double h = 0.0) {
		data = r;
		height = h;
	}
	double SurfaceArea() {
		return (PI*data*data * 2 + 2 * PI*data*height);
	}
	double Volume() {
		return (PI*data*data*height);
	}
private:
	double height;
};

class CBall :public Body {
public:
	CBall(double r = 0.0) {
		data = r;
	}
	double SurfaceArea() {
		return (4 * PI*data*data);
	}
	double Volume() {
		return (4 * PI*data*data*data / 3);
	}
};
int main303() {

	Body *body[3];
	CCube cube(3.0);
	CCylinder cylinder(2.0, 6.0);
	CBall ball(5.0);

	body[0] = &cube;
	body[1] = &cylinder;
	body[2] = &ball;

	for (int i = 0; i < 3; i++) {
		cout << "SurfaceArea " << body[i]->SurfaceArea() << "   Volume:" << body[i]->Volume() << endl;
	}
	system("pause");
	return 0;
}