#include<iostream>
using namespace std;

struct Fract {
	int num;
	int deno;
};
Fract sum(Fract, Fract);
int main104() {
	int num1, deno1, num2, deno2;
	cout << "请输入分数1：分子 分母：";
	cin >> num1 >> deno1;
	cout << "请输入分数2：分子 分母：";
	cin >> num2 >> deno2;
	Fract f1 = { num1,deno1 };
	Fract f2 = { num2,deno2 };
	Fract result = sum(f1, f2);
	cout << result.num << "/" << result.deno;
	system("pause");
	return 0;
}
Fract sum(Fract f1, Fract f2) {
	Fract result = { (f1.num*f2.deno) + (f2.num*f1.deno),f1.deno*f2.deno };
	return result;
}