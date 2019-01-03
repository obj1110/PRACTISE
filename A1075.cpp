#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int p[6]= {};

struct ite{
  char id[6];
  int score[6];
  int rank;
  int perfect;
  int total;
  int visable;
}stu[10100];

int cmp(ite a,ite b){
  if(a.total!=b.total) return a.total>=b.total;
  else if(a.perfect!=b.perfect) return a.perfect>=b.perfect;
  else return strcmp(a.id,b.id)<0;
}

int main(){
  //n是用户的数目，k是问题的数目，m是提交总数的数目
  int n,k,m;
  scanf("%d %d %d",&n,&k,&m);
  for(int i=0;i<k;i++){
    scanf("%d",&p[i]);
  }
  
  char a;
  int b,c;
  
  //count是当前的数组的元素的数目
  int count=0;
  
  for(int i=0;i<m;i++){
    scanf("%s %d %d",a,b,c);
    //index表示当前元素是哪一个 
    int index =-1;
    for(int i=0;i<count;i++){
      if(stu[i].id == a){
        index = i;
        break;
      }
    }
    //这里是输入的情况 
    if(index !=-1){
      stu[i].score[b] = (stu[i].score[b] >= c)?stu[i].score[b]:c;
      if(c == p[i]) stu[i].perfect++;
    }
    else{
      strcpy(stu[count].id,a);
      stu[count].total = 0;
      stu[count].score[b] = c;
      stu[count].visable = 0;
      
      //只需要单独设置为visible即可，不用设置别的东西
      if(c>0) stu.visable =1;
      
      if(c==p[i]){
        stu[count].perfect =1;
      }
      else{
        stu[count].perfect = 0;
      }
      
      if(c == -1) continue;
      else if(c!=-1) total+=c;
      count++:
    }
  }
  // user_id problem_id partial_score_obtained
  //也就是用户在某个题目上的得分情况
  return 0;
}
