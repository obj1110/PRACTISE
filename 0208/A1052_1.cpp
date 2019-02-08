#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 1000100;

struct Node{
	int add;
	int next;
	int data;
	int flag;
}node[maxn];

bool cmp(Node a,Node b) {
	if(a.flag != b.flag) return a.flag > b.flag;
	//由高处向低处进行排序
	else{
		return a.data < b.data;
	}  
}

int main(){
	int head,n,cts=0;
	int a,b,c;
	scanf("%d %d",&n,&head);
	
	while(n--){
		scanf("%d %d %d",&a,&b,&c);
		node[a].add = a;
		node[a].data = b;
		node[a].next = c;
	}
	
	
	while(head!=-1){
		cts++;
		node[head].flag = 1;
		head = node[head].next;
	}
	 
	sort(node,node+maxn,cmp);
	
	if(cts==0){
		printf("0 -1");
		return 0;
	}
	
	
	head  = node[0].add;
	printf("%d %05d\n",cts,head);
	for(int i = 0;i<cts;i++){
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
