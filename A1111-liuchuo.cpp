其实很简单，你自己打一遍试试就是知道了，就是晴神的那个模板
不要试图将这个题目一次写完，而是首先写一种路径的遍历，然后写另外一种路径的遍历。
 
void dfs(int s) {
	fill(d,d+maxn,inf);
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j =0;j<n;j++) {
			if( vis[j] == false && min > d[j]){
				d[j] = min;
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v=0;v<n;v++) {
			 if(vis[v] == false && G[u][v] == inf){
			 	if(d[u] + G[u][v] < d[v]){
			 		d[v] = d[u] + G[u][v];
			 		pre[v] = u;
				}
				else if(d[u] + G[u][v] == d[v]){
					if(weight[v] + w[u] > w[v]){
						w[v]  = weight[v] + w[u];
					}
				}
			 }
		}
	}
}
