#include<iostream> 
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

//Ϊ�ν�����ԣ�ԭ�������insert�������棬�������BST�Ĳ��뷽����������ǲ���
//��Ϊ����Ҫ��Ĳ��뷽ʽ��AVL��Ҳ����BST�������棬ƽ������� 
const int maxn = 1010;

struct node{
	node* lchild;
	node* rchild;
	int data;	
};
//��˵������һ������һ�� 
int layer[maxn];

int n;
//insert�Ĺ��̱������һ��һ���ڵ�Ľ��в���,���Բ�����int��������int���� 
void insert(node* &root,int data){
	//��Ҫ�Ǹ��ڵ� 
	if(root == NULL) {
		root = new node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return;
	}
	//������ڵ㣬�����ҽڵ�  
	if(data < root->data )  insert(root->lchild,data);
	else if(data >= root->data) insert(root->rchild,data);
}

void PreOrder(node* &root,int level){
	if(root==NULL) return;
	layer[level]++;
	PreOrder(root->lchild,level+1);
	PreOrder(root->rchild,level+1);
	return;
}

int main(){
	// ������ȡ���ݺͲ���ڵ� 
	memset(layer,0,maxn);
	scanf("%d",&n);
	//����cin������տո�;
	node* root = NULL;
	// һ����root���в�����
	// ���� root->lchild �� root->rchild ���ֶ��������root�ڵ�ʧȥ�Լ��ǿսڵ������
	// ��������͵����Ľ��������Ϳ����� 
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		insert(root , temp);
	}
	PreOrder(root,0);
	// �������ͨ�����ⷽʽ���и�ֵ��������ר�����ĳһ�������� 
	int i;
	for(i=0;i<n;i++){
		cout<<layer[i]<<endl;
		if(layer[i] == 0) 
		break;
	}
	printf("%d + %d = %d",layer[i-1],layer[i-2],layer[i-2] + layer[i-1]);
	
	
	return 0;
}
