#include<iostream>
#include<queue> 

using namespace std;

struct node{
	node* lchild ;
	node* rchild;
	int data; 
}; 

const int maxn = 35;
int pre[maxn] ,mid[maxn],post[maxn];

node* create(int midl,int midr,int postl,int postr){
	if(postl > postr) return NULL;
	int k;
	for( k = midl ; k!=midr ; k++ ){
		if(post[postr] == mid[k]) break;
	}
	int numLeft = k - midl;
	node* root = new node;
	root->data = post[k];
	root->lchild = create(midl,k-1,postl,postl+numLeft-1);
	root->rchild = create(k+1,midr,postl+numLeft,postr-1);
	return root;
}


void layerTraverse(node* root){
	int count =0;
	queue<node> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.top();
		q.pop();
		printf("%d",&temp->data);
		count++;
		if(count != n) {
			printf(" ");
		}
		if(temp->lchild) q.push(temp->lchild);
		if(temp->rchild) q.push(temp->rchild);
	}
}

void preTraverse(node* root){
	
}

