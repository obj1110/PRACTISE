//#include<iostream>
//using namespace std;
//const int SIZE = 1010;
//int main(){
//  int a,b;
//  int flag =1;
//  int cts =0;
//  while (flag){
//  	  scanf("%d %d",&a,&b);
//	  
//	  if(b!= 0){
//	    
//	    if(cts > 0 ){
//	       printf(" ");
//	    }
//		cts++;
//	    printf("%d %d",a*b,(b-1));
//	  }
//	  else{
//	  	flag =0;
//	  } 
//  }
//  return 0;
//}
//
#include<cstdio>
#include<iostream>
using namespace std;
const int SIZE =1010;
int main(){
	int index[SIZE] = {0};//emmmmm���ַ���Ҫ���գ����ǰ�һ������ȫ����ʼ��Ϊ0 
	int a,b,cts=0;
	for(int i=0;i<SIZE;i++){
		index[i] = 0;
	}
	//����ĸ�����Ҫʹ��EOF�����ж�,Ȼ��EOF���ж�������������Ҫ����ctrl+Z 
	//�����ʱ������������߽ף������ʱ������������ͽס��㲻��������Ȼ����Ϊ���е������׵ġ�
	//������ж�EOF���а� 
	while(scanf("%d%d",&a,&b)== EOF ){
		index[b] += a;
	}
	//����һ�������������0 0 ����ʽ
	for(int i=SIZE-1;i>0;i++){
		if(index[i]!=0){

		}
	}
	return 0; 
}
