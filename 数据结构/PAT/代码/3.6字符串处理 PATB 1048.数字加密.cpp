// PATB 1048.���ּ���
#include<cstdio>
#include<cstring>
const int maxn = 110;
char A[maxn],B[maxn],ans[maxn]={0};
void reverse(char s[]){	// ��ת�ַ��� 
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
	int len = lenA>lenB?lenA:lenB;	// �Ƚϳ��ȴ�С 
	for(int i = 0;i<len;i++){	// �ӵ�λ��ʼ
		int numA = i < lenA?A[i]-'0':0;	// numA��Ӧa[i]
		int numB = i < lenB?B[i]-'0':0;	// numB��Ӧb[i]
		if(i%2==0){	// iΪż�� 
			int temp = (numB+numA)%13;	// ����ģ��13
			if(temp == 10) ans[i] = 'J';
			else if(temp == 11) ans[i] = 'Q';
			else if(temp == 12) ans[i] = 'k';
			else ans[i] = temp+'0';	//0~9 
		} else{	// ��ǰλi������
			int temp = numB - numA;	// ��
			if(temp<0)	temp += 10;	// ���С��0�������10 
			ans[i] = temp+'0';	// ����Ӧ���ַ� 
		}
	}
	reverse(ans);
	puts(ans);
	return 0; 
}
