#include<iostream> 
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;

const int maxn = 100100;
const int inf = 0x3fffff;

void Dijstra(){
	
}

void Dij(int start){
	fill(d,d+maxn,INF);
	d[start] = 0;
	for(int i=0;i<n;i++) {
		int u = -1;
		int MIN = INF;
		for(int j = 0;j<n;j++){
			u = j;
			MIN = d[j];
		}
		if( u== -1) return;
		vis[u] = true;
		for(int v= 0;v<n;v++){
			if(vis[v] == false && G[u][v] != INF && d[u]+ G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
			}
		} 
	}
}

void DijAdv(int start){
	//首先还是把这个距离数组全部设置为INF 
	fill(d,d+maxn,INF);
	//然后就是把一个pre数祖进行初始化，首先指向的就是自己本身 
	for(int i=0;i<n;i++){
		pre[i] = i;
	}
	//然后就是对于距离数组，当前节点的初始化，实际上是遍历v0 
	d[s] = 0;
	//然后就是剩余节点一个一个加进来 
	for(int i=0;i<n;i++) {
		//首先寻找最短的距离 
		int u = -1;
		int MIN = INF;
		//最短的距离就是d[j]，也就是首先寻找最短的距离是哪一个元素 
		for(int j = 0;j<n;j++){
			if(vis[j] == false && d[j] <MIN){
				u = j;
				MIN = d[j];
			}
		}
		//剪枝 
		if(u == -1) {
			return;
		}
		//
		vis[u] = true;
		//对于和u（最小距离）相连的每一个节点 
		for(int v =0;v<n;v++) {
			if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] <d[v]){
				d[v] = d[u] + G[u][v];
				//如果涉及到距离的更新，还要考虑到就是点之间的前后关系 
				pre[v] = u;
			} 
		}
	}
}
