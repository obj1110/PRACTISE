#include<iostream>
using namespace std;

const int N =54;
char mp[5] = {'S','H','C','D','J'};


int main(){
  int K;
  scanf("%d",&K);
  int start[N+1],end[N+1],rule[N+1];
  for(int i=1;i<=N;i++){
    start[i] = i;
    scanf("%d",&rule[i]);
  }
  for(int i=0;i<K;i++){
    for(int j=1;j<=N;j++){
      end[j] = start[rule[j]];
    }
    for(int i=1;i<=N;i++){
      start[i] = end[i];
    }
  }
  
  //ִ�д�ӡ����
  for(int i=1;i<=N;i++){
    if(i!=1) printf(" ");
    start[i]--;//���ڴ���13�ı������⣬֮�������ٰ������ȥ��1���ϡ� 
    printf("%c%d",mp[start[i]/13],start[i]%13 + 1);
  }
  return 0;
}
