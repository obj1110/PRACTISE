#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 10010;
int v[maxn][maxn]={0};
bool vis[maxn] = {false};
int depth[maxn];
int result[maxn]={0};
int n,a,b;

void dfs(int index) {
	if(vis[index] == 0)
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		v[a][b] = v[b][a] = 1;
	}
	//联通分量  
	int cts = 0;
	//计数变量，i是当前开始遍历的根节点 
	for(int i=1;i<=n;i++) {
		vis[i] = true;
		for(int ) 
	}
	return 0;
}
