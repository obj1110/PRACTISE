#include<iostream>
#include<cstring>
using namespace std;
string week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

const int SIZE = 60;
int main(){
  char str1[65];
  char str2[65];
  scanf("%s %s",&str1,&str2);
  
  int i=0;
  int j=0;
  
  while((i<strlen(str1))&&(j<strlen(str2))){
    if(str1[i] == str2[j]){
      cout<<week[str1[i]-'A']<<" ";
      i++;
      j++;
      break;
    }
    i++;
    j++;
  }
  
  //输出小时
  while((i<strlen(str1))&&(j<strlen(str2))){
    if(str1[i] == str2[j]){
      if(str1[i]>='0' && str1[i]<='9'){
        printf("%d:",str1[i]-'0');
        break;
      }
      else if(str1[i]>='A' && str1[i]<='N'){
      	printf("%d:",str1[i]-'A'+10);
      	break;
	  }
    }
    else{
    	i++;
    	j++;	
	}
  }
  //输出时间

  scanf("%s %s",&str1,&str2);
  int cts =0;
  i=0;
  j=0;
  while((i<strlen(str1))&&(j<strlen(str2))){
    cts++;
    if(str1[i]==str2[j]){
      break;
    }
    i++;
    j++;
  }
  if(cts<10){
    printf("0%d",cts);
  }
  else{
    printf("%d",cts);
  }
  
  
  //输出 
  return 0;
}
