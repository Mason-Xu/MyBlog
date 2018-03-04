#include<cstdio>
const int maxn = 1010;
int main() {
	int a1=0,a2=0,a3=0,a4=0,a5=0;
	int count[maxn]={0};
	int n,temp;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&temp);
		int k = temp%5;
		switch(k) {
			case 0:
				if(temp%2==0) {
					a1=a1+temp;
					count[0]++;
				}
				break;
			case 1:
				count[1]++;
				if(count[1]%2==0) {
					a2 = a2-temp;
				} else {
					a2 = a2+temp;
				}
				
				break;
			case 2:
				a3++;
				count[2]++;
				break;
			case 3:
				count[3]++;
				a4 = a4+temp;
				
				break;
			case 4:
				if(temp>a5){
					a5 = temp;
				}
				count[4]++;
				break;
			default:				
				break;
		}
	}
	if(count[0]==0){
		printf("N "); 
	}else{
		printf("%d ",a1);
	}
	if(count[1]==0){
		printf("N "); 
	}else{
		printf("%d ",a2);
	} 
	if(count[2]==0){
		printf("N "); 
	}else{
		printf("%d ",a3);
	} 
	if(count[3]==0){
		printf("N "); 
	}else{
		printf("%.1f ",(double)a4/count[3]);
	}
	if(count[4]==0){
		printf("N"); 
	}else{
		printf("%d",a5);
	}   
	
	return 0;
}
