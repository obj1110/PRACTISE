//����Ҷ�ӽڵ�ĸ��� 
#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;

const int maxn = 110;
//n��Ҷ�ڵ�ĸ���,m�Ƿ�Ҷ�ӽڵ�ĸ��� 
int n,m,max_level = -1;

vector<int> node[maxn]; 
int cts[maxn] = {0};
//���ڵ��ʵ������Ǵ�01��ʼ 
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
		//������ͬ�ˣ�Ҫ���ذ� 
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
	//����Ķ�����ÿһ���Ҷ�ӽڵ�ĸ�����ÿ�㶼Ҫ��� 
	DFS(1,0);
	for(int i=0;i<=max_level;i++){
		printf("%d",cts[i]);
		if(i != (max_level)){
			printf(" ");
		}
	} 
}
