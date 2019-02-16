//对于1064的理解
//对BST进行中序遍历得到的是有序的序列
//存放进入数组中的BST的顺序输出，就是BST的层序遍历模式

//也就是说，对BST进行层序遍历的元素就是中序遍历的中间节点

//中序遍历的结果就是一个有序序列，所以中序遍历的中间过程就是一个序列中的元素，
//层序遍历的节点就是中序遍历的结果

//数组的第一个元素 是层序遍历的第一个元素 但并不是中序遍历的第一个元素

//通过中序遍历可以获知每一个数组单元对应的节点的序号
//比如根节点是1号节点，子树是2号和3号节点，他们存储的元素值呢？可以在中序遍历中进行赋值 

//中序遍历的输出序列就是一个顺序序列，所以对应的元素值可以在中序序列输出的时候进行赋值操作 
#include<iostream> 
#include<algorithm>
using namespace std;
const int maxn = 1010;
int data[maxn] ,tree[maxn];

//index从1开始处理的是二叉树静态存储数组的 
//cts是从0开始的处理顺序序列用的 
int index;
int cts = 0;
int n;
//index指的是节点的编号 
void InOrder(int index){
	if(index>n) return;
	InOrder(index*2) ;
	tree[index] = data[cts++];
	InOrder(index*2+1) ;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	sort(data,data+n);
	InOrder(1);
	for(int i=1;i<=n;i++){
		printf("%d",tree[i]);
		if(i != n ) cout<<" ";
	}
	return 0;
}
 
