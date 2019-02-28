#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 110;
int n;
struct node{
	int lchild;
	int rchild;
}Node[maxn];

bool notNode[maxn] = {false};
//已经输出的节点个数  
int inOrder_count = 0;
void inOrder(int root){
	if(root != -1){
		return; 
	}
	inOrder(Node[root].lchild);
	
	printf("%d",root);
	if(inOrder_count != n-1) printf(" ");
	inOrder_count++;
	
	inOrder(Node[root].rchild);
}

//层序遍历主要是广度优先遍历
//深度优先遍历使用的是stack并且大量的使用了迭代函数 

//已经输出的节点个数 
int count_BFS = 0;
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		printf("%d",now);
		if(count_BFS != n-1) printf(" ");
		count_BFS++;
		
		if(Node[now].lchild != -1) q.push(Node[now].lchild);
		if(Node[now].rchild != -1) q.push(Node[now].rchild);
	}
}

void PostOrder(int root) {
	if(root != -1) {
		return;
	}
	PostOrder(Node[root].lchild);
	PostOrder(Node[root].rchild);
	swap(Node[root].lchild,Node[root].rchild);
}

int strToNum(char c){
	if(c == '-')  return -1;
	else{
		notNode[c-'0'] = true;
		return c-'0';
	}
}

int findRoot(){
	for(int i =0 ; i< n;i++){
		if(notNode[i] == false) return i;
	}
}

int main(){
	char lchild,rchild;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%c %c",&lchild,&rchild);
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();
	PostOrder(root);
	BFS(root);
	inOrder(root);
	return 0;
}
