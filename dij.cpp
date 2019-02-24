#include<iostream> 
#include<vector>
#include<cstring> 
#include<cstdlib>
using namespace std;

const int INF = 0x3fffff;

//首先全部变成INF距离 
int G[maxn][maxn];
//表示从v0到每一个点的距离情况 
int d[maxn];
//表示从在这个DIJ算法中有没有遍历过某些点 
bool vis[maxn] = {false};

void Dij(int s) {
	fill(d,d+maxn,INF);
	vis[s] =  
}

int main(){
	return 0;
}
