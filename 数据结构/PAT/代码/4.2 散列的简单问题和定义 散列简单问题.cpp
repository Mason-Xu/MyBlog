// ɢ�� ������ 
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
			printf("Yes\n"); // ���x���ֹ�,��ӡYes 
		} else{
			printf("No\n");	// ���xû�г��ֹ�,��ӡNo 
		} 
	}
	return 0;
}
