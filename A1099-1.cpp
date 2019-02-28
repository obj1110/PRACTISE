#include<iostream> 
#include<algorithm> 
#include<queue>
#include<vector>

using namespace std;
const int maxn = 110;
struct node{
	int data;
	int lchild;
	int rchild;
}Node[maxn];

int n,data[maxn],cts = 0;

//core 填数字的主力军 
void InOrder(int root){
	if(root == -1){
		return;
	}
	InOrder(Node[root].lchild);
	Node[root].data = data[cts++];
	InOrder(Node[root].rchild);
}

//层序遍历的本质就是BFS，二者等同 
void BFS(int root){
	queue<int> q;
	q.push(root);
	cts = 0;
	while(!q.empty()){
		int now  = q.front();
		q.pop();
		printf("%d",Node[now].data);
	    cts++;
		if(  cts <n ) printf(" ");
		if(Node[now].lchild != -1) q.push(Node[now].lchild);
		if(Node[now].rchild != -1) q.push(Node[now].rchild);
	}
}

int main (){
	int lchild,rchild;
	scanf("%d",&n) ;
	for(int i =0;i<n;i++){
		scanf("%d%d",&lchild,&rchild);
		Node[i].lchild = lchild;
		Node[i].rchild = rchild;
		//非常清晰的树的结构，就是缺data 
	}
	for(int i = 0;i<n;i++){
		scanf("%d",&data[i]);
	}
	sort(data,data+n);
	//要指明root节点所在的位置 
	InOrder(0);
	//一样也是要指明root节点的位置 
	BFS(0);
	return 0;
}
