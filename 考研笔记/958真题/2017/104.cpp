#include<iostream>
using namespace std;

class Time {
public:
	Time() { minute = 0; sec = 0; }
	Time(int m, int s) :minute(m), sec(s) {};
	Time fun1(); Time fun2();
	void display() { cout << minute << ":" << sec<<endl; }
private:
	int minute;
	int sec;
};

Time Time::fun1() {
	if (++sec >= 60) {
		sec -= 60;
		++minute;
	}
	return *this;
}
Time Time::fun2() {
	Time temp(*this);
	sec++;
	if (sec >= 60) {
		sec -= 60;
		++minute;
	}
	return temp;
}

int main104() {
	Time time1(34, 59), time2;
	cout << "time1:   ";time1.display();
	time1.fun1();
	cout << "++time1:"; time1.display();
	time2 = time1.fun2(); cout << "time1++:   "; time1.display();
	cout << "time2:  "; time2.display();

	system("pause");
	return 0;
}



//time1:   34 : 59
//	++time1 : 35 : 0
//	time1++ : 35 : 1
//	time2 : 35 : 0