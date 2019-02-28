#include<iostream>
using namespace std;

//最多100条线，每条线最多100个车站 
const int maxn = 10000;
const int inf = 0x3ffffff;

int G[maxn][maxn];
int d[maxn];
bool vis[maxn] = {false};
int temp[120] = {0};

void init(){
	fill( d , d+maxn , inf );
	scanf("%d",&n);
	for(int line =1 ; line <= n ; line++){
		scanf("%d",&m);
		for(int j = 1 ; j <= m ; j++){
			scanf("%d",&temp[j]);
		}
		for(int i=1;i<m;i++){
			G[temp[i]][temp[i+1]] = G[temp[i+1]][temp[i]] = 1;
		}
	}
}

void dij(int s){
	fill(d,d+maxn,inf);
	fill(vis,vis+maxn,false);
	d[s] = 0;
	for(int i=0 ; i < n;i++){
		int u = -1;
		int min = inf;
		for(int j=1 ;j<n;j++){
			if( min >d[j] && vis[j] == false){
				d[j] = min;
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 1;v<n;v++){
			if(d[u] + G[][])
		}
	}
}

int main(){
	
}
