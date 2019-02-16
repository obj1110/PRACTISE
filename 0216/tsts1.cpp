#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
const int maxn = 110;

//typedef struct Node{
//	Node*lchild;
//	Node*rchild;
//	int data;
//}node;

struct node{
	int lchild;
	int rchild;
	int data;
}Node[maxn];

int n;
int data[maxn];

//���еĽ�㶼�Ǵ�0��ʼ��Ȼ��n-1���� 
void init(){
	scanf("%d",&n);
	int a,b;
	for(int i=0;i<n;i++) {
		scanf("%d %d",&a,&b);
		Node[i].data = i;
		Node[i].lchild = a;
		Node[i].rchild = b;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	sort(data,data+n);
}

//rootָ���ǽڵ��index 
int count_number  = 0;
void InOrder(int root){
	if(root == -1) return;
	InOrder(Node[root].lchild);
	Node[root].data = data[count_number++];
	InOrder(Node[root].rchild);
	return;
}

//������������Ͼ���һ��BFS�Ĳ�����������ȵĲ��� 
//ȫ�ֱ�����ͳ������ĸ��� 
int cts = 0;

void Level(int root){
	//���в����������
	queue<int> q;
	q.push(root);
	//��������л���Ԫ�صĻ� 
	while(!q.empty()){
		int index1 = q.front();
		q.pop();
		//��ӡ
		printf("%d",Node[index1].data);
		cts++;
		if(cts != n) printf(" ");
		//BFS����Ҫ�ݹ�
		if(Node[index1].lchild != -1) q.push(Node[index1].lchild);
		if(Node[index1].rchild != -1) q.push(Node[index1].rchild);
	}
}

int main(){
	init();
	InOrder(0);
	Level(0);
	return 0;
}
