// PATB 1031. 查验身份证(15)
#include<cstdio>
#include<cstring>
// 权重
int w[20] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
// 校验码
char change[15] = {'1','0','X','9','8','7','6','5','4','3','2'};

int main() {
	int n;
	scanf("%d",&n);
	bool flag = true;	// 记录是否所有身份证都是正确的,若均正确,则flag=true
	char str[20];
	for(int i = 0; i<n; i++) {
		scanf("%s",str);
		int j,last = 0;	// last 记录前17位的加权和
		for(j=0; j<17; j++) {
			if(!(str[j] >= '0' && str[j] <= '9')) break;	// 非数字
			last = last + (str[j]-'0') * w[j];
		}
		if(j<17) {	// 有非数字的存在
			flag = false;	// 存在身份证号错误
			printf("%s\n",str);
		} else {
			if(change[last%11]!=str[17]) {	// 校验码不等于最后一位
				flag = false;
				printf("%s\n",str);
			}
		}
	}
	if(flag == true) {
		printf("All passed\n");
	}
	return 0;
}
