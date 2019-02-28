邻接表普通 
vector<int> Adj[maxn] ;
邻接表特殊
struct node{
	int data;
	int w;
	bool vis;
};
vector<Node> adj[maxn] ;
构造函数结构体
struct Node{
	int v,w;
	Node(int _v,int _w):v(_v),w(_w){}
	Node(int _v,int _w):v(_v),w(_w){}
}; 

DFS(int index){
	vis[index] = true;
	//使用vector<Node> Adj[maxn] 也就是邻接表进行存储 
	for(int i=0;i<Adj[index].size();i++){
		if(vis[index] == false)  DFS(index); 
	}
}

int liantongfenliang = 0;
DFSTraverse(G){
	for(all node int G){
		if(vis[node] == false)
		 DFS(u);
		 liantongfenliang ++;
	}
}
//
int n,G[maxn][maxn];
bool vis[maxn] = {false};
void DFS(int u,int depth){
	vis[u] = true;
	void DFS(int u,int depth){
		vis[u] = true;
		for(int v= 0;v<n;v++){
			//一个是你当前节点周围的节点 是联通的并且是没有被遍历过的 
			if(vis[v] == false && G[u][v] != INF){
				DFS(v,depth+1);
			}
		}
	}
}

void DFSTaverse() {
	for(int u =0;u<n;u++){
		if(vis[u] == false){
			//当前节点是u，然后当前的节点深度是1 
			DFS(u,1);
		}
	}
}

//邻接矩阵和邻接表相比差别主要在于对于节点的选择上面，
//包括
//Adj[u].size()

 
//vector<Node> Adj[maxn] ;
BFS(int index)

