#include<iostream>
using namespace std;

int ite[100100]={0};
const int SIZE = 100100;
int main(){
  int num,a,b,max_id,max_sum=-1;
  
  scanf("%d",&num);
  for(int i=0;i<num;i++){
    scanf("%d %d",&a,&b);
    ite[a] += b;
    if(max_sum < ite[a]){
      max_id = a;
      max_sum = ite[a];
    }
  }
  printf("\n-------------\n"); 
  printf("%d %d",max_id,max_sum);
  return 0;
}
