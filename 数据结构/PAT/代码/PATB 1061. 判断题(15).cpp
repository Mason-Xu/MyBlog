// PATB 1061. еп╤олБ(15)
#include<cstdio>
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int score[m];
	for(int i = 0;i<m;i++){
		scanf("%d",&score[i]);
	}
	int right[m];
	for(int i = 0;i<m;i++){
		scanf("%d",&right[i]);
	}
	int sum[n]={0};
	for(int i = 0;i<n;i++){
		int temp[m]={0};
		for(int j = 0;j<m;j++){
			scanf("%d",&temp[j]);
			if(temp[j]==right[j]){
				sum[i]+=score[j];
			}
		}
	}
	for(int i = 0;i<n;i++){
		printf("%d\n",sum[i]);
	}
	return 0;
} 
