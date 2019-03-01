#include<iostream>
using namespace std;
float coffin[1010];
int main(){
	for(int i=0;i<m;i++){
		coffin[i] = 0;
	}
	int m,temp;
	float num;
	for(int j=0;j<2;j++){
		scanf("%d",m);
		for(int i=0;i<m;i++){
			scanf("%d %f",&m,&temp);
			coffin[m] += temp;
		}	
	}
	int item = 0;
	for(int i=0;i<1010;i++){
		if(coffin[i]!=0){
			item++; 
		}
	}
	
	printf("%d",item);
	for(int i=1010;i>=0;i--){
		if(coffin[i]!=0){
			printf(" ");
			prinf("%d %0.1f",i,coffin[i]);
		}
	}
}
