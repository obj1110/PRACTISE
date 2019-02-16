//判断是不是二叉排序树，主要的方式进行一个前序中序或者是后序的遍历操作 
//本题的问题就是判断一个二叉树是不是一个BST，或者说 mmmmmmmm65we88fc  
#include<iostream> 
#include<cstring>
#include<vector>
//交换二叉排序树的左右子树得到的是二叉排序树的镜像
//给出一个整数序列，然后判断这个序列是不是一个二叉排序树的前序或者是后续的序列
//或者判断这个序列是不是一个二叉排序树的镜像树的前序或者是后续的遍历结果 

using namespace std;

//假设它是二叉搜索树，一开始isMirror为FALSE，
//根据二叉搜索树的性质将已知的前序转换为后序，
//转换过程中，如果发现最后输出的后序数组长度不为n，
//那就设isMirror为true，然后清空后序数组，
//重新再转换一次（根据镜面二叉搜索树的性质），
//如果依旧转换后数组大小不等于n，就输出no否则输出yes

const int maxn = 1000100;

bool isMirror;
vector<int> pre,post; 

//给出一个数组的前后界限 
void getpost(int root,int tail){
	if(root > tail ) return;
	int i = root +1, j = tail;
	//如果不是镜像树 
	if(!isMirror) {
		
	} 
	//如果是镜像树
	else if(isMirror){
		while( i<= tail  && pre[root] )
	} 
}

int main(){
	
}
