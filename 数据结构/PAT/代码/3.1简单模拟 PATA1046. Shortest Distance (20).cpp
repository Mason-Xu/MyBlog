#include<cstdio>
#include<algorithm>
using namespace std; 
const int maxn =100005;
int dis[maxn],a[maxn];		// dis�����¼1�ŵ�i�ŵľ��� (˳ʱ��)��a�����¼i�ŵ�i+1�ŵľ��� 
int main(){
	int N,sum=0,query,left,right;  // query �ǲ�ѯ�Ĵ��� 
	scanf("%d",&N);
	for(int i = 1;i<=N;i++){
		scanf("%d",&a[i]);
		sum += a[i];
		dis[i] = sum; 
	}
	scanf("%d",&query);
	while(query--){
		scanf("%d%d",&left,&right);
		if(left>right) swap(left,right);  //  #include<algorithm>  using namespace std; 
		int temp = dis[right-1]-dis[left-1];
		printf("%d\n",min(temp,sum-temp));
	}
	return 0;
}
