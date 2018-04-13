// PATB1013. 数素数 (20) 
#include<cstdio>
#include<cmath>
const int maxn =1000001;
int prime[maxn] , num =0;

bool isPrime(int n){
	if(n<=1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
void Find_Prime(int n){
	for(int i = 2;i<maxn;i++){
		if(isPrime(i)){
			prime[num++] = i;
			if(num>=n) break;
		}
	}
}
int main(){
	int m,n,count = 0;
	scanf("%d%d",&m,&n);
	Find_Prime(n);
	for(int i = m;i<=n;i++){
		printf("%d",prime[i-1]);	// 下标从0开始 
		count++;
		if(count % 10 != 0&&i<n) printf(" ");
		else  printf("\n");
	}
	return 0;
}
