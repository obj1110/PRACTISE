//计算叶子节点的个数 
#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;

const int maxn = 110;
//n是叶节点的个数,m是非叶子节点的个数 
int n,m,max_level = -1;

vector<int> node[maxn]; 
int cts[maxn] = {0};
//根节点的实际情况是从01开始 
void init() {
	scanf("%d %d",&n,&m);
	int id,k,child;
	for(int i=0;i<m;i++){
		scanf("%d %d",&id,&k);
		for(int j =0;j<k;j++) {
			scanf("%d",&child); 
			node[id].push_back(child);
		}
	}
	
}
//special 
//The input ends with N being 0. That case must NOT be processed.
void DFS(int index,int level){
	if(node[index].size() == 0){
		cts[level]++;
		if(level > max_level) max_level = level;
		//到死胡同了，要返回啊 
		return;
	}
	else if(node[index].size() != 0){
		for(int j=0;j<node[index].size();j++) {
			DFS(node[index][j],level+1);
		}
	}
}
 
int main(){
	init();
	//输出的东西是每一层的叶子节点的个数，每层都要输出 
	DFS(1,0);
	for(int i=0;i<=max_level;i++){
		printf("%d",cts[i]);
		if(i != (max_level)){
			printf(" ");
		}
	} 
}
