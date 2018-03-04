// PAT A £º 1042. Shuffling Machine (20)
#include<cstdio>

const int N = 54;
int main(){
	int b[55];
	int k;  
	char mp[5] = {'S','H','C','D','J'};
	int start[55];
	for(int i = 1;i<=N;i++){
		start[i] = i;
	}
	int end[55]={0};
	scanf("%d",&k);
	for(int i =1;i<=N;i++){
		scanf("%d",&b[i]);
	}
	for(int step=0;step<k;step++){
		for(int j = 1;j<=N;j++){
			end[b[j]] = start[j];
		}
		for(int j = 1;j<=N;j++){
			start[j] = end[j];
		}
	}
	for(int i = 1;i<=N;i++){
		if(i!=1) printf(" ");
		start[i]--;
		printf("%c%d",mp[start[i]/13],start[i]%13+1);
	}
	return 0;
		
} 
