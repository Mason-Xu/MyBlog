// PATB 1056. ������ĺ�(15)
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
				sum = sum + a[i]*10+a[j];	// ��Ҫ ��ͬ������ϵĶ�λ�� 
			}
		}
	}
	printf("%d",sum);
	return 0;
}
