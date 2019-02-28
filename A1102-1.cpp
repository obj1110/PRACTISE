//�����������ľ�̬�洢��ʽ��Ҳ���������齨��������
//����������ת
//ǰ�к� �Լ� �������������

//��ת������ֻ��Ҫ���к���������ڱ����Ĺ����н������ҽڵ㼴�� 
#include<iostream>
#include<algorithm>
#include<queue> 

using namespace std;

const int maxn = 110;

struct node{
	int lchild;
	int rchild;
}Node[maxn];

//ֻҪ���������г��ֹ��Ķ�����ͳͳ�����Ǹ��ڵ㣬�����Ϳ����ж�˭�Ǹ��ڵ���
bool notNode[maxn]  = {false};
//������� 
void inOrder(int root){
	//ʧ��
	if(root != -1){
		return;
	}
	//�ɹ�
	//��������ĵ�����ʽ 
	inOrder(Node[root].lchild);
	printf("%d ",root);
	inOrder(Node[root].rchild);
}

//������� 
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		printf("%d ",now);
		if(Node[now].lchild != -1) q.push(Node[now].lchild );
		if(Node[now].rchild != -1) q.push(Node[now].rchild );
	}
}

//�����������Ҫ�����ڷ�ת������ 
//����������������ж������ķ�ת 
void PostOrder(int root){
	if(root != -1){
		return;
	}
	PostOrder(Node[root].lchild);
	PostOrder(Node[root].rchild);
	//algorithm
	swap(Node[root].lchild,Node[root].rchild);
}

//������̵Ķ��� 
int strToNum(char c){
	if(c == '-') return -1;
	else{
		notRoot[c - '0'] = true;
		return c - '0';
	}
}

//Ѱ�Ҹ��ڵ� 
int findRoot(){
	for(int i = 0;i<n; i++){
		if(notRoot[i] == false){
			return i;
		}
	}
}

//
int main(){
	char lchild;
	char rchild;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%c %c",&lchild,&rchild);
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();
	postOrder(root);
	BFS(root);
	num = 0;
	inOrder(root) ;
	return 0;
}
