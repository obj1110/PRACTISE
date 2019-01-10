#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int hashTable[255];

int main(){
  memset(hashTable,0,sizeof(hashTable));
  char str;
  while(scanf("%c",&str)!= EOF){
    if(str >= 'A' && str<='Z') {
      str = str -'A' +'a';
      hashTable[str]++;
    }
  }
  int maxnum =0;
  for(int i=0;i<sizeof(hashTable)/sizeof(hashTable[0]);i++){
   maxnum = max(maxnum,hashTable[i]);
  }
  printf("%d",maxnum);
  return 0;
}
