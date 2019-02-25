//最短路径是不是唯一的，如果不是唯一的，就要输出最小花费的哪一个 
#include<iostream>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
const int maxn = 520;
const int inf = 0x3fffff;

int d[maxn];
int G[maxn][maxn];
bool vis[maxn] = {false};
int cost[maxn][maxn];
int c[maxn] = {0} ;
int n,m,s,destination;
int pre[maxn];
//
//hence the cities are numbered from 0 to N-1
vector<int> temppath;
vector<int> path;

void init(){
	fill(G[0],G[0]+maxn*maxn,inf);
	fill(cost[0],cost[0]+maxn*maxn,inf);
	scanf("%d%d%d%d",&n,&m,&s,&destination);
	for(int i=0;i<n;i++){
		pre[i] = i;
	}
	int ta,tb;
	for(int i= 0;i<m;i++){
		scanf("%d%d",&ta,&tb);
		scanf("%d",&G[ta][tb]);
		scanf("%d",&cost[ta][tb]);
		G[tb][ta] = G[ta][tb];
		cost[tb][ta] = cost[ta][tb];
	}	
}

void dij(int s){
	fill(d,d+maxn,inf);
	for(int i=0;i<n;i++){
		c[i] = 0;
		pre[i] = i;
	}
	d[s] = 0;
	c[s] = 0; 
	for(int i=0;i<n;i++) {
		int u = -1;
		int min = inf;
		for(int j = 0;j<n;j++){
			if( vis[j] == false && min > d[j]) {
				min = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0;v<n;v++){
			if(vis[v] == false && G[u][v] != inf){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
				else if(d[u] + G[u][v] == d[v]){
					if(c[u] + cost[v][u] < c[v]){
						c[v] = cost[v][u] + c[u];
						pre[v] = u;
					}
					else if(c[u] + cost[u][v] >= c[v]){ 
						//不进行任何操作 
					}
				}
			}
		}
	}
}

int total_dis = 0;
void dij_seq(int start,int end){
	if(start == end) {
//		total_dis += G[end][pre[end]];
		printf("%d ",start);
		return;
	}
	else{
		total_dis += G[end][pre[end]];
		dij_seq(start,pre[end]);
		printf("%d ",end);
	}
}

int main(){
	init();
	dij(s);
//	the total distance and the total cost of the path
	dij_seq(s,destination);
	printf("%d %d",total_dis,c[destination]);
	return 0;
}
