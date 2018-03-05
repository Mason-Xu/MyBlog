#include<cstdio>
const int maxn = 10010;
struct Student{
  int id;
  int dscore;
  int cscore;
}ans[maxn];

int main(){	
	int n,small,big;
	scanf("%d%d%d",&n,&small,&big);
	for(int i =0;i<n;i++){
		scanf("%d%d%d",&ans[i].id,&ans[i].dscore,&ans[i].cscore);
	}
	for(int i =0;i<n;i++){
		printf("%d %d %d\n",ans[i].id,ans[i].dscore,ans[i].cscore);
	}
	return 0;
}
