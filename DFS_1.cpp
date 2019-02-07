#include<iostream> 
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 1000100;
const int INF = 0x7ffffffff;

int n,G[MAXN][MAXN];
bool vis[MAXN] = {false};

void DFS(int u, int depth){
	vis[u] = true;
	for(int v = 0;v<n;v++){
		if(vis[n] == false && G[u][v] != INF){
			DFS(v,depth+1);
		}
	}
}

void DFSTraverse() {
	for(int u =0;u<n;u++){
		if(vis[u] == false){
			DFS(u,1);
		}
	} 
}

int main(){
	
} 
