#include<iostream>
#include<cstring>
using namespace std;
char name[1010][12];
char password[1010][12];

struct account{
  char name[12];
  char password[12];;
};

account items[1010];

int main(){
  int n,m=0;
  

  char nm[12];
  char pw[12];
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%s %s",&nm,&pw);
    int flag =1;
    for(int i=0;i<strlen(pw);i++){
      if(pw[i] == '1') {
    	pw[i] = '@'	;
        flag = 0;
        continue;
      }
      else if(pw[i] == '0') {
        pw[i] = '%';
        flag = 0;
        continue;
      }
      else if(pw[i] == 'l'){
        pw[i] = 'L';
        flag = 0;
        continue;
      } 
      else if(pw[i] == 'O') {
        pw[i] = 'o';
        flag = 0;
        continue;
      }
    }
    //替换完毕，开始输入到结构体数组中
    if(flag ==0){
      strcpy(items[m].name,nm);
      strcpy(items[m++].password,pw);
    }
  }
  if(m == 0 ){
    printf("There is %d account and no account is modified",n);
    return 0;
  }

  printf("%d\n",m);
  for(int i=0;i<m;i++){
    printf("%s %s\n",items[i].name,items[i].password);
  }
  return 0;
}
