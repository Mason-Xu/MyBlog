// PAT A 1065. A+B and C (64bit) (20)
#include<cstdio>
int main(){
	int T;
	int tcase = 1;
	scanf("%d",&T);
	while(T--){
		long long A,B,C,sum;
		bool flag;
		scanf("%lld%lld%lld",&A,&B,&C);
		sum = A+B; 
		if(A>0 && B>0 && sum<0){	// 正溢出为true 
			flag = true;
		}else if(A<0 && B<0 && sum>=0){  // 负溢出为false 
			flag = false;
		}else if(sum>C){
			flag = true;
		}else{
			flag = false;
		}
		if(flag == true){
			printf("Case #%d: true\n",tcase++);
		}else{
			printf("Case #%d: false\n",tcase++);
		}
	}
	return 0;
} 
