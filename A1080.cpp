#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector> 

using namespace std;

struct node{
  int choice[8];
  int ge,gi;
  float total;
  int rank;   
  int final;   //最终去向
  int id;
}stu[40500];

struct node2{
	int id; ///学校的id 
	int quo;//学校可以招生的名额 
	int number[20010];
	int ava;//剩余名额
	int cts;//为了防止等rank而出现的实际名额统计 
	int last;//最后一个学生的id 
}sch[110];

int cmp(node a,node b){
  if(a.total!=b.total) return a.total > b.total;
  else if(a.ge != b.ge ) return a.ge > b.ge;
}


// 特别注意！！！！！ 
int cmp2(int a,int b){
//	return stu[a].id < stu[b].id;
	return a<b;
}
int main(){
  int N,M,K;
  //N个学生,M个学校，K个选择
  scanf("%d %d %d",&N,&M,&K);
  
  for(int i=0;i<M;i++){
  	sch[i].id = i;
  	//学校这个数组不能赋值为0因为有一个学生的id就是0 ,所以全部赋值为-1 
  	//这个赋值很有讲究，你要是赋值-1，会让整个数组全是-1，对最后输出前的排序很有影响，真的很有影响的。 
  	memset(sch[i].number,1,sizeof(sch[i]));
  	//
    scanf("%d",&sch[i].quo);
    sch[i].ava = sch[i].quo;
	sch[i].cts = 0; 
	sch[i].last =-1;
  }
  int ge,gi;
  for(int i=0;i<N;i++){
  	//这个申请人编号很重要 
  	stu[i].id = i;
    scanf("%d %d",&stu[i].ge,&stu[i].gi);
    stu[i].total = (stu[i].ge+stu[i].gi)/2;
    for(int j=0;j<K;j++){
      scanf("%d",&stu[i].choice[j]);
    }
  }

  //排序部分
  sort(stu,stu+N,cmp);
    
  //排名赋值
  int  rank=1;
  stu[0].rank =1;
  for (int i=1;i<N;i++){
    if(stu[i].total==stu[i-1].total) {
      if(stu[i].ge == stu[i-1].ge) {
        stu[i].rank = stu[i-1].rank;
        rank++;
        continue;
      }
      else {
        stu[i].rank = ++rank;
        continue;
      }
    }
    else{
      stu[i].rank = ++rank;
      continue;
    }
  }
  //检验输出
//  for(int i=0;i<N;i++) {
//  	 
//  	printf("%d | %f %d ",stu[i].id,stu[i].total,stu[i].rank);
//  	printf(" | ");
//  	for(int j=0;j<K;j++){
//  		printf("%d",stu[i].choice[j]);
//  		printf(" ");
//	  }
//	  printf(" | ");
//	printf("%d %d",   stu[i].ge,     stu[i].gi);
//	printf("\n");
//  }
	
//上面的输入没有任何的问题 

  //根据排名确定学校阶段
	for(int i=0;i<N;i++)  {
		for(int j=0;j<K;j++){
			int attempt = stu[i].choice[j];
			//就是申请的学校到底是哪一个。。
			if(sch[attempt].ava >0 || (sch[attempt].ava <= 0 && stu[i].rank==stu[sch[attempt].last].rank)){
				sch[attempt].number[sch[attempt].cts] = stu[i].id;
				sch[attempt].cts++;
				sch[attempt].ava--;
				sch[attempt].last = stu[i].id;
				break;
			} 
		}
	}
	
  //对录取名单进行排序 
  for(int i=0;i<M;i++){
  	int size = (sizeof(sch[i].number)/sizeof(sch[i].number[0]));
  	sort(sch[i].number,sch[i].number+size,cmp2);
  }
  
  //输出部分
  for(int i=0;i<M;i++){
    if(sch[i].cts>0){
      for(int j=0;j<sch[i].cts;j++){
			printf("%d",sch[i].number[j]);
			if (j!= sch[i].cts-1){
				printf(" ");
			  }
		  }
    }
	   if(i!=M-1){
		  printf("\n");
	  }
  }
  return 0;
}



