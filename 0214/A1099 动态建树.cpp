#include<iostream> 
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn = 110;
int data[maxn];
int n,cts,num;

struct node{
	int data, lchild,rchild;
}Node[maxn];

void InOrder(int root) {
	if(root == -1){
		return;
	}
	InOrder(Node[root].lchild);
	Node[root].data = data[cts++];
	InOrder(Node[root].rchild);
}

//对于这个东西的广度优先跟层序遍历还不一样啊 
void BFS(int root){
	queue<int> q;
	q.push(root);
	num = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		printf("%d",Node[now].data);
		num++;
		if(num < n) printf(" ");
		if(Node[now].lchild != -1) q.push(Node[now].lchild);
		if(Node[now].rchild != -1) q.push(Node[now].rchild);
	}
}

int main(){
	int lchild,rchild,data;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&lchild,&rchild);
		Node[i].lchild = lchild;
		Node[i].rchild = rchild;
	}
	for(int i = 0; i<n ; i++ ){
		scanf( "%d" , &data[i] );
	}
	sort(data,data+n);
	//用中序遍历的过程顺便建立一下树
	InOrder(0);//从0号节点开始中序遍历 
	 
	BFS(0);//从0号节点开始进行层序遍历 
	return 0;
}
