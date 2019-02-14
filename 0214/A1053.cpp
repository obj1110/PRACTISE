#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 110;

vector<int> node[maxn] ;
int w[maxn]  = {0};
//根节点从0到n-1 ,m是非叶节点的个数，tw是目标权重 
int n,m,tw;

bool cmp(int a,int  b) {
	return w[a] > w[b];
}

void init(){
	int id,k,num;
	scanf("%d%d%d",&n,&m,&tw);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&id,&k);
		for(int j = 0;j<k;j++){
			scanf("%d",&num);
			node[id].push_back(num);
		}
		//由于输出的缘故，优先遍历大权重的节点，所以要对vector进行遍历
	}
	//对元素进行排序 
	for(int i=0; i<n;i++) {
		//特别注意这里的写法！！！！！ 
		sort(node[i].begin(),node[i].end(),cmp);
	}
}

//本题只能用深度优先
//三种情况，一个是正好大小，输出并且pop
//一个是小，那就pop
//一个是大，那就push 
vector<int> temp; 
void DFS(int index,int remain){
	if(remain==0){
		for(int i=0;i<temp.size();i++){
			cout<<temp[i];
			if(i != temp.size()-1) cout<<" " ;
		}
		cout<<endl;
		temp.pop_back(); 
		return;
	}
	//剩余的东西，比你的节点权重还小 
	else if(remain < w[index]){
		temp.pop_back();
		return; 
	}
	else if(remain >= w[index]){
		temp.push_back(index);
		remain -= w[index];
		//对当前节点的所有的子节点进行遍历操作 
		for(int j=0;j<node[index].size();j++){
			DFS(node[index][j],remain);
		}
	}
}

int main(){
	init();
//	for(int i=0;i<n;i++){
//		cout<<node[i].size()<<" ";
//		for(int j=0;j<node[i].size();j++){
//			cout<<node[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	//0号节点，剩余24 
	DFS(0,24);
}
