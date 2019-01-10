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
  int final;   //����ȥ��
  int id;
}stu[40500];

struct node2{
	int id; ///ѧУ��id 
	int quo;//ѧУ�������������� 
	int number[20010];
	int ava;//ʣ������
	int cts;//Ϊ�˷�ֹ��rank�����ֵ�ʵ������ͳ�� 
	int last;//���һ��ѧ����id 
}sch[110];

int cmp(node a,node b){
  if(a.total!=b.total) return a.total > b.total;
  else if(a.ge != b.ge ) return a.ge > b.ge;
}


// �ر�ע�⣡�������� 
int cmp2(int a,int b){
//	return stu[a].id < stu[b].id;
	return a<b;
}
int main(){
  int N,M,K;
  //N��ѧ��,M��ѧУ��K��ѡ��
  scanf("%d %d %d",&N,&M,&K);
  
  for(int i=0;i<M;i++){
  	sch[i].id = i;
  	//ѧУ������鲻�ܸ�ֵΪ0��Ϊ��һ��ѧ����id����0 ,����ȫ����ֵΪ-1 
  	//�����ֵ���н�������Ҫ�Ǹ�ֵ-1��������������ȫ��-1����������ǰ���������Ӱ�죬��ĺ���Ӱ��ġ� 
  	memset(sch[i].number,1,sizeof(sch[i]));
  	//
    scanf("%d",&sch[i].quo);
    sch[i].ava = sch[i].quo;
	sch[i].cts = 0; 
	sch[i].last =-1;
  }
  int ge,gi;
  for(int i=0;i<N;i++){
  	//��������˱�ź���Ҫ 
  	stu[i].id = i;
    scanf("%d %d",&stu[i].ge,&stu[i].gi);
    stu[i].total = (stu[i].ge+stu[i].gi)/2;
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
  //�������
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
	
//���������û���κε����� 

  //��������ȷ��ѧУ�׶�
	for(int i=0;i<N;i++)  {
		for(int j=0;j<K;j++){
			int attempt = stu[i].choice[j];
			//���������ѧУ��������һ������
			if(sch[attempt].ava >0 || (sch[attempt].ava <= 0 && stu[i].rank==stu[sch[attempt].last].rank)){
				sch[attempt].number[sch[attempt].cts] = stu[i].id;
				sch[attempt].cts++;
				sch[attempt].ava--;
				sch[attempt].last = stu[i].id;
				break;
			} 
		}
	}
	
  //��¼ȡ������������ 
  for(int i=0;i<M;i++){
  	int size = (sizeof(sch[i].number)/sizeof(sch[i].number[0]));
  	sort(sch[i].number,sch[i].number+size,cmp2);
  }
  
  //�������
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



