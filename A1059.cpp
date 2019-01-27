#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;
const int maxn = 1000100;

bool isPrime(int n){
  if(n <= 1) return false;
  int sqr = (int)sqrt(1.0*n);
  for(int i=2 ; i<=sqr ; i++){
    if(n%i==0) return false;
  }
  return true;
}



int main(){
  int n;
  int  m; 
  scanf("%d",&n);
  m =n;
  //����
  if(n==1) {
  	printf("1=1\n");
  	return 0;
  }
  if(n==0){
  	printf("0=0\n");
  	return 0;
  }
  
//  n = 97532468;
  //������и�ֵ���� 
  int sqr = (int)sqrt(1.0*n);
  int array[sqr+1];
  memset(array,-1,sqr+1);
  int cts=0;
  
  //�̳��� 
  while(n>=1){
  	//��Ҫ��֦ 
  	if(isPrime(n)){
  		array[cts++] = n;
  		break;
	  }
  	//�����ݴ�С���ı� 
  	int sqr1 = (int)sqrt(1.0*n);
  	for(int sub=2 ; sub <= sqr1 ; sub++){
  		if(n % sub ==0){
  			array[cts++] = sub;
  			//�޸��Լ� 
  			n/= sub; 
  			//��ʱ�˳� 
  			break;
		  }
	  }
  }
  
  //����ܳ���������Ƕ��ֽ����ˡ���������
  int maxprime = -1;
  int index[sqr+1];
  //ͳ�Ʋ�ͬ��Ԫ�صĸ��� ,�������ӵĸ��������ж����ģ����ᳬ��sqrt(n)�����Χ�� = = 
  memset(index,0,sqr+1);
  
  for(int i =0 ;i< cts;i++){
  	index[array[i]]++;
  	if(array[i] > maxprime ) maxprime = array[i];
  } 
  
  //��� 
  printf("%d=",m);
  for(int i=2;i<=maxprime;i++){
  	if(index[i]>=1){
  		if(index[i]>1){
  			printf("%d^%d",i,index[i]);	
	  	}
		else if(index[i]==1){
	  		printf("%d",i);
	  	}
		if(i!=maxprime){
			printf("*");  	
		}	  	
	} 
  }
}
