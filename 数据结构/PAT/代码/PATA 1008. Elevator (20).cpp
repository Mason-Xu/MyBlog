// PATA 1008. Elevator (20)
//#include <iostream>
//using namespace std;
//int main() {
//    int a, now = 0, sum = 0;
//    cin >> a;
//    while(cin >> a) {
//        if(a > now)
//            sum = sum + 6 * (a - now);
//        else
//            sum = sum + 4 * (now - a);
//        now = a;
//        sum += 5;
//    }
//    cout << sum;
//    return 0;
//}
#include<cstdio>
int main(){
	int n,a,now = 0,sum = 0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(a>now){
			sum += 6*(a-now);
		}else{
			sum += 4*(now-a);
		}
		sum+=5;
		now = a;
	}
	printf("%d\n",sum);
	return 0;
	
} 
