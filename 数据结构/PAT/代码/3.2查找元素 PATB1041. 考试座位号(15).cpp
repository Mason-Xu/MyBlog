// PATB 1041. 考试座位号(15)
#include<cstdio>
const int maxn  = 1010;
// 结构体
struct Student{
	long long id;	// 准考证号 
	int examSeat;	// 考试座位号 
}testSeat[maxn];	//  试机座位号作为下标来记录考生
int main(){
	int n,m,seat,examSeat;
	long long id;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%lld%d%d",&id,&seat,&examSeat);
		testSeat[seat].id = id;	//	试机座位号为seat学生的准考证号 
		testSeat[seat].examSeat = examSeat;	// 试机座位号为seat的考生的考试座位号 
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
