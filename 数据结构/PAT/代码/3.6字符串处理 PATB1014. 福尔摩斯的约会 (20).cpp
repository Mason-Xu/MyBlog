// PATB1014. ����Ħ˹��Լ�� (20)
#include<cstdio>
#include<cstring>
int main(){
	char week[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char str1[70],str2[70],str3[70],str4[670];
	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	int i;
	for(i=0;i<len1&&i<len2;i++){
		if(str1[i] == str2[i] && str1[i]>='A'&&str2[i]<='G'){
			printf("%s ",week[str1[i]-'A']);
			break;
		}
	}
	// i������,������Ļ����ϲ��ҵڶ�����ȵ�Ӣ����ĸ������
	for(i++;i<len1&&i<len2;i++){
		if(str1[i]==str2[i]){
			if(str1[i]>='0'&&str1[i]<='9'){
				printf("%02d:",str1[i]-'0');	// �������
				break; 
			} else if(str1[i]>='A'&&str1[i]<='N'){
				printf("%02d:",str1[i]-'A'+10);
				break;
			}
		}
	} 
	
	for(int j = 0;j<len3&&j<len4;j++){
		if(str3[j]==str4[j]){
			if(str3[j]>='A'&&str3[j]<='Z'||str3[j]>='a'&&str3[j]<='z'){
				printf("%02d",j);
			}
			
		}
	}
	return 0;
}
