#include<iostream>
#define PI 3.14
using namespace std;


class Body {
protected:
	double data;
public :
	virtual double SurfaceArea()=0;
	virtual double Volume()=0;
};

class Cube :public Body {
public :
	Cube(double l=0) { data = l; }
	double SurfaceArea() {
		return data * data * 6;
	}
	double Volume() {
		return data * data*data;
	}
};

class Ball :public Body {
public :
	Ball(double r=0) { data = r; }
	double SurfaceArea() {
		return 4 * PI*data*data;
	}
	double Volume() {
		return data * data*data*PI * 4 / 3;
	}
};
class Cylinder :public Body {
private:
	double height;
public :
	Cylinder(double r=0,double h =0){
		data = r;
		height = h;
	}
	double SurfaceArea() { return (2*PI*data*data+2*PI*data*height); }
	double Volume() {
		return height * data*data*PI;
	}
};

int main3032() {
	Body *body[3];
	Cube cube(3);
	Cylinder cylinder(3, 4);
	Ball ball(3);
	body[0] = &cube;
	body[1] = &cylinder;
	body[2] = &ball;
	
	for (int i = 0; i < 3; i++) {
		cout << "表面积:" << body[i]->SurfaceArea() << "体积:" << body[i]->Volume() << endl;
	}
	system("pause");
	return 0;
}