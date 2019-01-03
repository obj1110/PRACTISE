#include<iostream>
#include<algorithm>
#include<cstring>
#include <stdlib.h> 

using namespace std;
int main(){
  long n;
  scanf("%ld",&n);
  int cts =0;
  int index = 1;
  string temp;
  while(index<=n){
    temp = to_string(index);
    for(int i=0;i<temp.length();i++){
      if(temp[i] == '1') cts++;
    }
    index++;
  }
  cout<<cts;
  return 0;
}
