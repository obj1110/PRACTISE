//�����ⲻҪ������ɣ���Ϊ�����������ֱ�ӽ����жϿ϶��ǿ���������������
//�����ľ��ǽ��б������ƽ� 
#include<iostream> 
#include<vector> 
using namespace std;

struct node{
	int data;
	node* left,*right;
};

//����һ�����н�����������������б��� 
//���insert������������BST�����������ڶ�����
//��Ϊ���������Ĺ���ģ�����һ�ֽڵ��������Ĺ��� 
void insert(node *&root, int data){
	if(root == NULL){
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	//���������Ĺ���  
	if(data < root->data ) insert(root->left,data);
	else if(data >= root->data ) insert(root->right,data);
	//����ע�⣬���ڵ���������������� 
}

//�Զ���������ǰ�����,������洢��һ��������
//֮����ʹ��vector����Ϊ�˷�����бȽ� 
void preOrder(node* root,vector<int> &v) {
	if(root == NULL) return;
	v.push_back(root->data);
	preOrder(root->left,vi);
	preOrder(root-data>right,vi);
}
int main(){
	
}
