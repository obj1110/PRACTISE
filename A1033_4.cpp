#include<iostream>
#include<cstring>

using namespace std;
int main(){
  char index[90];
  char ans[40][40]={};
  ///ֱ�Ӷ�ȡ�ַ����� 
  cin>>index;
  int cts = strlen(index);
  
  int n1,n2,n3;
  for(n2=1;n2<cts;n2++){
  	//���ż������Ҳ�Ƿǳ���Ҫ�ģ����ɺ��ӵ�	 
  	if((cts+2-n2)%2 == 0){
  	     n1 = n3 = (cts+2-n2)/2;	
  	     //����˵��n2һ��ʼ�Ǳ�n1ҪС�ܶ�ģ�Ȼ������n2>=n1�������Ȼ����ǲ��ϵ�����n2ֱ������n1��ʱ�� 
  	    if(n2 >=n1)  break;
    }
  }
  //�������Ѿ���ȡ��n1,n2,n3
  int pct =0;
  for(int i=0;i<n1;i++,pct++){
  	ans[i][0] = index[pct];
  }
  for(int i=1;i<n2;i++,pct++){
  	ans[n1-1][i] = index[pct];
  }
  for(int i=2;i<=n3;i++,pct++){
  	ans[n3-i][n2-1] = index[pct];
  }
  
  for(int i=0;i<n1;i++){
  	for(int j=0;j<n2;j++){
  		printf("%c",ans[i][j]);
	  }
	  printf("\n");
  }
  return 0;
} 
