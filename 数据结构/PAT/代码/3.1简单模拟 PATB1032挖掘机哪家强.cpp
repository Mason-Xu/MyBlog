// score school MAX

#include<cstdio>
const int maxn = 100010;
int school[maxn] = {0};
int main() {
	int n,schoolID,score;
	scanf("%d",&n);
	for(int i = 0; i<n; i++) {
		scanf("%d%d",&schoolID,&score);
		school[schoolID] += score;
	}
	int MAX = -1,k = 1;  // MAX 最大分数,k是学校下标
	for(int i = 1; i <= n; i++) {
		if(school[i]>MAX) {
			MAX = school[i];
			k = i;
		}
	}

	printf("%d %d\n", k, MAX);
	printf("%d",school[100000]);
	return 0;

}
