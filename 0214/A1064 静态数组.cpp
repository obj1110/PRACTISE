#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int n,number[maxn],CBT[maxn],index = 0 ;
void MidOrder(int root){
	//空节点直接返回 
	if(root  > n ) return;
	//左子树递归 
	MidOrder(root*2);
	//这种赋值操作其实就是一种打印的操作 
	CBT[root] = number[index++];
	//右子树进行递归 
	MidOrder(root*2+1);
}

int main() {
	scanf("%d",&n);
	//number用于暂存数据，将元素暂存在number中 
	for(int i=0;i<n;i++){
		scanf("%d",&number[i]);
	}
	sort(number.number+n);
	//从1号节点开始进行遍历 
	MidOrder(1);
	for(int i=1;i<=n;i++) {
		printf("%d",CBT[i]);
		if(i<n) printf(" ");
	}
	return 0;
}

//思路一;读取数据，建树，对树进行遍历（链表
//思路二：读取数据，直接遍历，对于二叉树而言啊，这个顺序是确定的啊 
