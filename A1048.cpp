#include<iostream>
#include<algorithm>
using namespace std;

int cmp(int a,int b){
  return a <b;
}

//二分查找法
int array[100050];
int main(){
  int N,M,temp;
  scanf("%d %d",&N,&M);
  int count=0;
  for(int i=0;i<N;i++){
    scanf("%d",&temp);
    if(temp<M){
    	array[count++] = temp;
	}
  }
  sort(array,array+count,cmp);
  
//  cout<<"--------" <<endl;
//  cout<<count<<endl;
//  
  int i =0 ;
  int j =count-1;
  while(i<j){
    if(array[i]+array[j] < M){
      i++;
    }
    else if((array[i]+ array[j])>M){
      j--;
    }
    else if(array[i] + array[j] == M){
      cout<<array[i]<<" "<<array[j];
      return 0;
    }
  }
  
  if(i>=j){
    cout<<"No Solution";
  }
  return 0;
}
