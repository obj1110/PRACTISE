#include<iostream>
using namespace std;
const int SIZE = 1010;
int main(){
  int K = 0 ;
  int a,cts=0;
  double b ; 
  double inda[SIZE]={0.0};
  double indb[SIZE]={0.0};
  double indc[SIZE]={0.0};
  scanf("%d",&K);
  for(int i=0;i<K;i++){
    scanf("%d %lf",&a,&b);
    inda[a] +=b;
  }
  scanf("%d",&K);
  for(int i=0;i<K;i++){
    scanf("%d %lf",&a,&b);
    indb[a] +=b;
  }
  for(int i=0;i<=1000;i++){
    if(inda[i]!=0){
      for(int j=0;j<=1000;j++){
        if(indb[j]!=0){
          indc[i+j] += inda[i]*indb[j];  
        } 
      }  
    }
  }
  for(int i=0;i<=1000;i++){
    if(indc[i]!=0){
      cts++;
    }
  }
  printf("%d",cts);
  if(cts>0){
    printf(" ");
    for(int i=1000;i>=0;i--){
      if(indc[i]!=0){
        printf("%d %0.1f",i,indc[i]);
        cts--;
		if(cts>0) {
			printf(" ");	
		}
      }
    }
  }
  return 0;
}
