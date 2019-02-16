#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1050;
int array[maxn];
int count1 = 0;
int n;

void InOrder(int index){
  if( index > n) return;
  InOrder(index*2);

  InOrder(index*2 +1);
}

int main(){
  cin >>n;
  for(int i=0;i<n;i++){
    cin>>array[i];
  }
  sort(array,array+n);
  InOrder(1);
  return 0;}
