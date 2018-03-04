// PATB1006. 换个格式输出整数 (15)
#include<cstdio>
int main(){
	int k;
	scanf("%d",&k);
	int b,s,n;
	b = k/100;
	s = k/10%10;
	n = k%10;
	for(int i=0;i<b;i++){
		printf("B");
	}
	for(int i=0;i<s;i++){
		printf("S");
	}
	for(int i=1;i<=n;i++){
		printf("%d",i);
	}
	return 0;
	
} 
