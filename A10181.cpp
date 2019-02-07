#include<iostream> 
#include<algorithm>
#include<vector> 
#include<cstring> 

using namespace std;
const int inf = 0x7fffffff;

int C[510];
struct Node{
	int v;//顶点 
	int w;//权重 
	//构造函数 
	Node(){};
	//构造函数 
	Node(int a,int b):v(a),w(b){};
};
vector<Node> adj[510];

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

	memset(C,-1,sizeof(C));
	
	//当前车站的数目 
	for(int i=0;i<N;i++) {
		scanf("%d",&C[i]);
	}
	//
	 
	//道路的情况
	int a,b,c;
	for(int i=0;i<M;i++) {
		//v是目标顶点，w是权重 
		scanf("%d%d%d",&a,&b,&c);
		adj[a].push_back(Node(b,c));
		adj[b].push_back(Node(a,c));
	}
	//
	 
	//
	for(int i =0;i <= N;i++){
		for(int j =0;j<adj[i].size();j++){
			cout<<adj[i][j].v<<" "<<adj[i][j].w<<endl;	
		}
		cout<<endl;
	}
}
