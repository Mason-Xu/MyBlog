// PATB 1010. 一元多项式求导 (25) 
#include<cstdio>
const int  maxn =1010;
int main(){
	int a[maxn] = {0};
	int k,e,count = 0;	// k为系数，e为指数，count计数不为0的导数项个数
	while(scanf("%d%d",&k,&e)!=EOF){
		a[e] = k;	// a数组用来存储系数 
	} 
	a[0] = 0;	// 零次项求导之后直接为0
	for(int i =1;i<=1000;i++){
		a[i-1] = a[i]*i;	// 求导公式，覆盖前面
		a[i] = 0; // 此句不可以省
		if(a[i-1]!=0) count++;	//计数不为0的导数项个数 
	} 
	if(count==0) printf("0 0");	//特例
	else{
		for(int i = 1000;i>=0;i--){	// 指数递降 
			if(a[i]!=0){
				printf("%d %d",a[i],i);
				count--;
				if(count!=0) printf(" ");
			}
		}
	} 
	return 0;
} 
