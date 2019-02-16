//本题的这种给发一看就是让你使用静态方式构建一个二叉树 
//本题跟1064的区别就是对于完全二叉树你可以用数组来偷懒，但是本题还是推荐建树 
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn  = 105;
int n,int data[maxn];
vector<int> tree[maxn];
bool isLeaf[maxn] = {false};
int level[maxn];

void init() {
	scanf("%d",&n);
	int a,b;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(a == -1 && b==-1){
			isLeaf[i] = true;
		}
		vector[i].push_back(a);
		vector[i].push_back(b);
	}
	for(int i=0;i<n;i++) {
		scanf("%d",data[i]);
	}
}

int root =0 ; 
int index = 0; 
// root是当前子树的根节点
//index是顺序序列的当前工作元素 
void InOrder(int root) {
	if(root >= n) return;
	InOrder(root*2+1);
	level[root] =  data[index++];
	InOrder(root*2+2);
}

int main(){
	init();
	//将数据数组存储为-1 
	memset(data,-1,maxn);
	// 
	return 0;
}
