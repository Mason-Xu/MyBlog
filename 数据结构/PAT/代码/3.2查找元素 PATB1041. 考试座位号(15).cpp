// PATB 1041. ������λ��(15)
#include<cstdio>
const int maxn  = 1010;
// �ṹ��
struct Student{
	long long id;	// ׼��֤�� 
	int examSeat;	// ������λ�� 
}testSeat[maxn];	//  �Ի���λ����Ϊ�±�����¼����
int main(){
	int n,m,seat,examSeat;
	long long id;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%lld%d%d",&id,&seat,&examSeat);
		testSeat[seat].id = id;	//	�Ի���λ��Ϊseatѧ����׼��֤�� 
		testSeat[seat].examSeat = examSeat;	// �Ի���λ��Ϊseat�Ŀ����Ŀ�����λ�� 
	}
	scanf("%d",&m);
	for(int i = 0;i<m;i++){
		scanf("%d",&seat);
		printf("%lld %d\n",testSeat[seat].id,testSeat[seat].examSeat);
	} 
	return 0;
} 
//int main(){
//	long long a[maxn][3];
//	int n,m;
//	scanf("%d",&n);
//	for(int i = 0;i<n;i++){
//		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
//	}
//	scanf("%d",&m);
//	int b[m];
//	for(int j = 0;j<m;j++){
//		scanf("%d",&b[j]);
//	}
//	for(int j=0;j<m;j++){
//		for(int i = 0;i<n;i++){
//			if(b[j]==a[i][1]){
//				printf("%lld %lld\n",a[i][0],a[i][2]);
//			}
//		}
//	}
//	return 0;
//} 
