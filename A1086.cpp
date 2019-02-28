//��������Ľ���ǿ�����stack���з��Ƶ�
//��һ����6���ڵ������������ʱ��
//��������Ķ�ջ��push��pop����Ѿ���������
//����Ļ���ֻҪpop��һ�����ӡ�ģ�����Ҳ�����
//����Ļ�����Ҫ����ӡ�������뵽����������ջ�У�Ȼ��pop����ӡ

//������������������н�� 

//���������ʵ����һ��DFS������Ҫ�õ���ջ
//���� ���� �ͺ���֮��Ĵ�����Ҫ��printf��ʱ�䲻ͬ



//����ı����ǣ������������к����������Ƶ��������� 
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

const int maxn = 35; 
int n;
//ע��ڵ��1��ʼ��n 

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
		//��pop 
		if(str.length() <= 4){
			mid[wpt_mid++] = st.top();
			st.pop();
		}
		//��push 
		else{
			//���ֲ�ֹ1λ 
			int number = stoi(str.substr(5,str.length()-5));
			pre[wpt_pre++]  = number;
			st.push(number);
		}
	}
}

//�����������кͺ������н������Ľ��� 
node* create(int prel,int prer,int midl,int midr){
	if(prel > prer ) return NULL;
	//Ѱ��k��λ�� 
	int k =0 ;
	for(k=prel; k <= prer; k++){
		if(mid[k] == pre[prel]) break;
	}
	//�������Ĵ�С 
	int left = k - midl;
	// 
	node* root = new node;
	root->data = pre[prel];
	root->lchild = create(prel+1,prel + left ,midl,k-1);
	root->rchild = create(prer - left,prer,k+1,midr);
	return root;
}

//���к������ 
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
