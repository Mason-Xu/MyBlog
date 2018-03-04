#include<cstdio>
int main() {
	int failA=0,failB=0;	// 记录甲乙输的次数 
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a1,a2,b1,b2;
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		if(a1+b1==a2&&a1+b1!=b2){	// 乙输 
			failB++;
		}else if(a1+b1!=a2&&a1+b1==b2){	// 甲输 
			failA++;
		}
	}
	printf("%d %d\n",failA,failB);
	return 0;
}
