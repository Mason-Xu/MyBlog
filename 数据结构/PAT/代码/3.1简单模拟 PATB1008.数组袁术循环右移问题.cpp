#include<cstdio>
const int maxn = 110;
int main(){
	int a[maxn];
	int n,m,count=0;	// count 是计算输出元素个数,当输出元素个数小于n时,输出元素后面加空格 
	scanf("%d%d",&n,&m);
	m = m%n;	// 当m>n时,修正m 
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	if(m==0){
		for(int i = 0;i<n;i++){
			printf("%d",a[i]);
			count++;
			if(count<n){
				printf(" ");
			}
		}
	}else{
		for(int i = n-m;i<n;i++){	// 直接输出 n-m~n-1 
			printf("%d",a[i]);
			count++;
			if(count<n){
				printf(" ");
			}
		}
		for(int i=0;i<n-m;i++){		// 直接输出 0~n-m-1
			printf("%d",a[i]);
			count++;
			if(count<n){
				printf(" ");
			}
		}	
	} 
	return 0;
} 
