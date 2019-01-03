#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
//其实这一点我并不理解啊
int cmp(string a,string b){
  return a+b <b+a;
}

string array[10010];
int main(){
  int n;
  scanf("%d",&n);
  int cts=0;
  for(;cts<n;cts++){
    cin>>array[cts];
  }
  sort(array,array+cts,cmp);
  
  
  string min="0";
  for(int i=0;i<cts;i++){
    min += array[i];
  }
  while(true){
    if(min[0] == '0'  && min.size()> 0) {
      min.erase(0,1);
    }
    else{
      break;
    }
  }
  
  
  cout<<min;
  return 0;
}
