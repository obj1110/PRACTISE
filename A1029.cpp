#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 200100;
int array[maxn];

//������Ҫ��һ�������ǲ��������У�Ҳ���Ǳ�����Ȼ�����������һ������ 
int cmp(int a,int b){
  return a <= b;
}

int main(){
  //n��m�ֱ����������е�Ԫ�ظ��� 
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
