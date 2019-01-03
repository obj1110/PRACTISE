#include<iostream> 
#include<cstring>
#include<algorithm> 
using namespace std;

struct ite{
	char id[6];
	int score[6];
	int rank;
	int perfect;
	int fail;//包括0分和-1分的数目
	int total; 
}stu[10100];

int cmp(ite a,ite b){
	if(a.total != b.total) return a.total >= b.	total;
	else if(a.perfect != b.perfect) return a.perfect>=b.perfect;
	else return strcmp(a.id,b.id)<0;
}

int p[6]={0};

int main(){
	int N,K,M;
	scanf("%d %d %d",&N,&K,&M);
	for(int i=0;i<K;i++){
		scanf("%d",&p[i]);
		
	}
	char a[6];
	int b,c;
	 
	int count=0;//我用到的stu数组到底有几个 
	int effective=0;//到底有多少人能够有资格排名。。。。 
	
	for(int i=0;i<M;i++){
		
		scanf("%s %d %d",a,&b,&c);
		int index =-1; //不确定当前输入对应的数组是哪一个 
		for(int i=0;i<count;i++){
			if(stu[i].id == a){
				index = i;
				break; 
			}
		}
		if(index !=-1){
			stu[i].score[b] = (stu[i].score[b] >= c)?stu[i].score[b]:c;
			if(c == p[i]) stu[i].perfect++;
			else if(c==0 || c==-1) stu[i].fail++;
		} 
		else{
			strcpy(stu[count].id,a);
			stu[count].total = 0;
			stu[count].score[b] = c;
			stu[count].fail = 0;
			stu[count].perfect  =0;
			if(c==p[i]) stu[count].perfect =1;
			if(c== -1 || c==0) stu[count].fail=1;
			//由于对一个问题可能有多次提交，所以不可以轻易的total加 
		} 
		count++;				
	}
	
	for(int i=0;i<count;i++){
		stu[i].total =0;
		for(int j =0;j<K;j++){
			stu[i].total += p[j];
		}
	}
	//比较
	sort(stu,stu+count,cmp);
	//排名 
	int rank =1;
	stu[0].rank = 1;
	for(int i=0;i<count;i++){
		if(stu[i].fail!=5){
			if(stu[i].total == stu[i-1].total) {
			stu[i].rank = stu[i-1].rank;
			rank++;
			}
			else stu[i].rank = (++rank);
			effective++;	
		}
		else{
			stu[i].rank = -1;
		}
	}
	
	//输出部分
	for(int i=0;i<effective;i++){
		printf("%d %s ",stu[i].rank,stu[i].id);
		for(int j=0;j<K;j++){
			if(stu[i].score[i] == 0) printf("0"); 
			else if(stu[i].score[i]==-1) printf("-");
			else {
				printf("%d",stu[i].score[j]);
			}
			if(j!= K-1){
				printf(" ");
			}
		}
		if(i!=effective-1){
			printf("\n");
		}
	} 
	
}
