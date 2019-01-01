#include<iostream>
#include<cstring>

using namespace std;
int main(){
  char index[90];
  char ans[40][40]={};
  ///直接读取字符数组 
  cin>>index;
  int cts = strlen(index);
  
  int n1,n2,n3;
  for(n2=1;n2<cts;n2++){
  	//这个偶数条件也是非常重要的，不可忽视的	 
  	if((cts+2-n2)%2 == 0){
  	     n1 = n3 = (cts+2-n2)/2;	
  	     //就是说你n2一开始是比n1要小很多的，然后不满足n2>=n1的情况，然后就是不断的增加n2直到大于n1的时候 
  	    if(n2 >=n1)  break;
    }
  }
  //到这里已经获取了n1,n2,n3
  int pct =0;
  for(int i=0;i<n1;i++,pct++){
  	ans[i][0] = index[pct];
  }
  for(int i=1;i<n2;i++,pct++){
  	ans[n1-1][i] = index[pct];
  }
  for(int i=2;i<=n3;i++,pct++){
  	ans[n3-i][n2-1] = index[pct];
  }
  
  for(int i=0;i<n1;i++){
  	for(int j=0;j<n2;j++){
  		printf("%c",ans[i][j]);
	  }
	  printf("\n");
  }
  return 0;
} 
