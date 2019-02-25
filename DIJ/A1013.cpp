#include<iostream> 
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int maxn = 1010;
const int inf = 0x3fffff;
int d[maxn] = {0};
int G[maxn][maxn];
bool vis[maxn] = {false};
int pre[maxn];

void dij(int s){
	fill(d,d+maxn,inf);
	for(int i=1;i<=n;i++){
		pre[i] = i;
	}
	vis[s] = true;
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u= -1;
		int min = inf;
		for(int j=1;j<=n;j++){
			if(min > d[j]){
				min = d[j];
				u = j;
			}
		}
		if(u = -1) return;
		vis[u] = true;
		for(int v=1;v<=n;v++){
			if(vis[v] == false && G[u][v] != inf && d[u] + G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
				pre[v] = u;
			}
		}
	}
}
int main(){
		
	return 0;
}
