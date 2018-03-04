// PATB1028. 人口普查(20)
#include<cstdio>
struct person{
	char name[10];	// 姓名
	int yy,mm,dd;	// 日期 
}oldest,youngest,left,right,temp;	// 最年长，最年轻，左边界，右边界，临时

bool LessEqu(person a,person b){	// 如果a的日期小于b，返回true 
	if(a.yy!=b.yy){
		return a.yy<=b.yy;
	}else if(a.mm!=b.mm){
		return a.mm<=b.mm;
	}else{
		return a.dd<=b.dd; 
	} 
}
bool MoreEqu(person a,person b){	// 如果a的日期大于b，返回true 
	if(a.yy!=b.yy){
		return a.yy>=b.yy;
	}else if(a.mm!=b.mm){
		return a.mm>=b.mm;
	}else{
		return a.dd>=b.dd; 
	} 
}
// youngest与left为1814年9月6日，oldest和right是2014.9.6
void init(){
	youngest.yy = left.yy=1814;
	oldest.yy = right.yy = 2014;
	youngest.mm = left.mm = oldest.mm = right.mm = 9;
	youngest.dd = left.dd = oldest.dd = right.dd = 6; 
} 
int main(){
	init();
	int n,num=0;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%s %d/%d/%d",temp.name,&temp.yy,&temp.mm,&temp.dd);
		if(MoreEqu(temp,left)&&LessEqu(temp,right)){	//日期合法 
			num++;
			if(LessEqu(temp,oldest)) oldest = temp;	// 更新oldest
			if(MoreEqu(temp,youngest)) youngest = temp;	//更新youngest 
		}
	} 
	if(num==0){	//所有人的日期都不合法,只输出0，没有空格 
			printf("0\n");
		}else{
			printf("%d %s %s\n",num,oldest.name,youngest.name); 
		}
	return 0;
} 
