#include<iostream>
using namespace std;
int main(){
  int base =13;
  char index[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
  //其实本题就是一个进制转化问题
  int x=0;
  int count=0;
  char y[40];
  printf("#");
  
  for(int i=0;i<3;i++){
    count =0;
    scanf("%d",&x);
    
    while(x!=0){
      y[count] = index[x%base];
      x = x/base;
      count++;
    }
    //两种要处理的特例 
    if(count==1){
    	printf("0");
	}
	if(count==0){
		printf("00");
	}
	
	
    for(int i=count-1;i>=0;i--){
      	printf("%c",y[i]);
		}
	}
  return 0;
}
