// PATB 1037. ÔÚ»ô¸ñÎÖ´ÄÕÒÁãÇ®£¨20£©
#include<cstdio>
const int G = 17*29;
const int S = 29;
int main(){
	int a1,b1,c1;
	int a2,b2,c2;
	int P,A;
	scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	P = a1*G+b1*S+c1;
	A = a2*G+b2*S+c2;
	int change = A-P;
	if(change<0){
		printf("-");
		change = -change;
	}	
	printf("%d.%d.%d\n",change/G,change%G/S,change%S);
	return 0;
}
