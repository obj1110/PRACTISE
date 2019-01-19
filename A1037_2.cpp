#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int size = 100000;
int product[size];
int coupon[size];


int main(){
  int n,m;
  int profit=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&coupon[i]);
  }
  scanf("%d",&m);
  for(int i=0;i<m;i++){
    scanf("%d",&product[i]);
  }
  sort(product,product+n);
  sort(coupon,coupon+m);
  int i=0;
  int j =0;
  while(i<n && j<m && product[i]<0 && coupon[j]<0){
    profit += product[i]*coupon[j];
  }
  i = n-i;
  j = m-j;
  while(i<n && j<m && product[i]>=0 && coupon[j]>=0){
    profit += product[i]*coupon[j];
  }
  cout<<profit;
  return 0;
}

