#include<iostream>
using namespace std;

class student {
public :
	int rno, m1, m2;
	void get() {
		rno = 15, m1 = 10, m2 = 10;
	}
};
class sports {
public :
	int sm;
	void getsm() {
		sm = 10;
	}
};

class statement :public student, public sports {
	int tot, avg;
public :
	void display() {
		tot = (m1 + m2 + sm);
		avg = tot / 3;
		cout << tot;
		cout << avg;
	}
};
int main105() {
	statement obj;
	obj.get();
	obj.getsm();
	obj.display();
	system("pause");
	return 0;
}