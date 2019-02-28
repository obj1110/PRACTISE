#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10010;
int n,maxheight = 0;
vector<vector<int>> v;
bool visit[maxn];

set<int> s;
vector<int> temp;
void dfs(int node,int height) {
	if(height > maxheight){
		temp.clear();
		temp.push_back(node);
		maxheight = height;
	}
	else if(height == maxheight){
		temp.push_back(node);
	}
	visit[node] = true;
	for(int i=0 ;i<v[node].size();i++){
		if(visit[v[node][i]] == false){
			dfs(v[node][i],height+1);
		}
	}
}
