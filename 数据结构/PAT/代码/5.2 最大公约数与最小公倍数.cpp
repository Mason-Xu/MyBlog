// ���Լ������󹫱��� 
#include<cstdio> 
int gcd(int a,int b){	// ���Լ������ 
	return !b ? a: gcd(b,a%b);
} 
int lcm(int a,int b){	// ��С���������� 
	return a / gcd(a,b) * b;	// Ҫʹ�� a*b / ab�����Լ��,ab���ܻ����,����Ҫa/gcd(a,b)*b   a/gcd(a,b) һ���Ǹ����� 
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("���Լ��:%d\n",gcd(a,b));
	printf("��С������:%d\n",lcm(a,b));
	return 0;
}
