#include<iostream>
using namespace std;
int main(){
	int index[1010]={0};
	int a,b,cts;
	while(scanf("%d%d",&a,&b)==EOF){
		index[b] = a;
	}
	for(int i=0;i<1000;i++){
		index[i] = index[i+1]*(i+1);
	}
	index[1000] = 0;
	for(int i=0;i<1000;i++){
		if(index[i]!=0){
			printf("%d %d",index[i],i);
		}
	}	

	return 0;
}
