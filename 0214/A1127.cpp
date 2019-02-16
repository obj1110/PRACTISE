//原来的层序遍历，从使用queue到使用stack，
//emmm似乎不是一个stack而是两个stack 

//首先是根据中序和后序队列建树
//所以用数组来静态存储二叉树比较好  
#include<iostream> 
#include<stack>
#include<cstring>
#include<cstdlib>
// The second line gives the inorder sequence 
// and the third line gives the postorder sequence
using namespace std;
const int maxn = 35;

stack<int> st1,st2;
int n,temp;
//一个是前序序列，一个是后序序列 
int in[maxn],post[maxn];
//左子树和右子树 
int tree[maxn][2];

//如何根据一个中序和后序队列进行建树？？
//当然是用递归的形式进行操作了 
struct Node{
	int lchild;
	int rchild;
	int data;
}node[maxn]; 

void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
}

//其实这就是一个递归建树的过程
//或者说是一层一层 
void dfs(int& index,int inleft,int inright,int postleft,int postright){
	//死胡同 
	if(inleft > inright )  return;
	//如果说只剩下一个节点，就执行插入工作	
	index  = postright;
	//寻找中序序列中和后序最后一个元素等value的元素序号 
	int i = 0;
	while(in[i] != post[postright]) i++;
	//左子树的元素个数 
	int left_num = i - inleft; 
	
	//下面的dfs操作不要包括进入根节点 
	//对左子树进行操作 ,对后序序列的遍历就是从右子树的第一个点开始，加上左子树的个数 
	dfs(tree[index][0], inleft , i-1 ,  postleft, postleft + left_num -1);
	//对右子树进行操作
	dfs(tree[index][1], i+1 , inright , postleft + left_num, postright - 1);
	//也就是计算右子树的元素的个数 
}

int main(){
	memset(pre,-1,maxn);
	memset(post,-1,maxn);
	init();
	
	return 0;
}
