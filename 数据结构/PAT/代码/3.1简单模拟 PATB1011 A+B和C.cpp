#include<cstdio>
int main(){
	int tcase = 1,T;
	scanf("%d",&T);
	while(T--){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a+b>c){
			printf("Case #%d: true\n",tcase++);
		}else{
			printf("Case #%d: false\n",tcase++);
		}
	}
	return 0; 
} 
