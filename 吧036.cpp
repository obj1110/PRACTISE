#include<iostream>
using namespace std;
int main(){
  int n;
  char a;
  scanf("%d %c",&n,&a);
  int row =(n+1)/2;
  
    if(i==0){
      for(int i=0;i<n-1;i++){
        printf("%c",a);
      }
      printf("%c\n",a);
    }
    for(int i=1;i<row-1;i++){
      printf("%c",a);
      for(int i=1;i<n-1;i++){
        printf(" ");
      }
      printf("%c\n",a);
    }
    
    if(i==row-1){
      for(int i=0;i<n;i++){
        printf("%c",a);
      }
    }
  return 0;
}
