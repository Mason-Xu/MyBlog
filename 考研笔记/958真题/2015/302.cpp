#include<iostream>
using namespace std;

class Vechicle {
protected:
	int wheels;
	int weight;
};
class Car:public Vechicle {
private:
	int passenger_load;
public :
	Car(int a=0,int b=0,int c=0) { 
		wheels = a;
		weight = b;
		passenger_load = c; 
	}
	void print_passenger_load() {
		cout << "载客量:" << passenger_load << endl;
	}
	void print_wheels() {
		cout << "轮子:" << wheels << endl;
	}
	void print_weight() {
		cout << "重量:" << weight << endl;
	}
};
class Truck :public Vechicle {
private:
	int passenger_load;
	int payload;
public:
	Truck(int a=0, int b=0, int c=0,int d=0) {
		wheels = a;
		weight = b;
		passenger_load = c;
		payload = d;
	}
	void print_passenger_load() {
		cout << "载客量:"<<passenger_load << endl;
	}
	void print_payload() {
		cout << "载重量:" << payload << endl;
	}
	void print_wheels() {
		cout << "轮子:" << wheels << endl;
	}
	void print_weight() {
		cout << "重量:" << weight << endl;
	}
};
int main() {
	Car car(4,1000,5);
	cout << "car的数据" << endl;
	car.print_wheels();
	car.print_weight();
	car.print_passenger_load();
	cout << endl;
	cout << "truck的数据" << endl;
	Truck truck(8, 3000, 6,20000);
	truck.print_wheels();
	truck.print_weight();
	truck.print_passenger_load();
	truck.print_payload();

	system("pause");
	return 0;
}