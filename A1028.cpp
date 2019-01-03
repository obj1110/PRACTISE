#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct item{
  char id[10];
  char name[10];
  int score;
}stu[100100];

int cmp1(item a,item b){
  if(a.id != b.id) return strcmp(a.id,b.id)<0;
}
int cmp2(item a,item b){
  if(a.name != b.name) return strcmp(a.name , b.name)<=0;
  else{
    return strcmp(a.id,b.id)<0;
  }
}

int cmp3(item a ,item b){
  if(a.score != b.score ) return a.score <= b.score;
  else{
    return strcmp(a.id,b.id)<0;
  }
}


int main(){
  int N,C;
  scanf("%d %d",&N,&C);
  int count =0;
  for(int i=0;i<N;i++){
    scanf("%s %s %d",stu[i].id,stu[i].name,&stu[i].score);
    count++;
  }
  if(C==1){
    sort(stu,stu+count,cmp1);  
  }
  else if(C==2){
    sort(stu,stu+count,cmp2);
  }
  else if(C==3){
    sort(stu,stu+count,cmp3);
  }
  
  for(int i=0;i<count;i++){
    printf("%s %s %d",stu[i].id,stu[i].name,stu[i].score);
    if(i!=count -1){
      printf("\n");
    }
  }
  return 0;
}

