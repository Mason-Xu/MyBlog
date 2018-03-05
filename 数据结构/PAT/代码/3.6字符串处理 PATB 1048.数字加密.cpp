// PATB 1048.数字加密
#include<cstdio>
#include<cstring>
const int maxn = 110;
char A[maxn],B[maxn],ans[maxn]={0};
void reverse(char s[]){	// 反转字符串 
	int len = strlen(s);
	for(int i=0;i<len/2;i++){
		int temp = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = temp;
	}
}
int main(){
	scanf("%s %s",A,B);
	reverse(A);
	reverse(B);
	int lenA = strlen(A);
	int lenB = strlen(B);
	int len = lenA>lenB?lenA:lenB;	// 比较长度大小 
	for(int i = 0;i<len;i++){	// 从低位开始
		int numA = i < lenA?A[i]-'0':0;	// numA对应a[i]
		int numB = i < lenB?B[i]-'0':0;	// numB对应b[i]
		if(i%2==0){	// i为偶数 
			int temp = (numB+numA)%13;	// 和再模上13
			if(temp == 10) ans[i] = 'J';
			else if(temp == 11) ans[i] = 'Q';
			else if(temp == 12) ans[i] = 'k';
			else ans[i] = temp+'0';	//0~9 
		} else{	// 当前位i是奇数
			int temp = numB - numA;	// 差
			if(temp<0)	temp += 10;	// 如果小于0，则加上10 
			ans[i] = temp+'0';	// 赋对应的字符 
		}
	}
	reverse(ans);
	puts(ans);
	return 0; 
}
