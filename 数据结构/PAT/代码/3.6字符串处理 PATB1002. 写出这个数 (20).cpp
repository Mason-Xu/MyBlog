// PATB1002. 写出这个数 (20)
#include<cstdio>
#include<cstring>
int main(){
	char str[110]; 
	gets(str);
	int sum =0;
	int len = strlen(str);	// 获取字符串长度 
	for(int i =0;i<len;i++){
		sum+=(str[i]-'0');
	} 
	char change[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int num = 0,ans[10];
	if(sum==0) printf("ling"); 
	while(sum!=0){
		ans[num++] = sum%10;
		sum/=10;
	} 
	for(int i = num-1;i>=0;i--){
		printf("%s",change[ans[i]]);	// ans[i]即从高位的第i个数字
		if(i!=0){
		 	printf(" "); 
		}else{
			printf("\n");	// 最后一次循环换行 
		}
	}
	return 0;
} 
