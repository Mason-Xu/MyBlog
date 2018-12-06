#pragma warning(4996)
#include<iostream>
using namespace std;


int main202() {
	char str[][7] = { "First","Second","Third","Forth","Fifth" };
	char *cp[] = { str[4],str[3], str[2], str[1], str[0] };
	int i=0;
	while (i < 5) {
		printf("%s", *(cp + i));
		i++;
	}
	system("pause");
	return 0;
}