#include<iostream> 
#include<algorithm>
#include<vector> 

using namespace std;
const int inf = 0x7fffffff;
int e[510][510]; //��·֮��ľ��� 
int dis[510];    
int weight[510];
bool visit[510];
vector<int> pre[510],path,temppath;

void dfs(int v){
	if(v == 0){
		
	}
}

//��PMBC����涨��վ�����·��
//���·����ѡ���ͳ����ٵ��Ǹ�
//pmbc�Լ�û������

int main(){
	int Cmax; //ż�� ,��վ������� 
	int N; //��1��ʼ�������Ǵ�0��ʼ ,��վ�ĸ��� 
	int M;//��·�ĸ���
	int S; //���⳵վ����ţ�Ҳ�����յ� 
	scanf("%d%d%d%d",&Cmax,&S,&N,&M);
	//���ð�PMBC����0�����洢 
	
	//��ǰ��վ����Ŀ 
	for(int i=0;i<N;i++) {
		scanf("%d",&C[i]);
	}
	//��·�����
	int a,b,c;
	for(int i=0;i<M;i++) {
		scanf("%d%d%d",&a,&b,&c);
	}
}
