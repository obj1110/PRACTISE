#include<iostream>
using namespace std;

// galleon 10的7次方 最大
// sickle 16最大
// knut  28最大  

int main(){
  //像是这种sum都是需要首先赋值为0的
  int a1,b1,c1,a2,b2,c2;
  
  scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
  
  c1 += c2;
  b1 += b2;
  a1 += a2;
  
  
  if(c1 >=29){
  	b1 += c1/29;
  	c1 = c1%29;
  }
  
  if(b1 >=17){
  	a1 += b1/17;
  	b1 = b1%17;
  }
  
  printf("%ld.%ld.%ld",a1,b1,c1);
  return 0;
}

