#include<iostream> 
#include<algorithm> 
#include<cstring>
using namespace std;

const int maxn = 10010;

int v[maxn][maxn]={0};

int n,a,b,cnt = 0;
bool isTree = false;
int depth[maxn]; 
int visit[maxn];
int result[maxn]; 

int dfs(int index,int depth){
	int liantong = 1;
	visit[index] = 1;
	for(int i=1;i<=n;i++) {
		if( v[index][i]==1 && visit[index] == 0){
			dfs(i,depth+1);
		}
	}
}

int main(){
	scanf("%d",&n);
	//遍历进来n-1行的数据 
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b); 
		v[a][b] = v[b][a] = 1;
	}
	for(int i=1;i<=n;i++){
		//所有点的深度都是-1  
		memset(depth,-1,maxn);
		//所有点都没有被便利过 
		memset(visit,0,maxn);
		//从i点开始，他是第一层 
		dfs(i,1);
		int max_depth = 0; 
		for(int j=1;j<=n;j++) {
			if(depth[j] == -1){
				//需要计算联通分量 
				isTree = false;
				cnt = 2;
				printf("Error: %d components",cnt);
				return 0;
			}
			if(depth[j] > max_depth){
				max_depth = depth[j];
			}
		}
		result[i] = max_depth;
	}
 	for(int i=1;i<=n;i++) {
 		cout<<result[i]<<" ";
	}
	return 0;
}
