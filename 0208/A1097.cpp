//初始化并读入链表；
//从头节点开始遍历链表，找出其中有效节点并标记；
//有效节点按照翻转规则对其重新编号；
//重新排序；
//按照题目格式要求输出返回零值。


//要处理的特例包括：
	//不存在无用节点
	//不存在有用节点 ，也就是头结点指向的元素不存在，或者说是头结点指向的元素是错误的不存在的元素，这种情况下，如何输出剩余的元素是一大问题 
	//有用节点只有1，而剩余全部的元素都是无用节点的情况 



#include<iostream>
#include<algorithm>
#include<cmath> 
#include<cstring>

using namespace std;

const int maxn =  1000100;

struct Node{
	int add;
	int data;
	int next;
	int flag;
}node[maxn],node1[maxn]; 
//node是用到过的
//node1是没有用到过的节点 

int hash_map[10010];

//对于node进行排序 
bool cmp(Node a,Node b){
	if(a.flag != b.flag) return a.flag > b.flag;
	else return abs(a.data) > abs(b.data);
}
//对于node1进行排序 
bool cmp1(Node a,Node b){
	if(a.flag != b.flag) return a.flag > b.flag;
}


int main(){
	//初始化 
//	memset(hash_map,0,10010);
	int h1,h2,n,cts=0;
	int cts1 = 0;
	int a,b,c;
	//数据的输入 
	scanf("%d %d",&h1,&n);
	while(n--) {
		scanf("%d %d %d",&a,&b,&c);
		node[a].add = a;
		node[a].data = b;
		node[a].next = c;
		//标记 
		hash_map[abs(b)] = 1;
	}

	//将有效节点和无效节点分开，并且对有效节点进行排序 
	while(h1!= -1){
		cts++;
		node[h1].flag = 1;
		h1 = node[h1].next;
	}
	sort(node,node+maxn,cmp);
	//

	//special 两个都是0 
//	if(cts==0){
//		printf("00000 0 -1\n");
//		return 0;
//	}
		
	//
	h1 = node[0].add;	
	int temp_cts_1 = cts;
	int temp_cts_2 = 0;
	int index = 0;
	
	for(int i=0 ; i < cts ; i++){
		int data = abs(node[i].data);
		if(hash_map[data] == 1){
			hash_map[data] = 0;
		}
		else{
			node1[index] = node[i];
			index++;
			node[i].flag = -1;
			temp_cts_1--;
			temp_cts_2++;
		}
	}
	cts = temp_cts_1;
	cts1 = temp_cts_2;
	//
//	cout<<"cts: " <<cts<<endl;
//	cout<<"cts1: "<<cts1<<endl;
	//
	sort(node,node+maxn,cmp);
	sort(node1,node1+maxn,cmp1);
	


	// 重新建立关系 
	h1 = node[0].add;
	for(int i=0;i<cts-1;i++) {
		node[i].next = node[i+1].add;
	}
	node[cts-1].next = -1;
	//
	// 重新建立关系 
	h2 = node1[0].add;
	for(int i=0;i<cts1-1;i++) {
		node1[i].next = node1[i+1].add;
	}
	node1[cts1-1].next = -1;
	
	// 打印 
	if(cts != 0) {
		for(int i=0  ;   i<cts-1  ;  i++){
			printf("%05d %d %05d\n",  node[i].add,   node[i].data,  node[i].next);
		}
		printf("%05d %d -1\n",node[cts-1].add,node[cts-1].data);
	}

	// 打印 
	if(cts1 !=0){
		for(int i=0  ;  i<cts1-1  ;  i++){
			printf("%05d %d %05d\n",  node1[i].add,   node1[i].data,  node1[i].next);
		}
		printf("%05d %d -1\n"  ,   node1[cts1-1].add  ,  node1[cts1-1].data);
	}


	
	return 0;
}
