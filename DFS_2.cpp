#include<iostream>
#include<vector> 
#include<algorithm> 
#include<cstring> 
#include<cstdlib>

using namespace std;

struct Node{
	int v;
	int w;
	Node(){
	}
	Node(int _v,int _w){
		v = _v;
		w = _w;
	}
};

const int MAXN = 1001000;
const int INF  = 0x7fffffff;

int n,G[MAXN][MAXN];
bool vis[MAXN] = {false};

void DFS(int u,int depth){
	vis[u] = true;
	for(int v = 0;v<n;v++){
		if(vis[v] == false && G[u][v] != INF){
			DFS(v,depth+1);
		}
	}
}

void DFSTraverse(){
	for(int u = 0;u < n;u++){
		if(vis[u] == false){
			DFS(u,1);
		} 
	}
}
