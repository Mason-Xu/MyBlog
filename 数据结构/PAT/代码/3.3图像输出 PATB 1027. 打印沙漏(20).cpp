// PATB 1027. 打印沙漏(20)
#include<cstdio>
#include<cmath>
int main(){
	int n,bottom,x;
	char c;
	scanf("%d %c",&n,&c);
	bottom = floor(sqrt(2.0*(1+n))-1);	// floor向下取整（也可以使用int的强制类型转换），和使用sqrt函数 
	if(bottom%2==0){
		bottom --;	// 如果还是偶数，则-1 
	}
	for(int i = bottom;i>=1;i-=2){		// 输出倒三角 
		for(int j = 1;j<=(bottom-i)/2;j++){
			printf(" ");	// 空格数为（bottom-i）/2 
		}
		for(int j =0;j<i;j++){
			printf("%c",c);
		}
		printf("\n");
	}
	for(int i = 3;i<=bottom;i+=2){		// 输出正三角 ,直接从i=3开始 
		for(int j = 1;j<=(bottom-i)/2;j++){
			printf(" ");
		}
		for(int j=0;j<i;j++){
			printf("%c",c);
		}
		printf("\n");
	}
	int used = (bottom+1)*(bottom+1)/2-1;	// 使用过的* 
	printf("%d\n",n-used);
	return 0;
}
