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
    //���ص��ǵ�һ���������ֵ��Ԫ�ص�ָ�������λ��
    //lower_bound���ص��ǵ�һ��С�ڵ������ֵ��Ԫ�ص�ָ��
    int j = upper_bound(array+i+1  , array+n ,  (long long)array[i]*p ) - array;
    cts = max(cts,j-i);
  }
  printf("%d\n",cts);
  return 0;
}
