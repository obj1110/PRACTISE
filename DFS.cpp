#include<iostream> 
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib> 

using namespace std;

struct Node{
	int v;
	int w;
	//Ĭ�ϵĹ��캯���ز����� 
	Node(){
	}
	//�ṹ������������Ĺ��캯�� 
	Node(int _v,int _w){
		v = _v;
		w = _w;
	}
};

const int MAXN = 1000100;
const int INF = 0x7fffffff;

int n,G[MAXN][MAXN];
bool vis[MAXN] = {false}; 


//һ���ֲ��Ĺ���
void DFS(int u,int depth){
	vis[u] = true;
	for(int v = 0;v<n;v++){
		if(vis[v] == false && G[u][v] != INF){
			DFS(v,depth+1);
		}
	}
}

//�ۺϵı��� 
void DFSTraverse(){
	for(int u = 0;u<n;u++){
		if(vis[u] == false){
			DFS(u,1);
		}
	}
}





int main(){
	int N = 10;
	vector<int> Adj[N];//�ڽӾ��󣬻������ڽӱ�
	vector<Node> Adj1[N];
	Node temp;
	temp.v = 3;
	temp.w = 4;
	Adj1[1].push_back(temp);
	Adj1[2].push_back(Node(3,4));
	return 0;
}


