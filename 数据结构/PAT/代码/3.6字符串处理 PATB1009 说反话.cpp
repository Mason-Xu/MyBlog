// PATB1009. 说反话 (20)
#include<cstdio>
int main(){
	int num=0;	// 单词的个数 
	char ans[90][90];
	while(scanf("%s",ans[num])!=EOF){
		num++;
	}
	for(int i = num-1;i>=0;i--){
		printf("%s",ans[i]);
		if(i>0) printf(" ");
	}
	return 0;
}
