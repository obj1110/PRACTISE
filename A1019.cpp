//����ת���Լ����������ж�
#include<iostream>
using namespace std;

int main(){
  int x;
  int base;  
  scanf("%d%d",&x,&base);
  //����ת����ģ��
  int y[80]={0};
  int count =0;
  while(x!=0){
    y[count++] = x%base;
    x = x/base;
  }
  //�ж��ǲ��ǻ�����
  int i = 0;
  int j = count-1;
  int flag =0;
  while(i<=j){
    if(y[i] == y[j]){
      flag =1;
      i++;
	  j--;
      continue;
    }
    else if(y[i]!= y[j]){
      flag =0;
      break;
    }
  }
  if(flag == 1){
    printf("Yes\n");
  }
  else{
  	printf("No\n");
  }
  
  for(int i=count-1;i>=0;i--){
    printf("%d",y[i]);
    if(i != 0 ) printf(" ");
  }
  return 0;
}
