//堆自己就是一个完全二叉树，然后分为大顶堆和小顶堆。 
#include<iostream> 
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 1010; 

//名义上的堆中的数据，其实是数组中的数据，
//一个叫做heap的一维数组中存储的数据 


//其实是对某一个节点进行调整 
void downAdjust(int low,int high) {
	//j是左孩子， 
	int i = low,j = low*2;
	//如果j没有超过上界 
	while(j <= high) {
		//对于右孩子如果也是不超上界的 
		//首先寻找一个右孩子，一个更高的右孩子 
		if(j +1 <= high && heap[j+1] > heap[j]) {
			j = j + 1;
		}
		//子节点和父母节点进行交换 
		if( heap[j] > heap[i] ){
			swap(heap[i],heap[j]);
			i = j;
			j = i*2;
		}
		else{
			break;
		}
	}
}
//其实就是按照一定的原则对heap进行排序，heap其实就是一个数组 
void createHeap(){
	//也就是倒着进行枚举操作 
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	} 
}
//删除heap top元素其实就是把heap top元素进行提取，其实就是堆排序嘛 
void deleteTop() {
	//首先进行替换 
	heap[1] = heap[n--];
	//然后进行堆调整 
	downAdjust(1,n); 
}

// 在堆中，插入节点的操作 
void upAdjust(int low,int high){
	int i = high;
	int j =i/2; 
	if(heap[j] < heap[i]){
		swap(heap[j],heap[i]);
		i = j;
		j = i/2;
	}
	else{
		//代表到达了最终的合适的位置 
		break;
	}
}
void insert(int x){
	heap[++n] = x;
	upAdjust(1,n);
}

void heapSort(){
	createHeap();
	for(int i = n ; i > 1 ; i++){
		//首先将第一个元素和最后一个元素进行交换 
		swap(heap[i],heap[1]);
		//主要是为了节省空间，前面是建好的heap 
		//后面是剩下的有序序列 
		downAdjust(1,i-1);
	}
}

int main(){
	
	return 0;
}
