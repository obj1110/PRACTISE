#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

//并查集：初始化，对所有的元素建立自己的一个集合。
struct Node{
	int data;
	int rank;
	int father;//作用是一个指针，指向大类 
}node[maxn]; 
//注：这种node 
//并查集也可以使用数组的形式进行研究
int set[maxn];
int rank[maxn];
int data[maxn];
void make_set(int i){
	
}


//判断两个节点是不是属于同一个集合 用father数组进行判断 
//将两个节点进行合并 用union函数 
int father[maxn];


//注意根节点的父亲节点是它自己 
int findF(int x){
	while(x != father[x]){
		x = father[x];
	}
	//退出循环的时候肯定是	 
	return x;
}

//路径压缩,缩短路径，让路径上的每一个点都进行修改 
int findFather(int v){
	if(v == father[v]) return v;
	else{
		int F =findFather(father[v]);
		//这句话让整个路径上的所有点直接跳到了最终的根节点位置 
		father[v] = F;
		return F;
	}
}

//并查集的合并操作是——首先查找一个根节点 
//将两个根节点的关系指定为father的关系 
void union(int a,int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	//如果a和b不是一个集合 
	if(faA != faB)  {
		father[faA] = faB;
		father[faB]	= faA;
	}
}

int main(){
	
}
