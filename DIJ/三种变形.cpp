#include<iostream> 
#include<algorithm> 
#include<vector>
using namespace std;

const int INF = 0X3ffffff;
const int maxn = 0xff;

int n;   //n就是节点数目 
int G[maxn][maxn];
int pre[maxn]; //初始化，距离更新的时候修改 
bool vis[maxn] = {false};//只能进行一次初始化 
int d[maxn]; //表示的是点到点的距离情况 

// 1
void DIJ0(int s){
	fill(d,d+maxn,INF);
	vis[s] = 1;
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1;
		int MIN = INF;
		for(int j = 0 ; j < n ; j++){
			if(vis[j] == false && MIN > d[j]){
				MIN = d[j];
				u = j;
			}
		}
		if( u == -1 ) return;
		vis[u] = true;
		//新找到的距离节点进行距离的更新 
		for(int v = 0; v<n;v++){
			//d[u]或者是d[v]都是从v0出发，直接到u或者是v的距离情况 
			if(vis[v] == false && G[u][v] + d[u] < d[v]){
				d[v] = G[u][v] + d[u] ;
				///更新距离的时候，顺便更新前驱 
				pre[v] = u;
			}
		}
	}
} 
// 1
//从v0到各个节点的距离 
int c[maxn];
//各个节点之间的cost花费情况 
int cost[maxn][maxn];

void DIJ1(int s){
	fill(d,d+maxn,INF);
	vis[s] = 1;
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1;
		int MIN = INF;
		for(int j = 0 ; j < n ; j++){
			if(vis[j] == false && MIN > d[j]){
				MIN = d[j];
				u = j;
			}
		}
		if( u == -1 ) return;
		vis[u] = true;
		//新找到的距离节点进行距离的更新 
		for(int v = 0; v<n;v++){
			if(vis[v]==false && G[u][v] !=INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
				}
				else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
					c[v] = c[u] + cost[u][v];
				}
			}
		}
	}
} 
// 2
// 某个点的物资情况 
int weight[maxn];
// 从V0到某个点的可以收集到的总物资情况 
int w[maxn];
void DIJ2(int s){
	for(int i=0;i<n;i++){
		//序列数组还是需要的 
		pre[i] = i;
		w[i] = 0;
	}
	fill(d,d+maxn,INF);
	d[i] = 0;
	vis[i] = 1 ;
	w[s] = weight[s];
	for(int i=0;i<n;i++){
		int u = -1;
		int MIN = inf;
		for(int j=1;j<=n;j++){
			if( MIN > d[j] && vis[j]== false) {
				u = j;
				MIN = d[j];
			}
			if(u == -1) return;5
			vis[u] = 1;
			for(int v= 0;v<n;v++){
				if(vis[v] == false && G[u][v] != INF){
					if(d[u] + G[u][v] <d[v]){
						d[v] = d[u] + G[u][v];
						//v是所有u可以联通到的点的集合情况 
						w[v] = w[u] + weight[v];
					}
					//距离相等，但是经过这个点也许可以收集到更多的物资 
					else if(d[u] + G[u][v] == d[v] && w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					} 
				}
			}
		}
	}
} 
// 3  
int n;
int G[maxn][maxn];
int d[maxn] = {0};
int pre[maxn];
int num[maxn] ={0};
bool vis[maxn] = {false};

void DIJ3(int s){
	fill(d,d+maxn,INF);
	for(int i =1 ;i<=n;i++){
		pre[i] = i;
	}
	for(int i=0;i<n;i++){
		int u = -1;
		int MIN =INF;
		//从点u到周围的各个点的一个距离情况 
		for(int j = 1;j<=n;j++){
			//如果从来没有遍历过某一个点 
			if(vis[v]== false && MIN > d[j]){
				u = j;
				MIN = d[j];
			}
		}
		if( u == -1 )  return;
		vis[u] = true;
		for(int v = 1; v <= n;v++){
			if(vis[v]== false && G[u][v] != INF) {
				if(d[u]+ G[u][v] <d[v] ){
					d[v] = d[u] + G[u][v];
					num[v] = num[u];
				}
				else if(d[u]+G[u][v] == d[v]) {
					//最短路径+num[u]
					//到达u的最短路径 和 到达v的最短路径 
					num[v] += num[u];
				}
			}
		}
	}

} 
//使用递归的方式进行重建操作 
void DIJ_sequence(int start,int end){
	if(start == end){
		printf("%d\n",start);
		return;
	}
	DIJ_sequence(start,pre[end]); 
	printf("%d\n",end);
}
//
 
int main(){
	
	return 0;
}
