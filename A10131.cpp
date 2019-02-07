#include<iostream> 
#include<algorithm>
#include<vector> 

//尝试用邻接链表改写1013 
using namespace std;
vector<vector<int>> G;
int vis[1010];

int N,M,K,temp1,temp2;
void DFS(int node){
	vis[node] = 1;
	for(int i=1;i<G[node].size();i++){
		if(vis[G[node][i]]==0){
			DFS(i);
		}
	}
}

int main(){
	cin>>N>>M>>K;
	G.resize(N+10);
	for(int i=0;i<M;i++){
		scanf("%d%d",&temp1,&temp2);
		G[temp1].push_back(temp2);
		G[temp2].push_back(temp1);
	} 
	for(int i=0;i<K;i++){
		scanf("%d",&temp1);
//		fill or memcpy
		fill(vis,vis+N,0);
		vis[temp1] = 1;
		int cts =0; 
		for(int i=1;i<=N;i++){
			if(vis[i]==0 && i!=temp1){
				DFS(i);
				cts++;
			}
		}
		printf("%d\n",cts-1);
	}
	return 0;
}
