// PATB 1082. ������� (20)
#include<cstdio>
#include<algorithm>
const int maxn = 10010;
using namespace std;
struct shoot{
	int id;		// id 
	int x,y;	// ���� 
	int L;	// xƽ����yƽ�� 
}athlete[maxn]; 
bool cmp(shoot a,shoot b){	// �������� 
	return a.L<b.L;			// ԽС�ľ���Խ�� 
}
int main(){
	int n;
	scanf("%d",&n); 
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&athlete[i].id,&athlete[i].x,&athlete[i].y);
		athlete[i].L = athlete[i].x * athlete[i].x + athlete[i].y * athlete[i].y;
	}
	sort(athlete,athlete+n,cmp);
	printf("%04d %04d\n",athlete[0].id,athlete[n-1].id);
	return 0;
}
