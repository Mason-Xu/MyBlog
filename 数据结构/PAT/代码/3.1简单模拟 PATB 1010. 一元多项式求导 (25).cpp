// PATB 1010. һԪ����ʽ�� (25) 
#include<cstdio>
const int  maxn =1010;
int main(){
	int a[maxn] = {0};
	int k,e,count = 0;	// kΪϵ����eΪָ����count������Ϊ0�ĵ��������
	while(scanf("%d%d",&k,&e)!=EOF){
		a[e] = k;	// a���������洢ϵ�� 
	} 
	a[0] = 0;	// �������֮��ֱ��Ϊ0
	for(int i =1;i<=1000;i++){
		a[i-1] = a[i]*i;	// �󵼹�ʽ������ǰ��
		a[i] = 0; // �˾䲻����ʡ
		if(a[i-1]!=0) count++;	//������Ϊ0�ĵ�������� 
	} 
	if(count==0) printf("0 0");	//����
	else{
		for(int i = 1000;i>=0;i--){	// ָ���ݽ� 
			if(a[i]!=0){
				printf("%d %d",a[i],i);
				count--;
				if(count!=0) printf(" ");
			}
		}
	} 
	return 0;
} 
