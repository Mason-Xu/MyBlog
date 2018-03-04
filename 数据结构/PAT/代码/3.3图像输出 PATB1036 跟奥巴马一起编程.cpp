#include<cstdio>
int main(){
	int N,row,col;
	char c;
	scanf("%d %c",&N,&c);
	col = N;
	if(col%2==0){
		row = col/2;
	}else{
		row = col/2+1;
	}
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++){
			if(i==1||i==row) printf("%c",c);
			else if(j==1||j==col) printf("%c",c);
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
