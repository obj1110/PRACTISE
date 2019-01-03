#include<iostream>
#include<algorithm>
using namespace std;

int array[200010];

int cmp(int a,int b){
  if(a!= b) return a<b;
}

int main(){
  int n,m;
  int temp;
  
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  
  scanf("%d",&m);
  for(i=n;i<n+m;i++){
    scanf("%d",&array[i]);
  }
  
  sort(array,array+m+n,cmp);
  
  if((m+n)%2==0){
    cout<<array[(m+n)/2] + array[(m+n)/2-1];
  }
  else if((m+n)%2==1){
    cout<<array[(m+n-1)/2];
  }
  
  return 0;
}
