#include<iostream>
#include<cstring>

//The first one who bets on a unique number wins.

// 首先是确定哪些数字是不独特的，进而确定哪些数字是独特的

using namespace std;
//不一定要用int，可以用short或者是更小的东西
int num[100100]; 
int bets[10010];

int main(){
  int n,temp,cts = 0;
  //首先将所有的东西假设为是独特的
  memset(bets,0,sizeof(bets));
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&temp);
    bets[temp]++;
    num[i] = temp;
  }
  
  int flag = 0;
  for(int i=0 ; i<n ; i++){
    if(bets[num[i]] == 1){
      printf("%d",num[i]);
      flag =1;
      return 0;
    }
    else{
    	continue;
	}
  }
  
  
  if(flag == 0){
  	printf("None");
  }
  return 0;
}

