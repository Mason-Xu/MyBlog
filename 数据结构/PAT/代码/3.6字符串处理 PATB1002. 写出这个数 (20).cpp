// PATB1002. д������� (20)
#include<cstdio>
#include<cstring>
int main(){
	char str[110]; 
	gets(str);
	int sum =0;
	int len = strlen(str);	// ��ȡ�ַ������� 
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
		printf("%s",change[ans[i]]);	// ans[i]���Ӹ�λ�ĵ�i������
		if(i!=0){
		 	printf(" "); 
		}else{
			printf("\n");	// ���һ��ѭ������ 
		}
	}
	return 0;
} 
