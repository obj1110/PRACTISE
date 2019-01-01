#include<iostream>
using namespace std;
int main(){
  int pt = 0;
  int at = 0;
  int a,b,c;
  scanf("%d.%d.%d",&a,&b,&c);
  pt = a*29*17 + b*29 +c;
  scanf("%d.%d.%d",&a,&b,&c);
  at = a*29*17 + b*29 +c;
  int sum = 0;
  if(pt>at){
      printf("-");
      sum =pt -at;
      a = sum/(29*17);
      b = sum%(29*17)/29;
      c = sum%29;
      printf("%d.%d.%d",a,b,c);
  }
  else if(pt<at){
      sum = at-pt;
      a = sum/(29*17);
      b = sum%(29*17)/29;
      c = sum%29;
      printf("%d.%d.%d",a,b,c);
  }
  else if(pt == at){
    printf("0.0.0");
  }
  return 0;
}

