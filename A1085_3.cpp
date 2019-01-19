#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100100;
int main(){
  int n,p,array[maxn];
  scanf("%d %d",&n,&p);
  for(int i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  int cts = -1;
  sort(array,array+n);
  for(int i=0;i<n;i++){
    //返回的是第一个大于这个值的元素的指针而不是位置
    //lower_bound返回的是第一个小于等于这个值的元素的指针
    int j = upper_bound(array+i+1  , array+n ,  (long long)array[i]*p ) - array;
    cts = max(cts,j-i);
  }
  printf("%d\n",cts);
  return 0;
}
