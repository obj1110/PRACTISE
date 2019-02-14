//中序遍历的结果是可以用stack进行反推的
//当一个有6个节点的树被遍历的时候
//这个辅助的堆栈的push和pop情况已经给出来了
//先序的话，只要pop就一定会打印的，中序也是如此
//后序的话，需要将打印队列输入到第三方辅助栈中，然后pop并打印

//输出这个后序遍历的序列结果 

//中序遍历其实就是一种DFS，所以要用到堆栈
//先序 中序 和后序之间的大差别主要是printf的时间不同



//本题的本质是：根据先序序列和中序序列推导后序序列 
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

const int maxn = 35; 
int n;
//注意节点从1开始到n 

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
	for(int i=0;i<total;i++){
		std::getline(cin,str);
		//是pop 
		if(str.length() <= 4){
			mid[wpt_mid++] = st.top();
			st.pop();
		}
		//是push 
		else{
			//数字不止1位 
			int number = stoi(str.substr(5,str.length()-5));
			pre[wpt_pre++]  = number;
			st.push(number);
		}
	}
}

//根据中序序列和后序序列进行树的建立 
node* create(int prel,int prer,int midl,int midr){
	if(prel > prer ) return NULL;
	//寻找k的位置 
	int k =0 ;
	for(k=prel; k <= prer; k++){
		if(mid[k] == pre[prel]) break;
	}
	//左子树的大小 
	int left = k - midl;
	// 
	node* root = new node;
	root->data = pre[prel];
	root->lchild = create(prel+1,prel + left ,midl,k-1);
	root->rchild = create(prer - left,prer,k+1,midr);
	return root;
}

//进行后序遍历 
int count_post = 0;
void PostTraverse(node* root){
	if(root!=NULL){
		printf("%d",root->data);
		count_post++;
		if(count_post != n) printf(" ");
		if(root->lchild) PostTraverse(root->lchild);
		if(root->rchild) PostTraverse(root->rchild);
	}
}

int main(){
  init();
  PostTraverse(create(0,n-1,0,n-1));
  return 0;
}
