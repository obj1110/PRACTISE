#include<iostream> 
#include<vector> 
#include<algorithm> 
#include<cstring>

using namespace std;
struct it{
	char id[20];
	int de;
	int cai;
	int flag;//������������ 
}ite[100100];

//����cmp���� 
 
int cmp(it a,it b){
	if(a.flag != b.flag) return a.flag <b.flag;
	else if(a.sum != b.sum) return a.sum < b.sum;
	else if(a.de != b.de) return a.de < b.de;
	else return strcmp(a.id,b.id); 
}

int main(){
	int N,L,H;
	int de,cai,
	scanf("%d %d %d",&N,&L,&H);
	for(int i=0;i<N;i++){
		scanf();		
	}
} 
