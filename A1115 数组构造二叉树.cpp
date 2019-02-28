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
	int lchild;
	int rchild;
	int data;
	//可用性，true表示可用，false表示已经被占用了 
	bool vis;
}Node[maxn];
//记录的是不同节点所在的层次
 
int level[maxn];
void init(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
		//数组中都说是一个一个的空节点 
		Node[i].vis = true;
		Node[i].lchild = -1;
		Node[i].rchild = -1;
	}
	sort(data,data+n);
}

//下面的插入函数包括了5种情况 

//统计目前已经插入树中的节点的个数 
int count_number = 0;
void insert(int root) {
	if(count_number == n) return;
	//死胡同 ，对根节点进行插入 
	if(count_number == 0 ){
		Node[root].data = data[count_number++];
		Node[root].vis = false;
	}
	//带插入的节点的值  
	else if(count_number > 0 && Node[root].vis == true ) {
		//上面的判断条件表示一个空的节点 
		Node[root].data = data[count_number++];
		Node[root].vis = false;
	}
	else if(count_number > 0 && Node[root].data < data[count_number]){
		insert(Node[root].lchild);
	}
	else if(count_number > 0 && Node[root].data > data[count_number]){
		insert(Node[root].rchild);
	}
	//对一般节点进行插入
}

//改写上面的插入函数，将count_number当做是一个引用变量 


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
