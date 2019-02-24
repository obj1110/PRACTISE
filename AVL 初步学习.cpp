//AVL�е�ƽ�����ӱ�ʾ������������֮��Ĳ�� ���������� 
#include<iostream> 
#include<vector> 
#include<algorithm>
using namespace std;

//����ƽ������
//�������ĸ߶�
//�������ĸ߶�
 
//���������� 

//����ڵ� (�Լ��ж�������RR����LL����RL����LR) 
 

// height ��ʾ������ڵ�Ϊ���ڵ�����ĸ߶� 
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
	return Node; //�����½��ڵ�ĵ�ַ 
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

//��Ҫ���ǻ�ȡ�����ĸ߶� getHeight()
//����ڵ��ƽ������ getBalancedFactor()
//���½ڵ�ĸ߶� updateHeight()  

//search����һ�������Ĺ��̣��൱����logn�ĸ߶ȵ������в�ѯ 
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

//�����Ĳ�����ԭ�����ڵ����������Ϊ���ڵ� 
//��ʵ���Ǹ��ڵ�����ӽڵ��Լ����ӽڵ�����ӽڵ������ 
void L(node* root) {
	//temp�����µĸ��ڵ� 
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
// ���������ǲ���
// LL RR LR RL�������ͣ�������жϷ�ʽ�����ҽڵ�͸��ڵ��ƽ�����ӵ���� 
// LL һ������  ��2 ��1 
// LR ������ ������������ת����-����ת���ڵ�  ��2 ��-1 
// RL ������ ������������ת����-����ת���ڵ�  ��-2 ��-1  
// RR һ������ ��-2 ��1 

//AVL��insert����BST�Ĳ��룬ֻ�������ڲ���֮�󣬺����ؼ����ӵı仯��Ȼ��������������� 
void insert(node* &root,int v){
	if(root == NULL) {   //����սڵ� 
		root = newNode(v);
		return;
	}
	//�������������� 
	if( v < root->v ) {
		insert(root->lchild , v);
		//�������������� 
		updateHeight(root);
		//��ת 
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

//����n���ڵ㽨�������� 
node* Create(int data[], int n) {
	// �½��ո��ڵ�root 
	node* root = NULL;
	for(int i =0;i<n;i++){ 
		insert(root,data[i]);
	}
	return root;
}

