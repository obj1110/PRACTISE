#include<iostream>
using namespace std;

// galleon 10��7�η� ���
// sickle 16���
// knut  28���  

int main(){
  //��������sum������Ҫ���ȸ�ֵΪ0��
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

