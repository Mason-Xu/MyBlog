// PATB 1019. 数字黑洞 (20)
#include<cstdio>
#include<algorithm> 
using namespace std;
bool cmp(int a,int b){	// 递减cmp 
	return a>b;
}
void to_array(int n,int num[]){	// 将n的每一位存到num数组中,不用在意顺序因为要重新排序 
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
	int n,min,max;	// min和max代表递增递减后的的最小值和最大值
	scanf("%d",&n);
	int num[5];
	while(1){
		to_array(n,num);	// 将n转换成数组 
		sort(num,num+4);	// 对num数组中元素从小到大排序 
		min = to_number(num);	// 获取最小值
		sort(num,num+4,cmp);	// 递减排序
		max = to_number(num);
		n = max-min;	// 得到下一个数
		printf("%04d - %04d = %04d\n",max,min,n);
		if(n == 0||n==6174) break;	// 下一个数如果是0或者6174,退出 
	} 
	return 0; 
}
