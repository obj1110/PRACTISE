#include<iostream>
#include<vector>
#include<stack>

using namespace std;

const int maxn = 35; 
int n;

struct node{
  node* lchild;
  node* rchild;
  int data;
};

int pre[maxn],mid[maxn],post[maxn];
stack<int> st; 

int wpt_pre = 0;
int wpt_mid = 0;

void init() {
	scanf("%d",&n);
	int total = 2*n;
	string str;
	getchar();
	for(int i=0;i<total;i++){
		std::getline(cin,str);
		//是pop 
		if(str.length() <= 4){
			mid[wpt_mid++] = st.top();
			st.pop();
		}
//		//是push 
		else{
//			//数字不止1位 
			int number = stoi(str.substr(5,str.length()-5));
			pre[wpt_pre++]  = number;
			st.push(number);
		}
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
		printf("%d",root->data);
		count_post++;
		if(count_post != n) printf(" ");
	}
}

int main(){
  init();
  PostTraverse(create(0,n-1,0,n-1));
  return 0;
}
