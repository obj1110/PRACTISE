#include<iostream>
using namespace std;
int numbers[10]= {0,0,0,0,0,0,0,0,0,0};

int main(){
  for(int i=0;i<10;i++){
  	scanf("%d",&numbers[i]);
  }
  
  int init =0;
  
  for(int i=1;i<10;i++){
  	if(numbers[i]!=0){
  		init = i;
  		numbers[i] = numbers[i] -1;
  		break;
	  }
  }
  
  printf("%d",init);
  
  
  for(int i=0;i<10;i++){
  	for(int j=0;j<numbers[i];j++){
  		printf("%d",i);
	  }
  }
  
  
  return 0;
}
