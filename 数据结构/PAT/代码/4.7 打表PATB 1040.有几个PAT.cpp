// PATB 1040.�м���PAT
#include<cstdio>
#include<cstring> 
const int maxn = 100010;
const int mod = 1000000007;
char str[maxn];
int leftNumP[maxn] = {0};
int main(){
	gets(str);
	int len = strlen(str);
	for(int i = 0;i<len;i++){
		if(i>0){	// ���i����i��λ 
			leftNumP[i] = leftNumP[i-1];	//�̳���һλ�Ľ�� 
		}
		if(str[i]=='P'){	// ��ǰλ��P 
			leftNumP[i]++;	// +1 
		} 
	}
	int ans = 0,rightNumT = 0;
	for(int i = len-1;i>=0;i--){
		if(str[i] == 'T'){
			rightNumT++;
		}else if(str[i] == 'A'){
			ans = (ans + leftNumP[i]*rightNumT)%mod;
		}
	} 
	printf("%d",ans);
	return 0;
}

