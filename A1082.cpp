#include<iostream>
#include<cstring>
using namespace std;
char rule[10][6] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
  char num[12];
  scanf("%s",num);
  char temp[12];
  if(num[0] == '-') {
    printf("Fu ");
    int length = strlen(num);
	for(int i=1;i<length;i++){
		temp[i-1] = num[i];
	}
	strcpy(num,temp);
  };
  
   int len = strlen(num);
   for(int i=0;i<len;i++){
   	
      //�����ж���������һ������0.ֻӦ�����һ��0�����Ա���������ǰ������ж� 
   	
	  printf("%s",rule[num[i]-'0']);
      
      if(i!=len-1) printf(" ");
       
      if((num[i]-'0')!=0){
      	 if((len-i)%4==0){
      		printf("Qian ");
		  }
		  else if((len-i)%4==3){
	      	printf("Bai ");
		  }
		  else if((len-i)%4==2){
	      	printf("Shi ");
		  }	
	  }
      
	  if((len-i) == 5) {
	  	printf("Wan ");
	  }
	  else if ((len-i) == 9){
	  	printf("Yi ");
	  }
	}
   
  return 0;
}
