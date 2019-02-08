#include<iostream>
#include<algorithm>
#include<cmath> 
#include<cstring>

using namespace std;

//注意：vivid 有效数据 
//seq 有效数据使用情况 
struct Node{
	int address,data,seq,next;
	int vivid;
}node[maxn]; 

//与A1097相比较，本代码的水平，明显高了一层，体现在对于数组元素属性的设置上。
//数据的输入，hashTable的设置， 
 

int HashTable[10010],first,N;
int count1 = 0,count2 = 0,p;

bool cmp(Node a,Node b){
	if(a.vivid != b.vivid){
		return a.vivid > b.vivid;
	}
	else{
		return a.seq < b.seq;
	}
}

void init(){
	int i;
	int address;
	scanf("%d %d",&first,&N);
	for(i=0;i<N;i++){
		scanf("%d",&address);
		scanf("%d %d",&node[address].data,&node[address].next);
		node[address].address = address;
	}
	p = first;
	i =0;
	while(p!=-1){
		node[p].seq = i++;
		if(HashTable[abs(node[p].data)] == 0){
			node[p].vivid = 2;
			count1 ++;
			HashTable[abs(node[p].data)] =1;
		}
		else{
			node[p].vivid = 1;
			count2++;
		}
		p = node[p].next;
	}
	sort(node,node+maxn,cmp);
}

void print(){
	int i = 0;
	if(count1 >0){
		printf("%05d %d",node[0].address,node[0].data);
		i = 1;
		while(i<count){
			printf("%05d\n%05d %d ",node[i].address,node[i].address,node[i].data);
			i++;
		}
		printf("-1\n");
	}
	if(count2>0){
		printf("%05d %d ",node[count1].address,node[count1].data);
		i = count1 + 1;
		count2 += count1;
		while(i<count2){
			printf("%05d\n%05d %d",node[i].address,node[i].address,node[i].data);
			i++;
		}
		printf("-1\n");
	}
}

int main(){
	init();
	print();
	return 0;
}
