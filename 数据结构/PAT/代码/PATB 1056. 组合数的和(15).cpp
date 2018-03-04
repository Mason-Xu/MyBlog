// PATB 1056. 组合数的和(15)
#include<cstdio>
int main(){
	int N,sum=0;
	scanf("%d",&N);
	int a[N];
	for(int i = 0;i < N;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			if(j!=i){
				sum = sum + a[i]*10+a[j];	// 不要 相同数字组合的二位数 
			}
		}
	}
	printf("%d",sum);
	return 0;
}
