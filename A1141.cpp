//���������Ҫ�ǲ�֪��Ӧ������ʲô�������ݽṹ��
//������о�������
//�о�Ӧ����hash�ṹ �����ǽṹ�����飬Ҳ����Ԫ��Ϊ�ṹ������� 
#include<iostream>
#include<cstring>
using namespace std;
const int SIZE = 100010; 

struct schoolstruct{
  float tws; //Ȩ�� 
  char name[8];//��Сд������
  int n; //�������� 
}temp;

int main(){
  int N;
  float score;
  char id[8]; 
  char school;
  scanf("%d",&N);
  //�ṹ������  
  schoolstruct item[N]; 
  //��ά����ר�����ڴ��ѧУ�����֣���Ϊһ����������ʹ�� 
  char index[N][8]={};
  
  for(int i=0;i<N;i++){
  	int tws = 0;
    scanf("%s %f %s",id,score,school);
    
    //��Сдת������strlwr strupr 
    //���⻹��toupper �� tolower 
    strcpy(school,strlwr(school));
    //���� 
    if(id[0]=='B'){
    	tws += score/1.5;
	}
	else if(id[0]=='A'){
		tws += score*1.0;
	}
	else if(id[0]=='T'){
		tws += score*1.5;
	}
	
//  ��һ���Ĵ����Ϊһ�����⣬����������ʱ������֧��
//   ���Գ��Ե���dictionary ������ hashtable�ȵȡ� 
//	for(int i=0;i<N;i++){
//        if(strcmp(index[i],school)){
//        	item[i].n++;
//			item[n].name = school;
//			item[n].tws += tws; 
//			break;
//		}
//		else if(){
//			
//		}
//	}
//    
  }

  // Rank School TWS Ns
  return 0;
}

