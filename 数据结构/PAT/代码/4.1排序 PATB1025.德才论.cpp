#include<cstdio>
#include<cstring> 
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Student{
	char id[10];	//准考id 
	int de,cai,sum;
	int flag;	// 考生类别 
}stu[maxn];
bool cmp(Student a,Student b){
	if(a.flag != b.flag) return a.flag<b.flag;	// 类别小的在前
	else if(a.sum != b.sum) return a.sum > b.sum;		// 类别相同时,总分大的在前
	else if(a.de != b.de) return a.de>b.de;	// 总分相同时,德分大的在前 
	else return strcmp(a.id,b.id)<0;	// 德分相同时,准考证小的在前 ,strcmp() 是String的一个函数,比较两个字符串的字典序,如果a<b,返回负数,相等返回0,大于返回正数 
} 
int main(){
	int n,L,H;
	scanf("%d%d%d",&n,&L,&H);
	int m = n;	// m为及格人数 
	for(int i = 0;i<n;i++){
		scanf("%s%d%d",stu[i].id,&stu[i].de,&stu[i].cai);
		stu[i].sum = stu[i].de+stu[i].cai;	// 总分 
		if(stu[i].de<L||stu[i].cai<L){	// 先将不及格者设为第五类 
			stu[i].flag = 5;	
			m--;	// 及格人数-1 
		} else if(stu[i].de>=H&&stu[i].cai>=H){
			stu[i].flag = 1;
		} else if(stu[i].de>=H&&stu[i].cai<H){
			stu[i].flag = 2;
		} else if(stu[i].de>=stu[i].cai){	// 除了以上几种情况,德分大于才分即可 
			stu[i].flag = 3;
		}else{
			stu[i].flag = 4;	 
		}
	}
	
	sort(stu,stu+n,cmp);
	printf("%d\n",m);
	for(int i =0;i<m;i++){
		printf("%s %d %d\n",stu[i].id,stu[i].de,stu[i].cai);
	} 
	return 0;
} 
// 运行超时 
//struct Student{
//	char id[10];
//	int d_score;
//	int c_score;
//	int sum;
//}student[maxn],temp1[maxn],temp2[maxn],temp3[maxn],temp4[maxn];
//bool cmp(Student a,Student b){
//	if(a.sum == b.sum){
//		if(a.d_score!=b.d_score){
//			return a.d_score>b.d_score;
//		}else{
//			return a.id<b.id;
//		}
//	}else{
//		return a.sum > b.sum;
//	}
//	
//}
//int main(){
//	int n,l,h,count=0;
//	int sum[maxn];
//	int s1=0,s2=0,s3=0,s4;
//	bool flag[maxn];
//	scanf("%d%d%d",&n,&l,&h);
//	for(int  i = 0;i < n;i++){
//		scanf("%s%d%d",student[i].id,&student[i].d_score,&student[i].c_score);
//		student[i].sum = student[i].d_score+student[i].c_score;
//		if(student[i].d_score>=l&&student[i].c_score>=l){
//			flag[i] = true;
//			count++;
//			if(student[i].d_score>=h&&student[i].c_score>=h){
//				temp1[s1] = student[i];
//				s1++;
//			}else if(student[i].d_score>h&&student[i].c_score<=h){
//				temp2[s2] = student[i];
//				s2++;
//			}else if(student[i].d_score<h&&student[i].c_score<h&&student[i].d_score>student[i].c_score){
//				temp3[s3] = student[i];
//				s3++;
//			}else{
//				temp4[s4] = student[i];
//				s4++;
//			}
//		}else{
//			flag[i] = false; 
//		}
//	}
//	printf("%d\n",count);
//	
//	sort(temp1,temp1+s1,cmp);
//	sort(temp2,temp2+s2,cmp);
//	sort(temp3,temp3+s3,cmp);
//	sort(temp4,temp4+s4,cmp);
//	
//	for(int  i =0;i<s1;i++){
//		printf("%s %d %d\n",temp1[i].id,temp1[i].d_score,temp1[i].c_score);
//	}
//	for(int  i =0;i<s2;i++){
//		printf("%s %d %d\n",temp2[i].id,temp2[i].d_score,temp2[i].c_score);
//	}
//	for(int  i =0;i<s3;i++){
//		printf("%s %d %d\n",temp3[i].id,temp3[i].d_score,temp3[i].c_score);
//	}
//	for(int  i =0;i<s4;i++){
//		printf("%s %d %d\n",temp4[i].id,temp4[i].d_score,temp4[i].c_score);
//	}	
//	return 0;
//} 
