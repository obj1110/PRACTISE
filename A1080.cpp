#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct node{
  int choice[8];
  int ge,gi;
  float total;
  int rank;   
  int final;   //����ȥ��
}stu[40100];

int cmp(node a,node b){
  if(a.score!=b.score) return a.score > b.score;
  else if(a.ge != b.ge ) return a.ge > b.ge;
}

int quo[110];

int main(){
  int N,M,K;
  //N��ѧ��,M��ѧУ��K��ѡ��
  scanf("%d %d %d",&N,&M,&K);
  
  for(int i=0;i<M;i++){
    scanf("%d",&quota[i]);
  }
  int ge,gi;
  for(int i=0;i<N;i++){
    scanf("%d %d",&stu[i].ge,&stu[i].gi);
    stu[i].total = (stu[i].ge+ stu[i].gi)/2;
    for(int j=0;j<K;j++){
      scanf("%d",&stu[i].choice[j]);
    }
  }
  
  //���򲿷�
  sort(stu,stu+N,cmp);
  //������ֵ
  int  rank=1;
  stu[0].rank =1;
  for (int i=1;i<N;i++){
    if(stu[i].total==stu[i-1].total) {
      if(stu[i].ge == stu[i-1].ge) {
        stu[i].rank = stu[i-1].rank;
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
    rank++;
  }
  //��������ȷ��ѧУ�׶�
  
  
  //�������
  return 0;
}



