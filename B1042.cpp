#include<iostream>
#include<cstring>
using namespace std;

const int maxsize = 1000;
char array[maxsize];
int flag[255] = {0};

int main(){
	memset(flag,0,sizeof(flag));
	cin.getline(array,maxsize);
	
	for(int i=0 ; i<= strlen(array) ; i++){
		if(array[i] >='A' && array[i]<='Z'){
			array[i] = array[i] - 'A' +'a';
			flag[array[i]]++;
		}
		else if(array[i] >= 'a' && array[i]<='z'){
			flag[array[i]]++;
		}
	}
	//
//	for(int i=0;i<=255;i++){
//		printf("%d\n",flag[i]);
//	}
	
	//
	int maxindex = 1;
	int tempmax = flag[maxindex];
	for(int i= 1;i<=255;i++){
		if(flag[i] > tempmax){
			maxindex = i;
			tempmax =flag[i];
		}
	}
	printf("%c %d",maxindex,flag[maxindex]);
}
