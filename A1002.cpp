#include<iostream> 
using namespace std;

const int SIZE = 1010;

int main(){
	int K,cts=0;
	int a;
	double b;
	double index[1010]={0.0};
	
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d %lf",&a,&b);
		index[a] += b;
	}
	
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d %lf",&a,&b);
		index[a] += b;
	}
	
	for(int i=0;i<=1000;i++){
		if(index[i]!=0) cts++;
	}
	
	printf("---------------1---------\n");
	
	printf("%d",cts);
	if(cts>0){
		printf(" ");
		for(int i=1000;i>=0;i--){
			if(index[i]!=0){
				printf("%d %0.1f",i,index[i]);
				cts--;
				if(cts>0){
					printf(" ");
					}
				}
			}
		} 
	return 0;
}
