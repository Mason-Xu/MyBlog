// PATB 1004. 成绩排名 (20)
#include<cstdio>
struct Student{
	char name[15];
	char id[15];	// 字符数组末尾 \0 不能是10 ，要比10大 
	int score; 
}temp,ans_min,ans_max;	// temp存放临时数据，ans_max放最大，ans_min放最小 
int main(){
	int n;
	scanf("%d",&n);
	ans_min.score = 101; 
	ans_max.score = -1; 
	for(int i=0;i<n;i++){
		scanf("%s%s%d",&temp.name,&temp.id,&temp.score);	// 获取数据 
		if(temp.score>ans_max.score) ans_max = temp;
		if(temp.score<ans_min.score) ans_min = temp;
	}
	printf("%s %s\n",ans_max.name,ans_max.id);
	printf("%s %s\n",ans_min.name,ans_min.id);
	return 0;
} 
