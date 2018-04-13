// PATB 1040.有几个PAT
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
		if(i>0){	// 如果i不是i号位 
			leftNumP[i] = leftNumP[i-1];	//继承上一位的结果 
		}
		if(str[i]=='P'){	// 当前位是P 
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

