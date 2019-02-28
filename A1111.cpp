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
int dt[maxn] = {0};

vector<int> prel[maxn];
vector<int> pret[maxn];
bool visl[maxn] = {false};
bool vist[maxn] = {false};

vector<int> pathl;
vector<int> patht;
vector<int> templ;
vector<int> tempt;

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

void dijt(int s){
	fill(dt,dt+maxn,inf);
	dt[s] =0;
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j=0;j<n;j++){
			if(vist[j]== false &&min > dt[j]){
				min = dt[j];
				u = j ;
			}
		}
		if(u == -1) return ;
		vist[u] = true;
		for(int v= 0;v<n;v++) {
			if(t[u][v] != inf && vist[v] == false){
				if(dt[u] + t[u][v] < dt[v]){
					dt[v] = dt[u] + t[u][v];
					pret[v].clear();
					pret[v].push_back(u);
				}
				else if(dt[i] + t[u][v] == dt[v]){
					pret[v].push_back(u);
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

void DFSt(int v){
	if(v != st){
		tempt.push_back(v);
		int value = tempt.size();
		//计算value
		//将当前路径和最短路径相比较，但注意比较的是节点的个数 
		if(value < optvaluet ){
			optvaluet = value;
			patht = tempt;
		} 
		tempt.pop_back();
		return;
	} 
	tempt.push_back(v);
	for(int i=0;i<pret[v].size();i++){
		DFSt(pret[v][i]);	
	}
	tempt.pop_back();
}

void print() {
	for(int i=0;i<pathl.size();i++) {
		cout<<pathl[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<patht.size();i++){
		cout<<patht[i]<<" ";
	}
}

int main() {
	init();
	/////////////////////
	//输出部分，长度最短和时间最短
	//如果路径最短的不唯一，就输出最快的；---1 
	//如果最快的也不唯一，就输出经过节点数最少的 ---2 
	//如果长度路径和时间路径是一样上的，就特殊的输出 ---1,2 
	dijl(st);
	dijt(st);
	DFSl(des);
	DFSt(des);
	print();
	return 0;
}
