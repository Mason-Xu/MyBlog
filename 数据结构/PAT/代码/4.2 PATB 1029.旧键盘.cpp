// PATB 1029.旧键盘 
#include<cstdio>
#include<cstring>
int main(){
	char str1[100],str2[100];
	bool HashTable[128] = {false};	// hashTable数组用来标记字符是否已经被输出
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i=0;i<len1;i++){	// 枚举第一个字符串的每一个字符 
		int j;
		char c1,c2;
		for(j=0;j<len2;j++){	// 枚举第二个字符串中的每个字符 
			c1 = str1[i];
			c2 = str2[j];
			if(c1>='a'&&c1<='z') c1 -= 32;	// 如果是小写字,则转换成大写字母 
			if(c2>='a'&&c2<='z') c2 -= 32;	
			if(c1==c2) break;	// 如果c1在第二个字符串中出现,则跳出 
		} 
		if(j == len2 && HashTable[c1] == false){
			printf("%c",c1);	// 在第二个字符串中未出现的c1,且c1未被输出过
			HashTable[c1] = true; 
		} 
	} 
	return 0;
}
