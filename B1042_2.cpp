#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int hashTable[255];

int main(){
  memset(hashTable,0,sizeof(hashTable));
  char str=NULL;
  while(scanf("%c",&str)!= EOF){
    if(str >= 'A' && str<='Z') {
      str = str -'A' +'a';
      hashTable[str]++;
    }
    else if(str >='a' && str<='z'){
      hashTable[str]++;
    }
  }
  int maxnum =0;
  char ch=NULL;
  for(int i=0;i<sizeof(hashTable)/sizeof(hashTable[0]);i++){
   if(maxnum < hashTable[i]){
     maxnum = hashTable[i];
     ch = i;
   }
  }
  printf("%c %d",ch,maxnum);
  return 0;
}
