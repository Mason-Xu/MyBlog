// PATB 1003.我要通过(20) 
#include<cstdio>
#include<cstring>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char str[100];
		scanf("%s",str);	// 输入字符串
		int len = strlen(str);
		// 分别代表P的个数,T的个数,除PAT外字符的个数
		int num_p = 0,num_t = 0,other = 0;
		int loc_p = -1,loc_t = -1;	// 分别代表P的位置,T的位置
		for(int i = 0;i<len;i++){
			if(str[i] == 'P'){	// 若当前字符是P,则P的个数+1,位置变i 
				num_p++;
				loc_p = i; 
			}else if(str[i] == 'T'){	// 若当前字符为T,则T的个数+1,位置变i 
				num_t++;
				loc_t = i;
			} else if(str[i]!='A') other++;	// 如果不是PAT,other++; 
		} 
		// 如果num_p不为1,或者num_t
		// 或者存在其他字符,或者PT之间没有字符 
		if(num_p!=1||num_t!=1||other!=0||loc_t-loc_p<=1){
			printf("NO\n");
			continue;	// 跳过这个循环 
		} 
		// xyz代表左中右的A的数量,可以通过loc_p,loc_t得到
		int x = loc_p,y = loc_t-loc_p-1,z = len-loc_t-1;
		if(z-x*(y-1)==x){
			printf("YES\n");
		} else{
			printf("NO\n");
		}
	} 
	return 0;
}
