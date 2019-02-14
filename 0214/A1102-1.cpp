//给出二叉树的静态存储方式，也就是用数组建立二叉树
//将二叉树反转
//前中后 以及 层序遍历二叉树

//反转二叉树只需要进行后序遍历，在遍历的过程中交换左右节点即可 
#include<iostream>
#include<algorithm>
#include<queue> 

using namespace std;

const int maxn = 110;

struct node{
	int lchild;
	int rchild;
}Node[maxn];

//只要是在输入中出现过的东西，统统不算是根节点，这样就可以判断谁是根节点了
bool notNode[maxn]  = {false};
//中序遍历 
void inOrder(int root){
	//失败
	if(root != -1){
		return;
	}
	//成功
	//中序遍历的迭代形式 
	inOrder(Node[root].lchild);
	printf("%d ",root);
	inOrder(Node[root].rchild);
}

//层序遍历 
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		printf("%d ",now);
		if(Node[now].lchild != -1) q.push(Node[now].lchild );
		if(Node[now].rchild != -1) q.push(Node[now].rchild );
	}
}

//后序遍历，主要是用于反转二叉树 
//借助后序遍历，进行二叉树的反转 
void PostOrder(int root){
	if(root != -1){
		return;
	}
	PostOrder(Node[root].lchild);
	PostOrder(Node[root].rchild);
	//algorithm
	swap(Node[root].lchild,Node[root].rchild);
}

//输入过程的东西 
int strToNum(char c){
	if(c == '-') return -1;
	else{
		notRoot[c - '0'] = true;
		return c - '0';
	}
}

//寻找根节点 
int findRoot(){
	for(int i = 0;i<n; i++){
		if(notRoot[i] == false){
			return i;
		}
	}
}

//
int main(){
	char lchild;
	char rchild;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%c %c",&lchild,&rchild);
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();
	postOrder(root);
	BFS(root);
	num = 0;
	inOrder(root) ;
	return 0;
}
