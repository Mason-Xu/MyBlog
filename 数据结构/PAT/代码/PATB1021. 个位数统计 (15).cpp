#include<cstdio>
const int maxn = 1000;
int main(){
    int N;
    scanf("%d",&N);
    int num[10]={0};
    if(N==0){
    	num[0]++;
	}
    while(N!=0){
        int k = N%10;
        num[k]++;
        N = N/10;
    }
    
    for(int i=0;i<10;i++){
    	if(num[i]!=0){
    		printf("%d:%d\n",i,num[i]);
		}        
    }
    return 0;
}
