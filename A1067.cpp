#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxsize = 100500;
int arr1[maxsize];
int arr2[maxsize];

void swap(int &a,int &b){
  int T = a ;
  a = b;
  b = T;
}

int main(){
  long long cts=0;
  //n是实际的情况
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr1[i]);
    arr2[i] = arr1[i];
  }  
  
  
  sort(arr1,arr1+n);
  for(int i=0;i<n;i++){
    //如果不是正确的位置
    if(arr1[i]!=arr2[i]){
      int j = i+1;
      for(;j<n;j++){
        if(arr2[j] == arr1[i]){
          break;
        }
      }
      swap(arr1[i],arr1[j]);
      cts++;
    }
  }
  cout<<cts;
  return 0;
}
