// PATB 1019. ���ֺڶ� (20)
#include<cstdio>
#include<algorithm> 
using namespace std;
bool cmp(int a,int b){	// �ݼ�cmp 
	return a>b;
}
void to_array(int n,int num[]){	// ��n��ÿһλ�浽num������,��������˳����ΪҪ�������� 
	for(int i = 0;i<4;i++){
		num[i] = n%10;
		n/=10;
	} 
}
int to_number(int num[]){
	int sum = 0;
	for(int  i = 0;i<4;i++){
		sum = sum*10+num[i];
	}
	return sum;
}
int main(){
	int n,min,max;	// min��max��������ݼ���ĵ���Сֵ�����ֵ
	scanf("%d",&n);
	int num[5];
	while(1){
		to_array(n,num);	// ��nת�������� 
		sort(num,num+4);	// ��num������Ԫ�ش�С�������� 
		min = to_number(num);	// ��ȡ��Сֵ
		sort(num,num+4,cmp);	// �ݼ�����
		max = to_number(num);
		n = max-min;	// �õ���һ����
		printf("%04d - %04d = %04d\n",max,min,n);
		if(n == 0||n==6174) break;	// ��һ���������0����6174,�˳� 
	} 
	return 0; 
}
