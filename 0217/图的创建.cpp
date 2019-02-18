#include<iostream> 
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn = 1010;

int v[maxn][maxn];
bool visit[maxn];

int n;

void dfs(int node){
	visit[node] = true;
	for(int i=1;i<=n;i++){
		if(visit[i] == false && v[node][i] == 1) dfs(i);
	}
}

int main(){
	//n是节点总数 m是节点和节点的关系 k是要查询的点 
	int m,k,a,b;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		v[a][b] = v[b][a] = 1;
	}
	for(int i = 0;i <k ;i++){
		fill(visit,visit +1010,false);
		scanf("%d",&a);
		int cnt =0;
		//  
		visit[a]  = true;
		//
		for(int j = 1;j<=n;j++) {
			if(visit[j] == false){
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}
