#include<cstdio>
void swap(int* &p1,int* &p2){
	int* temp = p1;
	p1 = p2;
	p2 = temp;
}
int main(){
	int a = 1, b = 2;
	int *p1 = &a, *p2 = &b;
	swap(p1,p2);
	printf("a = %d,b = %d\n",*p1, *p2);
	return 0;
} 
