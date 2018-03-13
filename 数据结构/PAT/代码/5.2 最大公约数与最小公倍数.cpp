// 最大公约数和最大公倍数 
#include<cstdio> 
int gcd(int a,int b){	// 最大公约数函数 
	return !b ? a: gcd(b,a%b);
} 
int lcm(int a,int b){	// 最小公倍数函数 
	return a / gcd(a,b) * b;	// 要使用 a*b / ab的最大公约数,ab可能会溢出,所以要a/gcd(a,b)*b   a/gcd(a,b) 一定是个整数 
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("最大公约数:%d\n",gcd(a,b));
	printf("最小公倍数:%d\n",lcm(a,b));
	return 0;
}
