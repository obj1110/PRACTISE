#include<iostream>
#include<cstring>

using namespace std;

char rule[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
  char str[110]={}; 
  int temp,sum =0;
  
  scanf("%s",&str);
  int len = strlen(str);
  
  if(len ==1){
  	printf("%s",rule[str[0]-'0']);
  	return 0;
  }
  
  for(int i=0;i<len;i++){
    sum += str[i]-'0';
  }
  
  int heap[110]={};
  //一个空的栈应该是从-1开始 
  int top=-1;
  
  while(sum != 0){
  	//全看规定，规定top指向当前的元素还是下一个空白元素
	//现在看来，应该是指向一个当前元素
	//所以首先++，然后进行赋值操作 
    heap[++top] = sum%10;
    sum/=10;
  }
  
  while(top>=0){
  	//都按照规则来就行了 
    printf("%s",rule[heap[top--]]);
    if(top >=0 ){
      printf(" ");
    }
  }
  return 0;
}
