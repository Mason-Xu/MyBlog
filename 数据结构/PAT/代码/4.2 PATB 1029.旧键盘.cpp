// PATB 1029.�ɼ��� 
#include<cstdio>
#include<cstring>
int main(){
	char str1[100],str2[100];
	bool HashTable[128] = {false};	// hashTable������������ַ��Ƿ��Ѿ������
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i=0;i<len1;i++){	// ö�ٵ�һ���ַ�����ÿһ���ַ� 
		int j;
		char c1,c2;
		for(j=0;j<len2;j++){	// ö�ٵڶ����ַ����е�ÿ���ַ� 
			c1 = str1[i];
			c2 = str2[j];
			if(c1>='a'&&c1<='z') c1 -= 32;	// �����Сд��,��ת���ɴ�д��ĸ 
			if(c2>='a'&&c2<='z') c2 -= 32;	
			if(c1==c2) break;	// ���c1�ڵڶ����ַ����г���,������ 
		} 
		if(j == len2 && HashTable[c1] == false){
			printf("%c",c1);	// �ڵڶ����ַ�����δ���ֵ�c1,��c1δ�������
			HashTable[c1] = true; 
		} 
	} 
	return 0;
}
