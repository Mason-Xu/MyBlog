// maxn EOF 查找x k下标  

#include<cstdio>
const int maxn = 210;
int a[maxn];	// 存放n个数
int main() {
	int n, x;
	while(scanf("%d",&n)!=EOF) {
		for(int i = 0; i<n; i++) {
			scanf("%d",&a[i]);
		}
		scanf("%d",&x);
		int k;
		for(k = 0; k<n; k++) {
			if(a[k]==x) {
				printf("%d\n",k);
				break;
			}
		}
		if(k==n) {
			printf("-1\n");
		}
	}

	return 0;
}
