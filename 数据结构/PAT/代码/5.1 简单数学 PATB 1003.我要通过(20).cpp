// PATB 1003.��Ҫͨ��(20) 
#include<cstdio>
#include<cstring>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char str[100];
		scanf("%s",str);	// �����ַ���
		int len = strlen(str);
		// �ֱ����P�ĸ���,T�ĸ���,��PAT���ַ��ĸ���
		int num_p = 0,num_t = 0,other = 0;
		int loc_p = -1,loc_t = -1;	// �ֱ����P��λ��,T��λ��
		for(int i = 0;i<len;i++){
			if(str[i] == 'P'){	// ����ǰ�ַ���P,��P�ĸ���+1,λ�ñ�i 
				num_p++;
				loc_p = i; 
			}else if(str[i] == 'T'){	// ����ǰ�ַ�ΪT,��T�ĸ���+1,λ�ñ�i 
				num_t++;
				loc_t = i;
			} else if(str[i]!='A') other++;	// �������PAT,other++; 
		} 
		// ���num_p��Ϊ1,����num_t
		// ���ߴ��������ַ�,����PT֮��û���ַ� 
		if(num_p!=1||num_t!=1||other!=0||loc_t-loc_p<=1){
			printf("NO\n");
			continue;	// �������ѭ�� 
		} 
		// xyz���������ҵ�A������,����ͨ��loc_p,loc_t�õ�
		int x = loc_p,y = loc_t-loc_p-1,z = len-loc_t-1;
		if(z-x*(y-1)==x){
			printf("YES\n");
		} else{
			printf("NO\n");
		}
	} 
	return 0;
}
