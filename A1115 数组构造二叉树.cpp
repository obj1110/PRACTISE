#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

const int maxn = 1010;
int n,temp;
int data[maxn];

struct node{
	int lchild;
	int rchild;
	int data;
	//�����ԣ�true��ʾ���ã�false��ʾ�Ѿ���ռ���� 
	bool vis;
}Node[maxn];
//��¼���ǲ�ͬ�ڵ����ڵĲ��
 
int level[maxn];
void init(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
		//�����ж�˵��һ��һ���Ŀսڵ� 
		Node[i].vis = true;
		Node[i].lchild = -1;
		Node[i].rchild = -1;
	}
	sort(data,data+n);
}

//����Ĳ��뺯��������5����� 

//ͳ��Ŀǰ�Ѿ��������еĽڵ�ĸ��� 
int count_number = 0;
void insert(int root) {
	if(count_number == n) return;
	//����ͬ ���Ը��ڵ���в��� 
	if(count_number == 0 ){
		Node[root].data = data[count_number++];
		Node[root].vis = false;
	}
	//������Ľڵ��ֵ  
	else if(count_number > 0 && Node[root].vis == true ) {
		//������ж�������ʾһ���յĽڵ� 
		Node[root].data = data[count_number++];
		Node[root].vis = false;
	}
	else if(count_number > 0 && Node[root].data < data[count_number]){
		insert(Node[root].lchild);
	}
	else if(count_number > 0 && Node[root].data > data[count_number]){
		insert(Node[root].rchild);
	}
	//��һ��ڵ���в���
}

//��д����Ĳ��뺯������count_number������һ�����ñ��� 


int main(){
	init();
//	for(int i=0;i<n;i++){
//		cout<<data[i]<<" ";
//	}
	memset(level,-1,n);
	//��һ��һ��Ҫע�� 
	node* root = new node; 
	return 0;
}
