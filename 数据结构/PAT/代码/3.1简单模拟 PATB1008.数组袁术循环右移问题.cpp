#include<cstdio>
const int maxn = 110;
int main(){
	int a[maxn];
	int n,m,count=0;	// count �Ǽ������Ԫ�ظ���,�����Ԫ�ظ���С��nʱ,���Ԫ�غ���ӿո� 
	scanf("%d%d",&n,&m);
	m = m%n;	// ��m>nʱ,����m 
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	if(m==0){
		for(int i = 0;i<n;i++){
			printf("%d",a[i]);
			count++;
			if(count<n){
				printf(" ");
			}
		}
	}else{
		for(int i = n-m;i<n;i++){	// ֱ����� n-m~n-1 
			printf("%d",a[i]);
			count++;
			if(count<n){
				printf(" ");
			}
		}
		for(int i=0;i<n-m;i++){		// ֱ����� 0~n-m-1
			printf("%d",a[i]);
			count++;
			if(count<n){
				printf(" ");
			}
		}	
	} 
	return 0;
} 
