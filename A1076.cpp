///1076 有向图的广度优先遍历 
//一个人可以指向别人，别人也可以指向自己 

//从某一个点出发，遍历固定的深度，能涉及到多少人呢？？？？？ 

//注意：本题的点的序号从1开始 

//思路：深度优先遍历，给每一个点计算它的深度，最后单独统计
//思路：在遍历的同时计算深度，到达一定的深度之后，直接返回
//同时设计一个全局变量统计个数 
#include<iostream> 
#include<vector>
#include<algorithm> 
#include<queue> 

using namespace std;
const int maxn = 1010;
//注意，本题是有向图，也就是说[a][b]表示的是从a到b 

int v[maxn][maxn] = {0};
int N,L,M,K,index; 

int BFS(int index,int depth) {
	
	int vis[maxn] = {0};
	int cnt = 0;
	queue<int> q1;
	queue<int> q2; 
	
	q1.push(index);
	vis[index] = 1;
	while((!q1.empty() || !q2.empty()) && depth <= L){
		while(!q1.empty()){
			int id = q1.front();
			q1.pop();	
			cnt++; 
			for(int i = 1;i<=N;i++){
				if(v[id][i] == 1 && vis[i] == 0) {
					q2.push(i);
					vis[i] = 1;
				}
			}	 
		}
		depth++;
		if(depth >L ) return cnt;
		while(!q2.empty()){
			int id = q2.front();
			q2.pop();
			cnt++; 
			for(int i = 1;i<=N;i++){
				if(v[id][i] == 1 && vis[i] == 0) {
					q1.push(i);
					vis[i] = 1;
				}
			}	
		}
		depth++;
	}
	return cnt;
}

int main(){
	scanf("%d%d",&N,&L);
	//i是点 
	int temp;
	for(int i=1 ;i<=N;i++) {
		scanf("%d",&M);
		//j是计数变量 
		for(int j=0;j<M;j++){
			scanf("%d",&temp);
			//从i到temp是通的  
			v[i][temp] = 1;
		}
	}
	//查询行 
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d",&index);
		printf("%d\n",BFS(index,0)-1 );
	}
	return 0;
}
