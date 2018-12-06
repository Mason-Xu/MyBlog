#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int a[4] = { 36,-5,73,8 };
int main101() {
	int i, y;
	for (i = 0; i < 4; i++) {
		if (a[i] < 0) y = 1;
		else if (a[i] < 10) y = a[i] * a[i] + 3;
		else if (a[i] < 60) y = 4 * a[i] - 5;
		else y = int(sqrt(a[i]));
		cout <<  setw(5) << a[i] << setw(5) << y;
	}
	system("pause");
	return 0;
}


//***36**139
//***-5****1
//***73****8
//****8***67