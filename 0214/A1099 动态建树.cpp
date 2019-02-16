#include<iostream> 
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn = 110;
int data[maxn];
int n,cts,num;

struct node{
	int data, lchild,rchild;
}Node[maxn];

void InOrder(int root) {
	if(root == -1){
		return;
	}
	InOrder(Node[root].lchild);
	Node[root].data = data[cts++];
	InOrder(Node[root].rchild);
}

//������������Ĺ�����ȸ������������һ���� 
void BFS(int root){
	queue<int> q;
	q.push(root);
	num = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		printf("%d",Node[now].data);
		num++;
		if(num < n) printf(" ");
		if(Node[now].lchild != -1) q.push(Node[now].lchild);
		if(Node[now].rchild != -1) q.push(Node[now].rchild);
	}
}

int main(){
	int lchild,rchild,data;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&lchild,&rchild);
		Node[i].lchild = lchild;
		Node[i].rchild = rchild;
	}
	for(int i = 0; i<n ; i++ ){
		scanf( "%d" , &data[i] );
	}
	sort(data,data+n);
	//����������Ĺ���˳�㽨��һ����
	InOrder(0);//��0�Žڵ㿪ʼ������� 
	 
	BFS(0);//��0�Žڵ㿪ʼ���в������ 
	return 0;
}
