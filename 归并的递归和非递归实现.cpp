#include<iostream> 
#include<algorithm>
#include<vector> 

using namespace std;

void merge(int array[],int length){
	int gap;
	for(gap=1;gap<=length;gap*=2){
		for(int i=0;i<length;i+=gap){
			
			int j = i+2*gap;			
			if(j>length) j = length;
			//sort自己是一个左闭右开的东西 
			sort(array+i,array+j);	
			if (j == length) break;			
		}
		//输出每一步的结果
		cout<<"gap:"<<gap<<endl;
		for(int i=0;i<length;i++){
			printf("%d",array[i]);
			if(i!=length-1) printf(" ");
		}
		printf("\n");
	} 
}

int main(){
	
	int a[20] = {11,0,4,5,1,6,7,2,8,3,9};
	int b[20] = {1,2,3,4,5,6,7,8,9,0,10};
	//直接输出a的情况 
	printf("原始序列\n");
	int length =  sizeof(a)/sizeof(a[0]); 
	for(int i=0; i < length ;i++){
			printf("%d",a[i]);
			if(i!=length-1) printf(" ");
		}
	printf("\n");
		
	merge(a,11);
	getchar();
}
