// PATB 1021.��λ��ͳ�� 
#include<cstdio>
#include<cstring>
int main(){
	char str[1010];	// 1000λ���������ַ�����ȡ
	gets(str);	// ��ȡһ���ַ���
	int len = strlen(str);	// ��ȡ�ַ�������

	int count[10] = {0};	// ��¼����0~9�Ĵ���

	for(int i =0;i<len;i++){
		count[str[i]-'0']++;	// ��str[i]��Ӧ�����ֵ�countֵ+1
	}

	for(int i = 0;i<10;i++){	// ö�����
		if(count[i]!=0){
			printf("%d:%d\n",i,count[i]);
		}
	}
	return 0;
}
