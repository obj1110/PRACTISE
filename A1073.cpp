#include<iostream>
#include<cstring>
using namespace std;

int main(){
  char str[10010];
  gets(str);
  int len = strlen(str);
  if(str[0]=='-') printf("-");
  
  int pos =0;
  while(str[pos] != 'E'){
    pos++;
  }
  
  int exp =0;
  for(int i=pos+2;i<len;i++){
    exp = exp*10 + (str[i]-'0');
  }
  
  if(exp ==0){
    for(int i=1;i<pos;i++){
      printf("%c",str[i]);
    }
  }
  
  if(str[pos+!] == '-') {
  	printf("0.");
  	for(int i=0;i<exp-1;i++){
  		printf("0");
	  }
	  printf("%c",str[1]]);
	  for(int i=3;i<pos;i++){
	  	printf("%c",str[i]);
	  }
  }
  else{
  	for(int i=1;i<pos;i++){
  		
	  }
  }
  return 0;
}
