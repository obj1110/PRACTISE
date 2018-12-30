#include<iostream>
using namespace std;

int main(){
  float a,b,c;
  float ite[3] ={0.0,0.0,0.0};
  for(int i=0;i<3;i++){
    scanf("%f %f %f",&a,&b,&c);  
    if(a>b && a>c){
      printf("L ");
      ite[i] =a;
      continue;
    }
    else if(b>a && b>c){
      printf("T ");
      ite[i] =b;
      continue;
    }
    else if(c>a && c>b){
      printf("W ");
      ite[i] =c;
      continue;
    }
  }
  
  float sum = 2*(ite[0]*ite[1]*ite[2]*0.65-1);
  printf("%0.2f",sum);
  return 0;
}
