#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
const int maxn = 110;

//typedef struct Node{
//	Node*lchild;
//	Node*rchild;
//	int data;
//}node;

struct node{
	int lchild;
	int rchild;
	int data;
}Node[maxn];

int n;
int data[maxn];

//所有的结点都是从0开始，然后到n-1结束 
void init(){
	scanf("%d",&n);
	int a,b,temp;
	for(int i=0;i<n;i++) {
		scanf("%d %d",&a,&b);
		Node[i].data = i;
		Node[i].lchild = a;
		Node[i].rchild = b;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	sort(data,data+n);
}

//root指的是节点的index 
int index = 0;
void InOrder(int root){
	if(root == -1) return;
	InOrder(Node[root].lchild);
	Node[root].data = data[index++];
	InOrder(Node[root].rchild);
	return;
}

//层序遍历本质上就是一个BFS的操作，广度优先的操作 
//全局变量，统计输出的个数 
int cts = 0;

void Level(int root){
	//进行层序遍历操作
	queue<int> q;
	q.push(root);
	//如果队列中还有元素的话 
	while(!q.empty()){
		int index = q.front();
		q.pop();
		//打印
		printf("%d",Node[index].data);
		cts++;
		if(cts != n) printf(" ");
		//BFS不需要递归
		if(Node[index].lchild != -1) q.push(Node[index].lchild);
		if(Node[index].rchild != -1) q.push(Node[index].rchild);
	}
}

int main(){
	init();
	InOrder(0);
	Level(0);
	return 0;
}
