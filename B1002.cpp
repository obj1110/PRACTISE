#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

string rule[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
  char index[120];
  cin>>index;
  int length = strlen(index);
  int sum=0;
  for(int i=0;i<length;i++){
  	sum += index[i] - '0';
  }
  
  
  int count =0;
  vector<int> number;
  
  while(sum>0){
	number.push_back(sum%10);
	sum = sum/10;
  }
  int length_2 = number.size();
  for(int i=length_2-1 ;i>=0;i--){
  	cout<<rule[number[i]];
  	if(i!=0) cout<<" ";
  }

}
