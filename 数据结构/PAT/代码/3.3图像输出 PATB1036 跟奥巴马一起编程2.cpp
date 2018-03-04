#include<cstdio>
int main() {
	int row,col,N;
	char c;
	scanf("%d %c",&N , &c);
	col = N;
	if(col%2==0) {
		row = col/2;
	} else {
		row = col/2+1;
	}

	// first
	for(int i = 0; i<col; i++) {
		printf("%c",c);
	}
	printf("\n");

	//second~end-1
	for(int i=0; i<row-2; i++) {
		printf("%c",c);
		for(int j = 0; j<col-2; j++) {
			printf(" ");
		}
		printf("%c\n",c);
	}

	// end
	for(int i = 0; i<col; i++) {
		printf("%c",c);
	}
	printf("\n");
	
	return 0;
}
