#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1010;
const int inf = 0x3ffffff;
 
int n,c1,c2,m;
//最短距离+最大点权
int G[maxn][maxn]; 
int d[maxn] ;
bool vis[maxn] = {false};
int pre[maxn];
//p 是从起点到某一个点的点权之和 
int p[maxn];
//point是点权 
int point[maxn];
//到达某一个点的时候的最短路径的个数 
int num[maxn]; 

void dij(int s){
	fill(d,d+maxn,inf);
	vis[s] = true;
	for(int i=0;i<n;i++){
//		这句话不应该声明是inf，否则无法继续下去 
//		d[i] = inf;
		pre[i] = i;
	}
	d[s] = 0;
	//
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		//图中的元素的序号是从0开始的
		//而不是从1开始的 
		for(int j =0;j<n;j++){
			if(min > d[j] && vis[j] == false) {
				min = d[j];
				u = j;
			}
		}
		if(u = -1) return;
		vis[u] = true;
		for(int v=0;v<n;v++){
			if(vis[v] == false && G[u][v] != inf){
				if(d[u] + G[u][v] < d[v]) {
					//涉及到u作为中间节点的情况 
					d[u] = d[v] + G[u][v];
					pre[v] = u;	
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}
				else if(d[v]+G[u][v] == d[u]){
					//除了路径最短，还要求点权最大 
					if(w[u] + weight[v] > w[v]){
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];	
				}
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&c1,&c2,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&point[i]);
	}
	int a,b,c;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			G[i][j] = G[j][i] = inf;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c); 
		G[a][b] = G[b][a] = c;
	}
	//输入部分完毕
	dij(c1);
	//输出最短路径的个数 + 点权最大是多少 
	printf("%d %d\n",num[c2],w[c2]);
	return 0;
}
