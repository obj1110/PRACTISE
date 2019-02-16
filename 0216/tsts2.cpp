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
//记录的是不同节点所在的层次
 
int level[maxn];
void init(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	sort(data,data+n);
}

//统计目前已经插入树中的节点的个数 
int count_number = 0;
void insert(node* root,int data[]) {
	//如果是空的节点
	if(count_number == 0){
		root->data = data[count_number];
		root->lchild = root->rchild = NULL;
		count_number++;
	}
	//如果不是空的节点 
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

//改写上面的插入函数，将count_number当做是一个引用变量 
void insert_number{
	
}

int main(){
	init();
//	for(int i=0;i<n;i++){
//		cout<<data[i]<<" ";
//	}
	memset(level,-1,n);
	//这一点一定要注意 
	node* root = new node; 
	return 0;
}
