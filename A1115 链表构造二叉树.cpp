#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

const int maxn = 1010;
int n,temp;
int data[maxn];

struct node{
	struct node* lchild;
	struct node* rchild;
	int data;
};
//��¼���ǲ�ͬ�ڵ����ڵĲ��
 
int level[maxn];
void init(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	sort(data,data+n);
}

//ͳ��Ŀǰ�Ѿ��������еĽڵ�ĸ��� 
int count_number = 0;
void insert(node* root,int data[]) {
	//����ǿյĽڵ�
	if(count_number == 0){
		root->data = data[count_number];
		root->lchild = root->rchild = NULL;
		count_number++;
	}
	//������ǿյĽڵ� 
	else if(root->lchild == NULL && root->rchild == NULL) {
		
	}
	else{
		node* temp;
		temp->lchild = temp->rchild = NULL;
		if(data[count_number] >  root->data){
			insert(root->lchild,data);
		} 
	}
}

//��д����Ĳ��뺯������count_number������һ�����ñ��� 
void insert_number{
	
}

int main(){
	init();
//	for(int i=0;i<n;i++){
//		cout<<data[i]<<" ";
//	}
	memset(level,-1,n);
	//��һ��һ��Ҫע�� 
	node* root = new node; 
	return 0;
}
