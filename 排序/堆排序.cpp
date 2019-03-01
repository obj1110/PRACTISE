#include<algorithm> 
#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;

void heap_build(int a[],int root,int length){
	int lchild = root*2+1;
	if(lchild < length){
		//首先选择二者中比较大的那个元素 
		int flag = root*2 + 1;
		int rchild = lchild + 1;
		if(rchild < length){
			//然后就是筛选二者中比较大的那个元素 
			if(a[rchild] > a[flag]){
				flag = rchild;
			}
		}
		// 如果根节点比这个节点要小，就交换二者的位置 
		if(a[root] < a[flag]){
			swap(a[root],a[flag]);
			Heap_build(a,flag,length);
			//然后递归的一条路径上去，逐渐的将这条路径上的所有点都调整好 
		}
	}
}

void heap_sort(int a[],int len) {
	//最后一个非叶子节点开始研究 
	for(int i= len/2; i>=0;i--){
		heap_build(a,i,len); 
	}
	//建堆完毕，开始排序 
	for(int j=len -1;j>0;j--){
		swap(a[0],a[j]); 
		//调整新上去的，0号元素的位置 
		heap_build(a,0,j);
	}
}

int main(){
	
}
