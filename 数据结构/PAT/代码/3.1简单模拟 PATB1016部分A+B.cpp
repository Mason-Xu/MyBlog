#include<cstdio>
int main(){
	long long A,DA,B,DB;
	scanf("%lld%lld%lld%lld",&A,&DA,&B,&DB);  // ·¶Î§³¬¹ýint·¶Î§ 
	int PA=0,PB=0;
	while(A!=0){
		if(A%10==DA){
			PA = 10*PA + DA;
		}
		A = A/10;
	} 
	while(B!=0){
		if(B%10==DB){
			PB = 10*PB + DB;
		}
		B = B/10;
	} 
	
	printf("%d\n",PA+PB);
	return 0;
}

