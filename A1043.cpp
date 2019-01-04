#include<iostream>
#include<vector>

using namespace std;
struct node{
	int data;
	node*left,*right;
};

void insert(node* &root,int data){
	if(root == NULL){
		root = new node;
		root->data = data;
		root->left = root->right =NULL;
		return ;
	}
	else{
		if(data < (root->data)) insert(root->left,data);
		else if(data >= (root->data)) insert(root->right,data);
		//注意，千万不要忽视等于的情况 
	}
}

void preorder(node *root,vector<int>& a){
	if(root == NULL) return ;
	a.push_back(root->data);
	preorder(root->left,a); 
	preorder(root->right,a);
}

void postorder(node* root,vector<int>& a){
	if(root ==NULL) return ;
	postorder(root->left,a);
	postorder(root->right,a); 
	a.push_back(root->data); 
}	

void preorderm(node *root,vector<int>& a){
	if(root == NULL) return ;
	a.push_back(root->data);
	preorderm(root->right,a);
	preorderm(root->left,a);
}
void postorderm(node *root,vector<int>& a){
	if(root ==NULL) return ;
	postorderm(root->right,a);
	postorderm(root->left,a);
	a.push_back(root->data);
}
vector<int> origin,pre,prem,post,postm;

int main(){
	int n,data;
	node *root = NULL;
	scanf("%d",&n);
	
	for(int i =0;i<n;i++){
		scanf("%d",&data);
		//把数据存储在数组中 
		origin.push_back(data);
		//给根节点插入元素 
		insert(root,data);
	}
	
	preorder(root,pre);
	preorderm(root,prem);
	postorder(root,post);
	postorderm(root,postm);
	
//	for(int i=0;i<origin.size();i++){
//		printf("%d",origin[i]);
//		if(i!=-1) printf(" ");
//	}
//	cout<<endl<<"-------"<<endl;
//	for(int i=0;i<pre.size();i++){
//		printf("%d",pre[i]);
//		if(i!=-1) printf(" ");
//	}
//	cout<<endl<<"-------"<<endl;
//	for(int i=0;i<prem.size();i++){
//		printf("%d",prem[i]);
//		if(i!=-1) printf(" ");
//	}
//	cout<<endl<<"-------"<<endl;
//	for(int i=0;i<post.size();i++){
//		printf("%d",post[i]);
//		if(i!=-1) printf(" ");
//	}
//	cout<<endl<<"-------"<<endl;
//	for(int i=0;i<postm.size();i++){
//		printf("%d",postm[i]);
//		if(i!=-1) printf(" ");
//	}
	
	
	if(origin == pre){
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf("%d",post[i]);
			if(i<post.size()-1) printf(" ");
		}
		return 0;
	}
	else if(origin == prem){
		printf("YES\n");
		for(int i=0;i<postm.size();i++){
			printf("%d",postm[i]);
			if(i<postm.size()-1) printf(" ");
		}
		return 0;
	}
	else printf("NO\n");
	return 0;
}
