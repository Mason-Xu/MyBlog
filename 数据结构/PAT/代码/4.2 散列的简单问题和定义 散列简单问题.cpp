// 散列 简单问题 
#include<cstdio> 
bool hashTable[100010] = {false};
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(int i = 0;i<n;i++){
		scanf("%d",&x);
		hashTable[x] = true;
	} 
	for(int i =0;i<m;i++){
		scanf("%d",&x);
		if(hashTable[x]){
			printf("Yes\n"); // 如果x出现过,打印Yes 
		} else{
			printf("No\n");	// 如果x没有出现过,打印No 
		} 
	}
	return 0;
}
