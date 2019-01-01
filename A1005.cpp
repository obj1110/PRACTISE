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
  //һ���յ�ջӦ���Ǵ�-1��ʼ 
  int top=-1;
  
  while(sum != 0){
  	//ȫ���涨���涨topָ��ǰ��Ԫ�ػ�����һ���հ�Ԫ��
	//���ڿ�����Ӧ����ָ��һ����ǰԪ��
	//��������++��Ȼ����и�ֵ���� 
    heap[++top] = sum%10;
    sum/=10;
  }
  
  while(top>=0){
  	//�����չ����������� 
    printf("%s",rule[heap[top--]]);
    if(top >=0 ){
      printf(" ");
    }
  }
  return 0;
}
