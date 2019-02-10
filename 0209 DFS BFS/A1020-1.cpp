#include<iostream> 
using namespace std;

const int maxn = 35;

int n;		
struct node{
	int data;
	node* l;
	node* r;
	//是不是曾经便利过 
	int vis;
};
//Node相当于是struct node		

int pre[maxn],mid[maxn],post[maxn];

void init(){
	scanf("%d",&n);
	for(int i =0;i<n;i++) {
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&mid[i]); 
	}
}

//用递归的方式建立二叉树 
node* Create(int postl,int postr,int midl,int midr){
	if(postl > postr || midl > midr) return NULL;
	
	node* root = new node ;
	root->data = post[postr];
	root->l = root->r =NULL;
	int k = midl;
	while(mid[k] != post[postr]);{
		k++;
	}
	// midl,,,,,,k-1, k,k+1,,,,,,,midr;
	//postl,,,,postr-1,postr;
	root->l = Create( midl, k-1, midl,k-1);
	root->r = Create( k,  midr-1,k+1  ,midr );
	return root;
} 

void PreTraverse(node* root){
	if(root != NULL){
		printf("%d\n",root->data);
		PreTraverse(root->l);
		PreTraverse(root->r);
	}
}

void Layer(node* root){
	
}

int main(){
	init();
	node* root = Create(0,n-1,0,n-1);
	PreTraverse(root);
//	Layer(root);
	return 0;
}
