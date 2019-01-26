#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 200100;
int array[maxn];

//我们需要的一个序列是不减的序列，也就是保持相等或者是上升的一个序列 
int cmp(int a,int b){
  return a <= b;
}

int main(){
  //n和m分别是两个序列的元素个数 
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
  
//  cout<<"----------"<<endl;
//  for(int x = 0;x<(m+n);x++) {
//  	printf("%d ",array[x]);
//  }
//  cout<<"----------"<<endl;
  
  if((m+n)%2==0){
    cout<<array[(m+n)/2-1];
  }
  else if((m+n)%2==1){
    cout<<array[(m+n-1)/2];
  }
  
  return 0;
}
