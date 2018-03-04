#include<cstdio>
const int CLK_TCK = 100;
int main(){
	int C1,C2,time;
	int hh,mm,ss;
	scanf("%d%d",&C1,&C2);
	time = C2-C1;
	if(time%100>=50){	// 四舍五入操作 
		time = time/CLK_TCK+1;
	}else{
		time = time/CLK_TCK;
	}
	ss = time % 60;
	mm = time /60 % 60;
	hh = time / 3600;
	printf("%02d:%02d:%02d\n",hh,mm,ss);
	return 0;
}
