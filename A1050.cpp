#include<iostream>
#include<cstring>
using namespace  std;

char str1[10050];
char str2[255];
bool hashTable[255]={0};

int main(){
  memset(hashTable,true,sizeof(hashTable));
  
  //默认用\0来进行换行， 
  cin.getline(str1,10050); 
  scanf("%s",str2);
  
  for(int i=0;i<strlen(str2);i++){
  	if(str2[i]>='A' && str2[i]<='Z'){
  		str2[i] = str2[i] - 'A' +'a';
	  }
    hashTable[str2[i]] = false;
  }
  
  int len1 = strlen(str1);
  for(int i=0;i<len1;i++){
    if(hashTable[str1[i]] == true){
      printf("%c",str1[i]);
    }
  }
}
