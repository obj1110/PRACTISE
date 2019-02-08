#include<iostream> 
#include<algorithm> 
#include<cstdlib>
#include<cstring>

using namespace std;

//容纳99999 
const int maxn = 100100;
//数据范围 int 正负10万 
struct Node{
	int data;
	int next;
	int add;
	int flag; //flag==1 表示的是有效节点
	//flag==0 表示的是无效节点 
}node[maxn];

//Node 是结构体类型 node 是结构体数组 

//cmp的作用，筛选有效节点，并进行二次处理 
bool cmp(Node a,Node b){
	//如果至少存在一个无效节点 
	if(a.flag != b.flag) return a.flag > b.flag;
	else{
		return a.data < b.data; 
	}
}

int main(){
	int h1,n;
	int a,b,c;
	int cts = 0 ;
	scanf("%d %d",&n,&h1);
	while(n--){
		scanf("%d %d %d",&a,&b,&c);
		node[a].add = a;
		node[a].data = b;
		node[a].next = c;
	}
	//输入的节点不一定都是在链表上的 
	//遍历链表，更新flag 
	while(h1 != -1){
		cts++;
		node[h1].flag = 1;
		h1 = node[h1].next;
	}
	sort(node,node+maxn,cmp);
	 
	h1 = node[0].add;
	//special 
	if(cts==0){
		printf("0 -1");
		return 0;
	}
	// 
	printf("%d %05d\n",cts,h1);
	for(int i=0;i<cts;i++){
		printf("%05d %d",node[i].add,node[i].data);
		if(i!= cts-1){
			printf(" %05d\n",node[i+1].add); 
		}
		else{
			printf(" -1\n");
		}
	}
	return 0;
}
