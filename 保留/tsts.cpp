#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<queue> 

using namespace std;

const int maxn = 35;

struct node{
	int data;
	node* l;
	node* r;
};

int n;
int pre[maxn],mid[maxn],post[maxn];

void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&mid[i]);
	}
}

node* create(int midl,int midr,int postl,int postr){
	if(postl > postr) return NULL;
	int k;
	for(k=midl;k<=midr;k++){
		if(mid[k] == post[postr]) break;
	}
	//指针变量一定要提前分配好空间 
	node* root = new node;
	root->data = post[postr];
	int numleft = k - midl;
	root->l = create(midl,k-1,postl,postl+numleft-1);
	root->r = create(k+1,midr,postl+numleft,postr-1);
	
//	root->l = create(midl,k-1,postl,k-1);
//	root->r = create(k+1,midr,k,postr-1);

	return root;
}

int cts =0;
void layerTraverse(node* root){																					queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		cts++;
		printf("%d",temp->data);
		if(cts != n){
			printf(" ") ; 
		}
		if(temp->l) q.push(temp->l);
		if(temp->r) q.push(temp->r);
	}
}

void PreTraverse(node* root){
	if(root != NULL){
		printf("%d ",root->data);
		PreTraverse(root->l);
		PreTraverse(root->r);
	}
}

int main(){
	init();
	node* root = create(0,n-1,0,n-1);
//	cout<<"!";
//	PreTraverse(root);
	layerTraverse(root);
	return 0;
}
