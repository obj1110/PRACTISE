//在链表采用静态链表，储存时加一个数据域，存储是否被访问过；
//第一个链表遍历同时修改访问位；


//遍历第二个链表时遇到访问过的情况则表明找到公共后缀的起点，如到末尾也未找到说明没有公共后缀；


//输出结果并返回0值。

//输入的情况是第一行两个链表的头节点 和行数
 
 
//本题中不用考虑任何的跟数据有关的内容，单纯考虑地址即可 
 
#include<iostream> 
#include<vector>
const int maxn  = 100010;

using namespace std;

//所有的地址不超过99999，所以你的数组开100k就行 
struct Node{
	int next;
	int vis;
}node[maxn];

int main(){
	int h1,h2,h3,n;
	int a,c;
	char b;
	scanf("%d %d %d ",&h1,&h2,&n);
	//存储数据 
	for(int i=0;i<n;i++){
		scanf("%d %c %d",&a,&b,&c);
		node[a].next = c;
		node[a].vis = 0;
	}
	//构造第一个表访问的情况 
	while(h1 != -1) {
		node[h1].vis = 1;
		h1 = node[h1].next;
	}
	while(h2 != -1){
		if(node[h2].vis != 1 ){
			h2 = node[h2].next;
			continue;
		}
		else{
			break;
		}
	}
	// 处理h2的while循环
	if(h2==-1) {
		printf("-1");
	}
	else{
		printf("%05d",h2);
	}
	return 0;
}
