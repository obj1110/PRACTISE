#include<iostream> 
#include<vector>
#include<cstring> 
#include<cstdlib>
using namespace std;

const int INF = 0x3fffff;

//首先全部变成INF距离 
int G[maxn][maxn];
//表示从v0到每一个点的距离情况 
int d[maxn];
//表示从在这个DIJ算法中有没有遍历过某些点 
bool vis[maxn] = {false};
int pre[maxn];

void Dij(int s) {
	for(int i=0;i<maxn;i++) {
		pre[i] = i;
		d[i] = INF;
	}
	fill(d,d+maxn,INF);
	d[s] = 0;
	for(int i=0 ; i<n ; i++) {
		int u = -1;
		int MIN = INF;
		//也就是对所有的节点中寻找最小距离的点 
		for(int j=0;j<n;j++){
			if(vis[j]== false && d[j]< MIN) {
				//对距离尽心更新 
				MIN = d[j];
				u = j;
			}
		}
		if(u == -1 ) return ;
		vis[u] = true;
		for(int v = 0;v<n;v++){
			if(vis[v] == false && G[u][v] != INF && d[u]+ G[u][v] < d[v]){
				d[v]  =d[u] +G[u][v];
				pre[v] = u;
			}
		}
	}
}

//如果v就是这个节点 
void Dij_sequence(int s){
	if (v == s) {
		printf("%d\n",s);
		return;
	}
	DFS(s,pre[v]);
	printf("%d\n",v);
}
 
void DFS_Sequence(int start,int end){
	if(end == start){
		//打印起点 
		printf("%d\n",start);
		return;
	}
	DFS_Sequence(start,pre[end]);
	//递归进行打印，首先打印出来的是跟start最近的点 
	printf("%d\n",end);
}



int main(){
	return 0;
}
