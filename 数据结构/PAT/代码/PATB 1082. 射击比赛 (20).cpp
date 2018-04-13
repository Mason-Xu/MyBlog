// PATB 1082. 射击比赛 (20)
#include<cstdio>
#include<algorithm>
const int maxn = 10010;
using namespace std;
struct shoot{
	int id;		// id 
	int x,y;	// 坐标 
	int L;	// x平方加y平方 
}athlete[maxn]; 
bool cmp(shoot a,shoot b){	// 排升序序 
	return a.L<b.L;			// 越小的距离越近 
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
