#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	int a[5] = {2,1,4,3,5};
    sort(a,a+3,cmp);
    for(int i=0;i<5;i++){
    	printf("%d ",a[i]);
	}
	return 0;
} 
