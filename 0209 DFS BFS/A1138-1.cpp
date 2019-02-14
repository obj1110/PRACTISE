///�����86��˵���������ڱ���Ľڵ���̫���ˣ�30����5��� 
//�����Ҳ��Ҫ��������������������У�ֻ��Ҫ�����һ��
//�϶�������ķ��� 

//emmmm�ƺ�PAT�������д��Ľ� 
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
	//Ѱ��k��λ�� 
	int k =0 ;
	//��������ʧ��==== 
	//��ߵĵ�һ��Ԫ����Ϊͷ�ڵ㣬���Ӧ���Ƿ����ұߵ�λ�� 
	for(k=midl; k <= midr; k++){
		if(mid[k] == pre[prel]) break;
	}
	//�������Ĵ�С 
	int left = k - midl;
	// 
	node* root = new node;
	root->data = pre[prel];
	root->lchild = create(prel+1,      prel + left , midl,   k-1);
	root->rchild = create(prel + left +1,   prer,    k+1,    midr);
	return root;
}

//���к������ 
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
