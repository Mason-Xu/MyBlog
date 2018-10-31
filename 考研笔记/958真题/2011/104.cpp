#include<iostream>
#include<string>
using namespace std;
class sample {
public :
	int i, j;
	sample(int a=0 ,int b=0){
		i = a;
		j = b;
		cout << "constructor1" << endl;
	}
	sample(const sample& H) {
		i = H.i; j = H.j;
		cout << "constructor2" << endl;
	}
	void plus(sample H) {
		i += H.i;
		j += H.j;
	}
	void  display() {
		cout << i << " " << j << endl;
	}
};

int main104() {
	sample s1(3, 3), s2(4, 4), s3(5, 5);
	s2.display();
	s1.plus(s3);
	s1.display();
	system("pause");
	return 0;
}