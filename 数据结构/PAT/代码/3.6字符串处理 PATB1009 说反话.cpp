#include<cstdio>
int main() {
	int ans[90][90];
	int num = 0;  // 单词数量
	while(scanf("%s",&ans[num])!=EOF) {		// scanf 识别空格
		num++;
	}
	for(int i = num-1; i>=0; i--) {
		printf("%s",ans[i]);
		if(i>0) {
			printf(" ");
		}
	}
	return 0;
}
