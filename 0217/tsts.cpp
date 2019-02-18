#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int maxn = 1010;
//两个点之间的联系 
int v[maxn][maxn];
//指的是这个点是不是曾经遍历过 
bool visit[maxn];
int n; 

//对图进行深度优先遍历 
void dfs(int node){
	//对节点进行遍历的操作 
	visit[node] = true;
	for(int i =0;i<=n;i++) {
		if(visit[i] == false && )
	}
}

int main(){
	
}
