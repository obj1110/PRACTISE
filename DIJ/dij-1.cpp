#include<iostream>

int d[maxn]
int G[maxn][maxn];
bool vis[maxn] = {false};

int pre[maxn];
//最短路径个数 
int num[maxn];
//最多或者最少点权 
int weight[maxn];
int w[maxn];
//最多或者最少花费 
int cost[maxn];
int c[maxn];

//////////////////原版的dij算法，将第一要素和第二要素共同进行判断 
void init() {
	fill(G[0],G[0]+maxn*maxn,inf);
	for(int i=0;i<n;i++){
		pre[i] = i;
		num[i] = 0;
		w[i] = 0 ;
		c[i] = 0 ;
	}
	fill(d,d+maxn,inf);
}
void dij(int s){
	fill(d,d+maxn,inf);
	d[s] = 0;
	w[s] = weight[s];
	c[s] = 0;
	num[s] = 1;
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j= 0;j<n;j++){
			if(vis[j]== false  && min > d[j]) {
				min = d[j];
				u = j;
			}
		} 
		if(u == -1) return;
		//////只有这一个地方允许更换你的vis元素的值，其余的情况，vis不参与 
		vis[u] = 1;
		/////////////////////////////////////////////////
		for(int v= 0;v<n;v++){
			if(vis[j]==false && G[u][v] != inf){
				if(d[u] + G[u][v] < d[v]){
					d[v] = G[u][v] + d[u];
					pre[v] = u;
					num[v] = num[u];
					w[v] = w[u] + weight[u][v];
				}
				else if(d[u] + G[u][v] == d[v]){
					if(w[u] + weight[v] > w[v]){
						w[v] = w[u] + weight[u];
					}
					num[v] += num[u];
				}
			}
		}
	}
}
void DFS_traverse(int start ,int end ){
	
	
	if(start == end) {
		printf("%d\n",start);
		return;
	}
	else{
		DFS_Traverse(start,pre[end]) ;
		printf("%d\n",end); 
	} 
}

//////////////////改版的dij算法，首先就找最短路径，但是要记录前驱情况， 
vector<int> pre[maxn] ;
void dij(int a){
	fill(d,d+maxn,inf);
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1;
		int MIN = inf;
		for(int j =0;j<n;j++){
			if(vis[j]== false && d[j] < MIN){
				u = j;
				MIN =d[j];
			}
		}
		if( u== -1) return;
		vis[u] = true;
		for(int v =0;v<n;v++){
			if(vis[v]== false && G[u][v] != inf){
				if(G[u][v] + d[u] < d[v])	{
					d[v] = G[u][v] +d[u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(G[u][v] + d[u] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
///////////////////////////之后就是恢复一个原来的最佳的路径
int optvalue;//也就是最佳值 
vector<int> pre[maxn] ;///pre数组，本质上类似于一个邻接链表，是一个二维数组 
vector<int> path,tempPath;//全局最优解和当前的局部解 
void DFS(int end) {
	//死胡同，如果已经递归到了一个整个图的开始V0 
	if(end == start) {
		tempPath.push_back(end);
		int value;
		//根据这个路径，来计算value 
		if(value > optvalue){
			optvalue = value;
			path = temppath;
		}
		temppath.pop_back();
		//到了终点，应该返回了 
		return;
	}
	//也就是一般的分支或者是岔路口 
	else{
		temppath.push_back(end);
		for(int i=0;i<pre[end].size();i++){
			//对每一条路径进行递归操作 
			DFS(pre[end][i]);
		}
		//便利完毕当前的节点就将当前的节点删除？？？？ 
		temppath.pop_back();
	} 
}
