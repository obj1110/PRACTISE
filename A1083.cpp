#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct node{
  char name[12];
  char cla[12];
  int grade;
}stu[10010];

int cmp(node a ,node b){
  if(a.grade!=b.grade)return  a.grade > b.grade;
//  else return strcmp(a.cla,b.cla)<0;
}

int main(){
  int n,grade,left,right;
  scanf("%d",&n);
  char temp1[12],temp2[12];
  for(int i=0;i<n;i++){
    scanf("%s %s %d",stu[i].name,stu[i].cla,&stu[i].grade);
  }
  sort(stu,stu+n,cmp);
  
  scanf("%d %d",&left,&right);
  int flag =0;
  for(int i=0;i<n;i++){
    if(stu[i].grade >= left && stu[i].grade <= right){
      flag =1;
      printf("%s %s",stu[i].name,stu[i].cla);
      if(i!=n-1) printf("\n");
    }
  }
  if(flag==0){
    printf("NONE");
  }
  return 0;
}
