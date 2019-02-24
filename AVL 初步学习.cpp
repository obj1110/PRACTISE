//AVL中的平衡因子表示的是左右子树之间的差距 可以有正负 
#include<iostream> 
#include<vector> 
#include<algorithm>
using namespace std;

//计算平衡因子
//计算树的高度
//更新树的高度
 
//左旋，右旋 

//插入节点 (以及判断树型是RR还是LL还是RL还是LR) 
 

// height 表示以这个节点为根节点的树的高度 
struct node{
	int v,height;
	node* lchild,
	node* rchild;
};

node* newNode(int v){
	node* Node = new node;
	Node->v = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node; //返回新建节点的地址 
}

int getHeight(node* root){
	if(root == NULL) return 0;
	return root->height;
} 

int getBalancedFactor(node* root) {
	return getHeight(root->lchild)  - getHeight(root->rchild);
}

void updateHeight(node* root){
	root->height = max(getHeight(root->lchild),getHeight(root->rchild));
}

//主要就是获取子树的高度 getHeight()
//计算节点的平衡因子 getBalancedFactor()
//更新节点的高度 updateHeight()  

//search就是一个遍历的过程，相当于是logn的高度的树进行查询 
void Search(node* root,int x){
	if(root ==NULL) {
		printf("search failed\n");
		return;
	}
	if(x==root->data){
		printf("%d\n",root->data);
	}
	else if(x < root->data){
		search(root->lchild,data);
	}
	else if(x > root->data){
		search(root->right,data);
	}
}

//左旋的操作，原来根节点的右子树成为根节点 
//其实就是根节点和右子节点以及右子节点的左子节点的事情 
void L(node* root) {
	//temp就是新的根节点 
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void R(node* root) {
	node* temp = root->lchild;
	//
	root->lchild = temp->rchild;
	//
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
// 左旋右旋是操作
// LL RR LR RL都是树型，具体的判断方式是左右节点和根节点的平衡因子的情况 
// LL 一次右旋  根2 左1 
// LR 先左旋 后右旋，先旋转子树-后旋转根节点  根2 左-1 
// RL 先右旋 后左旋，先旋转子树-后旋转根节点  根-2 右-1  
// RR 一次右旋 根-2 右1 

//AVL的insert就是BST的插入，只不过是在插入之后，衡量关键因子的变化，然后进行左旋和右旋 
void insert(node* &root,int v){
	if(root == NULL) {   //到达空节点 
		root = newNode(v);
		return;
	}
	//进行左旋和右旋 
	if( v < root->v ) {
		insert(root->lchild , v);
		//更新子树的树高 
		updateHeight(root);
		//旋转 
		if(getBalanceFactor(root) == 2) {	
			if(getBalanceFactor(root->lchild) == 1){
				R(root);
			}
			else if(getBalanceFactor(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	}
	else{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1){
				L(root);
			}
			else if(getBalanceFactor(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}
	} 
} 

//根据n个节点建立二叉树 
node* Create(int data[], int n) {
	// 新建空根节点root 
	node* root = NULL;
	for(int i =0;i<n;i++){ 
		insert(root,data[i]);
	}
	return root;
}

