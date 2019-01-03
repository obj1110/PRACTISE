#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct ite{
  char id[14];
  int score;
  int fr; //final rank
  int lr; // local rank
  int kaochang;
}stu[30100];

// registration_number     final_rank     location_number      local_rank
int cmp(ite a,ite b){
    if(a.score!= b.score) return a.score>b.score;
    //rank越小越靠前
    else if(a.fr!=b.fr) return a.fr<b.fr;
    else if(a.kaochang != b.kaochang) return a.kaochang<b.kaochang;
    else if(a.lr != b.lr) return a.lr<b.lr; 
    //实践证明，这种说法还是很有用也是很可行的。 
    else return strcmp(a.id,b.id)<0; 
}

int cmp1(ite a,ite b){
    if(a.score!= b.score) return a.score>b.score;
}

int main(){
  int n,k;
  char str[14];
  scanf("%d",&n);
  
  
  
  //考生总数
  int count =0;
  
  for(int i=0;i<n;i++){
    int init_count = count;
    scanf("%d",&k);
    for(int j=0;j<k;j++){
      scanf("%s %d",stu[count].id,&stu[count].score);
      stu[count].kaochang =i+1;
      count++;
    }
    
//    cout<<"--------%d------"<<init_count<<endl; 


    //lr可以在内层循环结束后进行
    sort(stu+init_count,stu+init_count+k,cmp1);
    int lr =1;
    //local rank赋值
    stu[init_count].lr = 1;
    for(int i=init_count+1;i<init_count+k;i++){
      if(stu[i].score == stu[i-1].score) stu[i].lr = stu[i-1].lr;
      else stu[i].lr = lr+1;
      lr++;
    }
  }
  
  //fr必须要两层循环结束后进行
  sort(stu,stu+count,cmp1);
  //对fr赋值
  int fr =1;
  stu[0].fr = 1;
  for(int i=1;i<count;i++){
    if(stu[i].score == stu[i-1].score)   stu[i].fr = stu[i-1].fr;
    else stu[i].fr = fr+1;
    fr++;
  }
  
  
  sort(stu,stu+count,cmp);
  
  //输出了
  printf("%d\n",count);
  for(int i=0;i<count;i++){
    printf("%s %d %d %d",stu[i].id,stu[i].fr,stu[i].kaochang,stu[i].lr);
    if(i!=count-1) printf("\n"); 
  }
  
  //此外注意这个分数相同的情况
  //数据已经扫描进来了。。。。接下来就是sort时间了
  
  return 0;
}



//2019年1月1日23:24:26
//这个程序的问题出现在，对于准考证号char [13]的排序是一大难题 

// 
