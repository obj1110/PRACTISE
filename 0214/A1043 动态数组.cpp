//这种题不要急于求成，因为根据这个序列直接进行判断肯定是考场上做不出来的
//能做的就是进行暴力的破解 
#include<iostream> 
#include<vector> 
using namespace std;

struct node{
	int data;
	node* left,*right;
};

//根据一个序列建树——对这个树进行遍历 
//这个insert不仅仅适用于BST，甚至适用于多种树
//因为它将建树的过程模拟成了一种节点迭代插入的过程 
void insert(node *&root, int data){
	if(root == NULL){
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	//两个迭代的过程  
	if(data < root->data ) insert(root->left,data);
	else if(data >= root->data ) insert(root->right,data);
	//尤其注意，等于的情况归属于右子树 
}

//对二叉树进行前序遍历,将结果存储在一个序列中
//之所以使用vector，是为了方便进行比较 
void preOrder(node* root,vector<int> &v) {
	if(root == NULL) return;
	v.push_back(root->data);
	preOrder(root->left,vi);
	preOrder(root-data>right,vi);
}
int main(){
	
}
