#include<cstdio>
int main() {
	int ans[90][90];
	int num = 0;  // ��������
	while(scanf("%s",&ans[num])!=EOF) {		// scanf ʶ��ո�
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
