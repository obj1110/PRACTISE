//首先本题不是二叉树而是一个多叉树 
//1090 不需要使用什么struct，而本题是需要使用结构体，不是说这两个题存在什么本质上的差别，而是说这两个题的节点不同
//1090的节点没有任何的附加信息，而1079的节点存在着大量的附加信息 

//1094就是寻找节点数最多的深度，也就是遍历每一个层次，对不同的节点赋值不同的深度，一方面可以实时记忆深度，另一方面，也可全部遍历完之后，另行处理。


//1094对于深度节点数的记忆，除了使用int数组构造的hashTable之外，还可以使用map 
#include<iostream> 
#include<vector>
#include<map> 

using namespace std;

const int maxn = 110;

//树的静态写法就是数组
//树的动态写法就是用链表加指针 
vector<int> Node[maxn] ;
int hashTable[maxn] = {0};

void DFS(int index,int depth){
	hashTable[depth]++;
	//统计每一个节点的子节点，因为是树不是二叉树，所以这样做 
	for(int j =0;j < Node[index].size();j++){
		DFS(Node[index][j],depth+1);
	}
}

//int father,root;
//
//double p,r,ans;//p是价格，r是ratio比例,ans是总价值 
//
//// 全局变量，用于减少运算量 
////numf代表最大深度的节点个数  
//int n,maxDepth,num,k,child; 
//
//
////二叉树的静态数组存储方式的形式大概就是一个二维数组，第一个维度代表节点
////第二个维度代表这个节点的子节点的情况 
//void DFS(int index,int depth){
//	//如果是叶节点 
//	if(Node[index].child.size() == 0 ) {
//		ans += Node[index].data * pow(1+r,depth);
//		//一旦触及子节点就要返回了 
//		return ;
//	} 
//	//如果不是叶节点 
//	else if( Node[index].child.size() != 0 ) {
//		for(int i = 0;i < Node[index].child.size();i++) {
//			DFS(Node[index].child[i],depth+1);
//		}
//	}
//}


//输入的部分
//0号节点固定是root
//首先给出子节点的个数，如果子节点的个数是0 ，那么后面的数字就是子节点的货物量
//如果子节点的个数不是0, 那后面的东西就是子节点的id号，把这些id号放在二维数组的第二个维度上
//二叉树的静态构成
 


int main(){
	
	int n,m,parent,k,child;
	scanf("%d%d",&n,&m);
	for(int i =0 ;i<m;i++){
		scanf("%d %d",&parent,&k);
		for(int j = 0; j<k;j++){
			scanf("%d",&child);
			Node[parent].push_back(child);
		}
	}
	//本题的初始节点是1，初始深度0或者1都可以 
	DFS(1,1);//0号节点，深度是0
	int maxLevel = -1;
	int maxValue = 0;
	for(int i=0;i<maxn;i++) {
		if(hashTable[i] > maxValue){
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}
	printf("%d %d\n",maxValue,maxLevel);
	return 0;
}
