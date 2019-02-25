//最短路径是不是唯一的，如果不是唯一的，就要输出最小花费的哪一个 
#include<iostream>
#include<cstdlib>
#include<algorithm> 
using namespace std;
const int maxn = 520;
const int inf = 0x3fffff;

int d[maxn];
int G[maxn][maxn];
bool vis[maxn] = {false};
int cost[maxn][maxn];
int c[maxn] = {0} ;
int n,m,s,destination;

//
vector<int> path;
vector<int> temppath;
vector<int> pre[maxn];

//hence the cities are numbered from 0 to N-1

void init(){
	fill(G[0],G[0]+maxn*maxn,inf);
	fill(cost[0],cost[0]+maxn*maxn,inf);
	scanf("%d%d%d%d",&n,&m,&s,&destination);
	for(int i=0;i<n;i++){
		pre[i].push_back(i);
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
	//似乎没什么必要啊 
//	for(int i=0;i<n;i++){
//		pre[i].push_back(i);
//	}
	d[s] = 0;
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
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[u] + G[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
 
int optvalue =  inf ;
void DFS_seq(int end){
	if(s == end){
		temppath.push_back(end);
		int value = 0;
		//计算temppath的节点所构成的value
		//
		int p1= end;
		int p2 = pre[end].front() ;
		
		while(p1 != s) {
			value += cost[p1][p2];
			p1 = p2;
			if(p1 == s) {
				break;
			}
			p2 = pre[p2].front();
		}
		//
		if(value < optvalue){
			optvalue = value;
			path = temppath; 
		} 
		temppath.pop_back();
		return;
	}
	else if(s != end){
		temppath.push_back(end);
		for(int i=0;i<pre[end].size();i++){
			DFS_seq(pre[end][i]);
		}
		temppath.pop_back();
	}
} 

int main(){
	init();
	dij(s);
//	the total distance and the total cost of the path
	cout<<path.size()<<endl;
	
	for(int i=0;i<path.size();i++){
		printf("%d",path[i]);
	}
	return 0;
}
