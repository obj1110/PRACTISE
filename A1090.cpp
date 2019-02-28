//首先本题不是二叉树而是一个多叉树 

#include<iostream> 
#include<algorithm>
#include<queue>
#include<stack> 
#include<cmath> 
#include<vector>

using namespace std;

const int maxn = 100010;
int father,root;
	
//child数组存放的是每一个节点的子节点包括什么 
vector<int> child[maxn] ;
double p,r;//p是价格，r是ratio比例
// 全局变量，用于减少运算量 
//numf代表最大深度的节点个数  
int n,maxDepth,num; 


//二叉树的静态数组存储方式的形式大概就是一个二维数组，第一个维度代表节点
//第二个维度代表这个节点的子节点的情况 
void DFS(int index,int depth){
	//如果是叶节点 
	if(child[index].size() == 0 ) {
		if(depth > maxDepth) {
			maxDepth  = depth;
			num = 1;
		}
		else if(depth == maxDepth){
			num++;
		}
		//一旦触及子节点就要返回了 
		return ;
	} 
	//如果不是叶节点 
	else if(child[index].size() != 0) {
		for(int i = 0;i<child[index].size();i++) {
			DFS(child[index][i],depth+1);
		}
	}
}

void init(){
	//注意double对应的类型是lf而不是f 
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100.0;
	for(int i=0;i<n;i++){
		scanf("%d",&father);
		if(father != -1){
			child[father].push_back(i);
		}
		else{
			root = i;
		}
	}
}

int main(){
	init();
	
	//根节点和深度 
	DFS(root,0);	
	printf("%.2f %d\n", p*pow(1+r , maxDepth),num);
	return 0;
}
