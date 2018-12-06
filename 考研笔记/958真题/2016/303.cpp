#include<iostream>
using namespace std;

class Vehicle{
protected:
	double maxSpeed, currentSpeed, weight;
public :
	void start() {}
	void stop() {}
};

class Bicycle :public Vehicle {
protected:
	double height;
};

class Motacar :public Vehicle {
protected:
	int seatNum;
};

class Motocycle :public Bicycle , public Motacar{

};



int main303() {
	
	system("pause");
	return 0;
}