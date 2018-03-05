// PATB 1021.个位数统计 
#include<cstdio>
#include<cstring>
int main(){
	char str[1010];	// 1000位的数字用字符串获取
	gets(str);	// 获取一行字符串
	int len = strlen(str);	// 获取字符串长度

	int count[10] = {0};	// 记录数字0~9的次数

	for(int i =0;i<len;i++){
		count[str[i]-'0']++;	// 将str[i]对应的数字的count值+1
	}

	for(int i = 0;i<10;i++){	// 枚举输出
		if(count[i]!=0){
			printf("%d:%d\n",i,count[i]);
		}
	}
	return 0;
}
