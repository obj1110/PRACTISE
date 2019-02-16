//将给定的序列插入一个 
//结果就是计算最底下两层的一个节点的个数 

// 将节点插入一个空白的二叉搜索树，
// 然后遍历计算每一个层次的，主要的目的是计算每一个节点的层次 
//  
#include<iostream> 
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

const int maxn = 1010;
const int max_inf = 1010;
const int min_inf = -1010;
vector<int> data;

struct Node{
	int data;
	struct Node* lchild;
	struct Node* rchild;
	int level; 
}node[maxn];

int n1,n2,n,temp;
int index = 0 ;
Node insert(Node root,vector<int> temp){
	while(!temp.empty()){
		int x = temp[index];
		index++;
		
		if(root.data > x ) {
			if(root.lchild == NULL) {
				Node new_node = new Node;
				new_node.data = x;
				new_node.lchild = new_node.rchild = NULL;
				root.lchild = new_node; 
			}
			else if(root.lchild != NULL) insert(root.lchild);
		}
		else if(root.data <= x){
			if(root.rchild == NULL) {
				Node new_node = new Node;
				new_node.data = x;
				new_node.lchild = new_node.rchild = NULL;
				root.rchild = new_node; 
			}
			else if(root.rchild != NULL) insert(root.rchild);
		}
	return root;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		data.push_back(temp);
	}
	sort(temp,temp+n);
	for(int i=0;i<n;i++){
		insert(temp[i]);
	}
	

	cout<<".....";
	printf("%d + %d = %d",n1,n2,n1+n2);
	return 0; 
}

