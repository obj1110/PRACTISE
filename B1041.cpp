#include<iostream>
using namespace std;
const int SIZE = 1010;

int main(){
  int num,a,b;
  long long c;
  scanf("%d",&num);
  long long ind1[SIZE]={0};
  int ind2[SIZE]={0};
  for(int i=0;i<num;i++){
    scanf("%lld %d %d",&c,&a,&b);
    ind1[a] = c;
    ind2[a] = b;
  }
  scanf("%d",&num);
  for(int i=num;i>=0;i--){
    scanf("%d",&a);
    printf("%lld %d\n",ind1[a],ind2[a]);
  }
  return 0;
}
