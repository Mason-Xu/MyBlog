#include<stdio.h>

int main201() {
	char str[5][7] = { "First","Second","Third","Forth","Fifth" };
	char *cp[] = { str[4],str[3],str[2],str[1],str[0] };
	int i = 0;
	while (i < 5) {
		printf("%s ", *(cp+i));
		i++;
	}
	/*printf("\n");
	i = 4;
	while (i >=0) {
		printf("%s ", str[i]);
		i--;
	}
	printf("\n");
	i = 0;
	while (i < 5) {
		printf("%c ", str[2][i]);
		i++;
	}*/
	
	getchar();
	return 0;
}


//Fifth Forth Third Second First
//First Second Third Forth Fifth
// " ) 0   乱码


 