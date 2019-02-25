void dij(int s){
	fill(d,d+maxn,inf);
	vis[s] = 1 ;
	d[s] = 0;
	for(int i=0;i<n;i++){
		if(vis[j] == false&& MIN >d[j]){
			min = d[j];
			u = j;
		}
	}
	if(u == -1) return;
	vis[u] = true;
	for(int v= 0;v<n;v++){
		if(vis[v]== false  && G[u][v] + d[u] <d[v]){
			d[v] = d[u] + G[u][v];
			pre[v] = u;
		}
	}
} 

int c[maxn];
int cost[maxn];

void DIJ1(int s){
	fill(d,d+maxn,inf);
	vis[s] = 1;
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u =-1;
		int min = inf;
		for(int j=0;j<n;j++){
			if(vis[j]== false && min >d[j]){
				min = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v =0;v<n;v++){
			if(vis[v]== false && G[u][v] !=INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
				}
				else if(d[u] + G[u][v] == d[v] && c[u] +cost[u][v] <c[v]){
					c[v] = c[u] + cost[u][v];
				}
			}
		}
	}
}

for(int v = 0;v<n;v++){
	if(vis[v]==false && G[u][v]!=inf){
		if(d[u] + G[u][v] < d[v]){
			d[v] = d[u] + G[u][v];
			c[v] = c[u] + cost[u][v];
		}
		else if(d[u] + G[u][v] == d[v] && cost[])
	}
}
