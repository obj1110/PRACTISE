#include<iostream> 
#include<cstring>
#include<algorithm>

using namespace std;

bool visit[1010];
bool v[1010][1010];
int N;

void dfs(int n){
	visit[n] = true;
	for(int i =0;i<=N;i++){
		if(visit[i]==false && v[i][n]==true) dfs(i);
	}
}

int main(){
	int m,k;
	scanf("%d%d%d",&N,&m,&k);
	int a,b,c;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		v[a][b] = v[b][a] =true;
	}
	//
	for(int i=0;i<K;i++){
		memset(visit,false,1010);
		//假如说C是要查询的城市 
		scanf("%d",&c);
		int cnt= 0;
		visit[c] = true;
		for(int j=1;j<=n;j++){
			if(visit[j] == false){
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;	
}
