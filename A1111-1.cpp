//本题相当于是对两个不同的图进行两次dij算法，代码量较大 
//所以，就按照DIJ+DFS进行遍历，首先输出时间最短的路径和路程最短的路径 

//到达某一个节点的时候，经过的节点个数 是可以遍历得到的  
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 520;
const int inf = 0x3fffffff;
//n是点的个数，m是街道的个数 
int n,m,v1,v2,one_way,length,time,st,des;
int optvaluel= inf,optvaluet= inf ;

int t[maxn][maxn];
int l[maxn][maxn];
int dl[maxn] = {0};

vector<int> prel[maxn];
bool visl[maxn] = {false};

vector<int> pathl;
vector<int> templ;

void init(){
	fill(t[0],t[0]+maxn*maxn,inf);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		scanf("%d %d %d %d %d",&v1,&v2,&one_way,&length,&time);
		if(one_way == 1){
			l[v1][v2] = length;
			t[v1][v2] = time;
		}
		else{
			l[v1][v2] = l[v2][v1] = length;
			t[v1][v2] = t[v2][v1] = time;
		}
	}
	scanf("%d%d",&st,&des);
}

void dijl(int s){
	fill(dl,dl+maxn,inf);
	dl[s] =0;
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j=0;j<n;j++){
			if(visl[j]== false &&min > dl[j]){
				min = dl[j];
				u = j ;
			}
		}
		if(u == -1) return ;
		visl[u] = true;
		for(int v= 0;v<n;v++) {
			if(l[u][v] != inf && visl[v] == false){
				if(dl[u] + l[u][v] < dl[v]){
					dl[v] = dl[u] + l[u][v];
					prel[v].clear();
					prel[v].push_back(u);
				}
				else if(dl[i] + l[u][v] == dl[v]){
					prel[v].push_back(u);
				}
			}
		}
	}
}

void DFSl(int v){
	if(v != st){
		templ.push_back(v);
		int value = 0 ;
		//都是最短路径 
		for(int i=0;i < templ.size()-1;i++){
			int id = i;
			int idnext =i+1;
			value += t[id][idnext];
		} 
		//计算value
		//将当前路径和最短路径相比较,但注意比较的是时间 
		if(value < optvaluel ){
			optvaluel = value;
			pathl = templ;
		} 
		templ.pop_back();
		return;
	} 
	templ.push_back(v);
	for(int i=0;i<prel[v].size();i++){
		DFSl(prel[v][i]);	
	}
	templ.pop_back();
}

void print() {
	cout<<pathl.size()<<endl;
	
	for(int i=0;i<pathl.size();i++) {
		cout<<pathl[i]<<" ";
	}
}

int main() {
	init();
	dijl(st);
	DFSl(des);
	print();
	return 0;
}
