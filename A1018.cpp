#include<iostream> 
#include<algorithm>
#include<vector> 

using namespace std;
const int inf = 0x7fffffff;
int e[510][510]; //道路之间的距离 
int dis[510];    
int weight[510];
bool visit[510];
vector<int> pre[510],path,temppath;

void dfs(int v){
	if(v == 0){
		
	}
}

//从PMBC到达规定车站的最短路径
//最短路径中选择送车最少的那个
//pmbc自己没有上限

int main(){
	int Cmax; //偶数 ,车站最大容量 
	int N; //从1开始，而不是从0开始 ,车站的个数 
	int M;//道路的个数
	int S; //问题车站的序号，也就是终点 
	scanf("%d%d%d%d",&Cmax,&S,&N,&M);
	//正好把PMBC当做0号来存储 
	
	//当前车站的数目 
	for(int i=0;i<N;i++) {
		scanf("%d",&C[i]);
	}
	//道路的情况
	int a,b,c;
	for(int i=0;i<M;i++) {
		scanf("%d%d%d",&a,&b,&c);
	}
}
