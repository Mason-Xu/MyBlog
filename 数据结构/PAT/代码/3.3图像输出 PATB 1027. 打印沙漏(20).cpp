// PATB 1027. ��ӡɳ©(20)
#include<cstdio>
#include<cmath>
int main(){
	int n,bottom,x;
	char c;
	scanf("%d %c",&n,&c);
	bottom = floor(sqrt(2.0*(1+n))-1);	// floor����ȡ����Ҳ����ʹ��int��ǿ������ת��������ʹ��sqrt���� 
	if(bottom%2==0){
		bottom --;	// �������ż������-1 
	}
	for(int i = bottom;i>=1;i-=2){		// ��������� 
		for(int j = 1;j<=(bottom-i)/2;j++){
			printf(" ");	// �ո���Ϊ��bottom-i��/2 
		}
		for(int j =0;j<i;j++){
			printf("%c",c);
		}
		printf("\n");
	}
	for(int i = 3;i<=bottom;i+=2){		// ��������� ,ֱ�Ӵ�i=3��ʼ 
		for(int j = 1;j<=(bottom-i)/2;j++){
			printf(" ");
		}
		for(int j=0;j<i;j++){
			printf("%c",c);
		}
		printf("\n");
	}
	int used = (bottom+1)*(bottom+1)/2-1;	// ʹ�ù���* 
	printf("%d\n",n-used);
	return 0;
}
