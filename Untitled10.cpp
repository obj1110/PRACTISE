#include<iostream>
#include<cstring>
using namespace std;
string week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(){
  char str1[65];
  char str2[65];
  char str3[65];
  char str4[65];
  scanf("%s %s",&str1,&str2);
  scanf("%s %s",&str3,&str4);
  
  int i=0;
  int j=0;
  
  while((i<strlen(str1))&&(j<strlen(str2))){
    if(str1[i] == str2[j] && isalpha(str1[i])){
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
  	if(str1[i] == str2[j] && isdigit(str1[i])){
  		printf("%d:",str1[i]-'0');
        break;
	  }
	else if(str1[i] == str2[j] && str1[i]>='A' && str1[i]<='N'){
		printf("%d:",str1[i]-'A'+10);
      	break;
	}
    i++;
    j++;	
  }
  //输出时间

  int cts =0;
  i=j=0;
  while((i<strlen(str3))&&(j<strlen(str4))){
    if(str3[i]==str4[j] && isalpha(str3[i])){
      break;
    }
    i++;
    j++;
    cts++;
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
