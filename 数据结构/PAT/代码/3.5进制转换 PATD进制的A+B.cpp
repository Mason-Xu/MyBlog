#include<cstdio>
int main() {
	int A,B,D,sum;
	scanf("%d%d%d",&A,&B,&D);
	sum = A+B;
	int ans[31],num=0;
	do {
		ans[num++] = sum%D;
		sum = sum/D;
	} while(sum!=0);

	for(int i= num-1; i>=0; i--) {
		printf("%d",ans[i]);
	}
	return 0;
}
