//����1064�����
//��BST������������õ��������������
//��Ž��������е�BST��˳�����������BST�Ĳ������ģʽ

//Ҳ����˵����BST���в��������Ԫ�ؾ�������������м�ڵ�

//��������Ľ������һ���������У���������������м���̾���һ�������е�Ԫ�أ�
//��������Ľڵ������������Ľ��

//����ĵ�һ��Ԫ�� �ǲ�������ĵ�һ��Ԫ�� ����������������ĵ�һ��Ԫ��

//ͨ������������Ի�֪ÿһ�����鵥Ԫ��Ӧ�Ľڵ�����
//������ڵ���1�Žڵ㣬������2�ź�3�Žڵ㣬���Ǵ洢��Ԫ��ֵ�أ���������������н��и�ֵ 

//���������������о���һ��˳�����У����Զ�Ӧ��Ԫ��ֵ�������������������ʱ����и�ֵ���� 
#include<iostream> 
#include<algorithm>
using namespace std;
const int maxn = 1010;
int data[maxn] ,tree[maxn];

//index��1��ʼ������Ƕ�������̬�洢����� 
//cts�Ǵ�0��ʼ�Ĵ���˳�������õ� 
int index;
int cts = 0;
int n;
//indexָ���ǽڵ�ı�� 
void InOrder(int index){
	if(index>n) return;
	InOrder(index*2) ;
	tree[index] = data[cts++];
	InOrder(index*2+1) ;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	sort(data,data+n);
	InOrder(1);
	for(int i=1;i<=n;i++){
		printf("%d",tree[i]);
		if(i != n ) cout<<" ";
	}
	return 0;
}
 
