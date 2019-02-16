//ԭ���Ĳ����������ʹ��queue��ʹ��stack��
//emmm�ƺ�����һ��stack��������stack 

//�����Ǹ�������ͺ�����н���
//��������������̬�洢�������ȽϺ�  
#include<iostream> 
#include<stack>
#include<cstring>
#include<cstdlib>
// The second line gives the inorder sequence 
// and the third line gives the postorder sequence
using namespace std;
const int maxn = 35;

stack<int> st1,st2;
int n,temp;
//һ����ǰ�����У�һ���Ǻ������� 
int in[maxn],post[maxn];
//�������������� 
int tree[maxn][2];

//��θ���һ������ͺ�����н��н�������
//��Ȼ���õݹ����ʽ���в����� 
struct Node{
	int lchild;
	int rchild;
	int data;
}node[maxn]; 

void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
}

//��ʵ�����һ���ݹ齨���Ĺ���
//����˵��һ��һ�� 
void dfs(int& index,int inleft,int inright,int postleft,int postright){
	//����ͬ 
	if(inleft > inright )  return;
	//���˵ֻʣ��һ���ڵ㣬��ִ�в��빤��	
	index  = postright;
	//Ѱ�����������кͺ������һ��Ԫ�ص�value��Ԫ����� 
	int i = 0;
	while(in[i] != post[postright]) i++;
	//��������Ԫ�ظ��� 
	int left_num = i - inleft; 
	
	//�����dfs������Ҫ����������ڵ� 
	//�����������в��� ,�Ժ������еı������Ǵ��������ĵ�һ���㿪ʼ�������������ĸ��� 
	dfs(tree[index][0], inleft , i-1 ,  postleft, postleft + left_num -1);
	//�����������в���
	dfs(tree[index][1], i+1 , inright , postleft + left_num, postright - 1);
	//Ҳ���Ǽ�����������Ԫ�صĸ��� 
}

int main(){
	memset(pre,-1,maxn);
	memset(post,-1,maxn);
	init();
	
	return 0;
}
