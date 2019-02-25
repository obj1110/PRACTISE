//A1003一共是两个问题，最短路径的条数，最短路径的点权最大是多少、 
#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;
const int maxn = 510;
const int inf  = 0x3ffffff; 

int n,c1,c2,m;
int G[maxn][maxn];//初始化为inf 
int d[maxn];  //初始化为inf 
bool vis[maxn] = {false};//初始化为false 
int pre[maxn];  //初始化为指向自己 
//从开始位置到达某一个点的最短路径的个数 
int num[maxn]={0}; //初始化为0，也就是0条路径， 
//从开始位置到达某一个点的最大的权重，初始为0 
int w[maxn] = {0};
int weight[maxn];

void init(){
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
		//这种初始化方式很厉害 
		//但是一定注意是G[0] ！！！！ 
	fill(G[0],G[0]+maxn*maxn,inf);
	for(int i=0;i<maxn;i++){
		d[i] = inf;
		pre[i] = i;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	int a,b,c;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		G[a][b] = G[b][a] = c;
	}
}

void dij(int s){
	fill(d,d+maxn,inf);
	for(int i=0;i<n;i++){
		d[i] = inf;
		w[i] = 0;
		num[i] = 0;
	}
	d[s] = 0;
	w[s] = weight[s];
	num[s] =1;
	for(int i =0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j=0;j<n;j++){
			if(min > d[j] && vis[j]== false){
				min = d[j];
				u = j;
			}
		}
		if(u==-1) return;
		vis[u] = true;
		for(int v= 0;v<n;v++){
			if(vis[v] == false && G[u][v]!=inf ){
				if(d[u] + G[u][v] < d[v]){
		 			d[v] = d[u] + G[u][v];
		 			w[v] = w[u] + weight[v];
					pre[v] = u;
					num[v] = num[u];
				}
				else if(d[u] + G[u][v] == d[v]){
					if(weight[v] + w[u] > w[v])	{
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}
int main(){
	init();
	dij(c1);
	printf("%d %d\n",num[c2],w[c2]); 
	return 0;
}
