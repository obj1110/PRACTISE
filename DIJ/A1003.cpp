//A1003һ�����������⣬���·�������������·���ĵ�Ȩ����Ƕ��١� 
#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;
const int maxn = 510;
const int inf  = 0x3ffffff; 

int n,c1,c2,m;
int G[maxn][maxn];//��ʼ��Ϊinf 
int d[maxn];  //��ʼ��Ϊinf 
bool vis[maxn] = {false};//��ʼ��Ϊfalse 
int pre[maxn];  //��ʼ��Ϊָ���Լ� 
//�ӿ�ʼλ�õ���ĳһ��������·���ĸ��� 
int num[maxn]={0}; //��ʼ��Ϊ0��Ҳ����0��·���� 
//�ӿ�ʼλ�õ���ĳһ���������Ȩ�أ���ʼΪ0 
int w[maxn] = {0};
int weight[maxn];

void init(){
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
		//���ֳ�ʼ����ʽ������ 
		//����һ��ע����G[0] �������� 
	fill(G[0],G[0]+maxn*maxn,inf);
	for(int i=0;i<maxn;i++){
		d[i] = inf;
		pre[i] = i;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	int a,b,c;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		G[a][b] = G[b][a] = c;
	}
}

void dij(int s){
	fill(d,d+maxn,inf);
	for(int i=0;i<n;i++){
		d[i] = inf;
		w[i] = 0;
		num[i] = 0;
	}
	d[s] = 0;
	w[s] = weight[s];
	num[s] =1;
	for(int i =0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j=0;j<n;j++){
			if(min > d[j] && vis[j]== false){
				min = d[j];
				u = j;
			}
		}
		if(u==-1) return;
		vis[u] = true;
		for(int v= 0;v<n;v++){
			if(vis[v] == false && G[u][v]!=inf ){
				if(d[u] + G[u][v] < d[v]){
		 			d[v] = d[u] + G[u][v];
		 			w[v] = w[u] + weight[v];
					pre[v] = u;
					num[v] = num[u];
				}
				else if(d[u] + G[u][v] == d[v]){
					if(weight[v] + w[u] > w[v])	{
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}
int main(){
	init();
	dij(c1);
	printf("%d %d\n",num[c2],w[c2]); 
	return 0;
}
