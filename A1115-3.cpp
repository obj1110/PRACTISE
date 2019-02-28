#include<iostream> 
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

//为何结果不对，原因在你的insert函数上面，如果按照BST的插入方法，结果就是不对
//因为本题要求的插入方式是AVL，也就是BST的升级版，平衡二叉树 
const int maxn = 1010;

struct node{
	node* lchild;
	node* rchild;
	int data;	
};
//最极端的情况，一个数据一层 
int layer[maxn];

int n;
//insert的过程本身就是一个一个节点的进行插入,所以参数用int，而不是int数组 
void insert(node* &root,int data){
	//主要是根节点 
	if(root == NULL) {
		root = new node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return;
	}
	//插入左节点，插入右节点  
	if(data < root->data )  insert(root->lchild,data);
	else if(data >= root->data) insert(root->rchild,data);
}

void PreOrder(node* &root,int level){
	if(root==NULL) return;
	layer[level]++;
	PreOrder(root->lchild,level+1);
	PreOrder(root->rchild,level+1);
	return;
}

int main(){
	// 包括读取数据和插入节点 
	memset(layer,0,maxn);
	scanf("%d",&n);
	//用完cin最好吸收空格;
	node* root = NULL;
	// 一旦对root进行操作，
	// 包括 root->lchild 和 root->rchild 这种都会让这个root节点失去自己是空节点的性质
	// 所以这里就单纯的进行声明就可以了 
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		insert(root , temp);
	}
	PreOrder(root,0);
	// 下面可以通过任意方式进行赋值，而不用专门针对某一个。。。 
	int i;
	for(i=0;i<n;i++){
		cout<<layer[i]<<endl;
		if(layer[i] == 0) 
		break;
	}
	printf("%d + %d = %d",layer[i-1],layer[i-2],layer[i-2] + layer[i-1]);
	
	
	return 0;
}
