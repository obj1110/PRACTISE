�ڽӱ���ͨ 
vector<int> Adj[maxn] ;
�ڽӱ�����
struct node{
	int data;
	int w;
	bool vis;
};
vector<Node> adj[maxn] ;
���캯���ṹ��
struct Node{
	int v,w;
	Node(int _v,int _w):v(_v),w(_w){}
	Node(int _v,int _w):v(_v),w(_w){}
}; 

DFS(int index){
	vis[index] = true;
	//ʹ��vector<Node> Adj[maxn] Ҳ�����ڽӱ���д洢 
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
			//һ�����㵱ǰ�ڵ���Χ�Ľڵ� ����ͨ�Ĳ�����û�б��������� 
			if(vis[v] == false && G[u][v] != INF){
				DFS(v,depth+1);
			}
		}
	}
}

void DFSTaverse() {
	for(int u =0;u<n;u++){
		if(vis[u] == false){
			//��ǰ�ڵ���u��Ȼ��ǰ�Ľڵ������1 
			DFS(u,1);
		}
	}
}

//�ڽӾ�����ڽӱ���Ȳ����Ҫ���ڶ��ڽڵ��ѡ�����棬
//����
//Adj[u].size()

 
//vector<Node> Adj[maxn] ;
BFS(int index)

