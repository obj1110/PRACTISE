#include<iostream> 
using namespace std;
int main(){
	int cts = 0;
	char array[10000];
	while(scanf("%s",&array)!=EOF){
		cts++;
	}
	printf("�ļ�����Ϊ:%d",cts/3);
}
