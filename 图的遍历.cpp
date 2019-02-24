#include<iostream> 
#include<vector> 
using namespace std;
const int N = 10;
vector<int> Adj[N];
struct Node{
	int v;
	int w;
	Node(int _v,int _w):v(_v),w(_w){}
};
void DFS(int u){
	vis[u] = true;
	//u节点出发，可以到达的所有的v节点 
	for(int i=0;i<Adj[u].size();i++){
		if(vis[v]== false) {
			//对v进行深度优先遍历 
			DFS(v);
		}
	}
}
void DFSTraverse(Graph G){
//	G的所有的节点
	for(){
		if(vis[u] == false){
			DFS(u);
		}
	}
}

void init(){
	Adj[i].push_back(Node(3,4));
}
void DFS(int u,int depth){
	vis[u] = true;
	for(int v = 0;v<n;v++){
		if(vis[v]== false && G[u][v] != INF){
			DFS(v,depth+1);
		}
	}
}
void DFSTraverse(){
	//对于每一个节点都要进行遍历操作 
	for(int u = 0;u<n;u++){
		if(vis[u] == false){
			DFS(u,1);
		}
	}
}

vector<Node> Adj[maxn];
int n;
bool vis[maxn] = {false};
void DFS(int u,int depth){
	vis[u] = false;
	for(int i=0;i<Adj[u].size();i++){
		DFS(v,depth+1);
	}
}
void DFSTraverse(){
	for(int u =0;u<n;u++){
		if(vis[u] == false){
			DFS(u,1);
		}
	}
}

int main() {
	
	return 0;
}
