#include<iostream>
#include<cstring>

//The first one who bets on a unique number wins.

// ������ȷ����Щ�����ǲ����صģ�����ȷ����Щ�����Ƕ��ص�

using namespace std;
//��һ��Ҫ��int��������short�����Ǹ�С�Ķ���
int num[100100]; 
int bets[10010];

int main(){
  int n,temp,cts = 0;
  //���Ƚ����еĶ�������Ϊ�Ƕ��ص�
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

