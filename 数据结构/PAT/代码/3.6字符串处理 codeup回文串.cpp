#include<cstdio>
#include<cstring> 
const int maxn = 256;
bool judge(char str[]){
	int len = strlen(str);	// ?????????
	for(int i = 0;i<len/2;i++){
		if(str[i]!=str[len-1-i]){
			return false;
		}
	} 
	return true;
}
int main(){
	char str[maxn];	// ????????? 
	while(gets(str)){	// ?????????? 
		bool flag = judge(str);	// ?��?
		if(flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
