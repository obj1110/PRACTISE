#include<iostream> 
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int inf = 0x3ffffffff;

int n,m,st,ed;
int G[maxn][maxn];
int d[maxn],cost[maxn],c[maxn];
bool vis[maxn] = {false};
int optvalue = inf;
vector<int> pre[maxn];
vector<int> temppath,path;

void dij(int s){
	fill(d,d+maxn,inf);
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j = 0;j<n;j++){
			if(vis[j] == false&& min>d[j]){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = 1;
		for(int v= 0;v<n;v++){
			if(G[u][v] != inf && vis[u] == false){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[v][u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[u] + G[u][v] == d[v]){
					d[v] = d[u] + G[u][v];
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v){
	if(v == st){
		temppath.push_back(v);
		int value;
		for(int i = temppath.size() -1;i>0;i--)	{
			int id = temppath[i];
			int idnext = temppath[i-1];
			tempcost += cost[id][idnext];
		}
	
		if(value < optvalue){
			optvalue = value;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	else if(v != st){
		temppath.push_back(v);
		for(int i=0;i<pre[v].size();i++){
			DFS(pre[v][i]);
		}
		temppath.pop_back();
	}
}

int main(){
	
	return 0;
}
