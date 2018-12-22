#include<iostream>
using namespace std;

class Goods {
private:
	int num;
	double price;
public :
	Goods() {}
	Goods(int n, double p) { num = n; price = p; }
	double cost() { return num * price; }
};
int main() {
	Goods g(5, 30.8);
	double money = g.cost();
	cout << "cost:" << money << endl;
	system("pause");
	return 0;
}