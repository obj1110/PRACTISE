///相对于86来说，问题在于本题的节点数太多了，30个对5万个 
//而最后也不要求你输出后续遍历的序列，只需要输出第一个
//肯定有巧妙的方法 

//emmmm似乎PAT的例子有待改进 
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

const int maxn = 50100; 
int n;

struct node{
  node* lchild;
  node* rchild;
  int data;
};

int pre[maxn],mid[maxn],post[maxn];

void init() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&mid[i]);
	}
}

node* create(int prel,int prer,int midl,int midr){
	if(prel > prer) return NULL;
	//寻找k的位置 
	int k =0 ;
	//这里严重失误==== 
	//左边的第一个元素作为头节点，最后应该是放在右边的位置 
	for(k=midl; k <= midr; k++){
		if(mid[k] == pre[prel]) break;
	}
	//左子树的大小 
	int left = k - midl;
	// 
	node* root = new node;
	root->data = pre[prel];
	root->lchild = create(prel+1,      prel + left , midl,   k-1);
	root->rchild = create(prel + left +1,   prer,    k+1,    midr);
	return root;
}

//进行后序遍历 
int count_post = 0;
void PostTraverse(node* root){
	if(root!=NULL){
		if(root->lchild) PostTraverse(root->lchild);
		if(root->rchild) PostTraverse(root->rchild);
		post[count_post++] = root->data;
	}
}

int main(){
  init();
  PostTraverse(create(0,n-1,0,n-1));
  cout<<post[0];
  return 0;
}
