#include<iostream> 
#include<vector>
#include<cstring>
#include<cstdlib>
#include<algorithm> 

using namespace std;

const int maxn = 100100;
const int inf = 0x3fffff;

//这个邻接表，每一个节点中的v代表的都是一个点
//对于Adj[v].size() 其实表示的就是跟v相联通的点的个数
//Adj[v].size() 也就是跟v相连的所有的点 
struct node{
	int v;
	int dis;
}; 
//其实是一个Node类型的二维数组 
vector<Node> Adj[maxn];
int n;
int d[maxn];
bool vis[maxn] = {false};
void Dijstra(int s){
	fill(d,d+maxn,INF);
	d[s] = 0;
	//总共要进行多少次  
	for(int i=0;i<n;i++){
		//每次都是首先寻找最小 
		int u = -1; 
		int MIN = INF;
		for(int j = 0;j<n;j++) {
			if(vis[j] ==false && d[j] <MIN){
				u = j;
				MIN = d[j];
			}
		}
		if( u == -1) return;
		vis[u] = true;
		for(int j=0;j<Adj[u].size();j++) {
			//也就是所联通的节点 
			int v = Adj[u][j].v;
			//邻接表表示的是距离 
			//一个是没有访问过的节点集合才有更新的价值（必选
			//一个是要联通（在临界表中不需要 （可选 
			//一个是距离的关系 （必选 
			if(vis[v] == false && d[u]+Adj[u][j].dis < d[v]){
				d[v] = d[u] + Adj[u][j].dis; 
			}
		}
	}
}

struct node{
	int v;
	int dis;
};
vector<node> adj[maxn];
int n;
int d[maxn];
bool vis[maxn] = {false};

void dijstra(int s){
	fill(d,d+maxn,INF);
	d[s] = 0;
	for(int i = 0 ;i< n;i++){
		//u记录的是当前的节点是哪一个
		//dis记录的是当前的最小距离 
		int u = -1;
		int MIN = INF;
		for(int j = 0;j< n;j++) {
			if (vis[j] == false && d[j] <MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1 ) return;
		vis[u] = true;
		for(int j = 0;j<Adj[u].size;j++){
			//让我康康是哪个节点 
			//u是当前最小距离的节点，所以对所有和u联通的节点进行更新 
			int v = Adj[u][v].v;
			if(vis[v] == false && d[u] + Adj[u][v].dis < d[v]){
				d[v] = d[u] + Adj[u][v].dis;
			}
		}
	}
}




int main(){
	
}
