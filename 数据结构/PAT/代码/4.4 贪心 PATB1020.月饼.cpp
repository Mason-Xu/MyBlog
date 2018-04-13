// PATB1020.月饼
#include<cstdio>
#include<algorithm>
using namespace std;
struct mooncake{
	double store;	// 库存 
	double price;	// 单价 
	double sell;	//总售价 
}cake[1010];
bool cmp(mooncake a,mooncake b){	// 按单价从高到低排序 
	return  a.price>b.price;
} 
int main(){
	int n;
	double D;
	scanf("%d%lf",&n,&D);
	for(int i = 0;i < n;i++){
		scanf("%lf",&cake[i].store);
	} 
	for(int i = 0;i < n;i++){
		scanf("%lf",&cake[i].sell);
		cake[i].price = cake[i].sell/cake[i].store;	// 计算单价 
	} 
	sort(cake,cake+n,cmp);
	double ans = 0; 	// 收益
	for(int i = 0;i<n;i++){
		if(cake[i].store<=D){	// 如果需求量高于月饼库存 
			D -= cake[i].store;
			ans += cake[i].sell;
		}else{	// 月饼库存大于需求量 
			ans += cake[i].price*D;
			break;
		}
	} 
	printf("%.2f\n",ans);
	return 0;
} 
