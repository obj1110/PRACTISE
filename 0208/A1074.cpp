//初始化并读入链表；
//从头节点开始遍历链表，找出其中有效节点并标记；
//有效节点按照翻转规则对其重新编号；
//重新排序；
//按照题目格式要求输出返回零值。

#include<iostream>
#include<algorithm>

using namespace std;

const int maxn =  1000100;

struct Node{
	int add;
	int data;
	int next;
	int flag;
}node[maxn]; 

bool cmp(Node a,Node b){
	if(a.flag != b.flag) return a.flag > b.flag;
	else return a.data < b.data;
}

int main(){
	//k是sublist的长度,很重要的变量 
	int h1,n,k,cts=0;
	int a,b,c;
	scanf("%d %d %d",&h1,&n,&k);
	while(n--) {
		scanf("%d %d %d",&a,&b,&c);
		node[a].add = a;
		node[a].data = b;
		node[a].next = c;
	}

	//计算有效节点的个数 
	while(h1 != -1){
		cts++;
		node[h1].flag = 1;
		h1 = node[h1].next;
	}
	
	//special
	if(cts==0){
		printf("00000 0 -1\n");
		return 0;
	}
	//将有效节点和无效节点分开，并且对有效节点进行排序 
	sort(node,node+maxn,cmp);
	//

	//交换位置 
	if(k > cts){
		//continue; 
	}
	//k <= cts ，需要进行顺序的变化 
	else{
		int init =0;
		while(init + k <cts) {
			int i = 0;
			int j = k-1;
			while(i <= j){
				swap(node[i],node[j]) ;
//				swap( node[i].add , node[j].add  );
//				swap( node[i].data, node[j].data );
//				swap( node[i].next, node[j].next );
				i++;
				j--; 
			} 
			init += k;
		}
	}
	// 重新建立关系 
	h1 = node[0].add;
	for(int i=0;i<cts-1;i++) {
		node[i].next = node[i+1].add;
	}
	node[cts-1].next = -1;
	// 打印 
	for(int i=0;i<cts-1;i++){
		printf("%05d %d %05d\n",  node[i].add,   node[i].data,  node[i].next);
	}
	printf("%05d %d -1\n",node[cts-1].add,node[cts-1].data);
	return 0;
}
