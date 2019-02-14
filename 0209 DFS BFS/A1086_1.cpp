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
		//��pop 
		if(str.length() <= 4){
			mid[wpt_mid++] = st.top();
			st.pop();
		}
//		//��push 
		else{
//			//���ֲ�ֹ1λ 
			int number = stoi(str.substr(5,str.length()-5));
			pre[wpt_pre++]  = number;
			st.push(number);
		}
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
