#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int n,number[maxn],CBT[maxn],index = 0 ;
void MidOrder(int root){
	//�սڵ�ֱ�ӷ��� 
	if(root  > n ) return;
	//�������ݹ� 
	MidOrder(root*2);
	//���ָ�ֵ������ʵ����һ�ִ�ӡ�Ĳ��� 
	CBT[root] = number[index++];
	//���������еݹ� 
	MidOrder(root*2+1);
}

int main() {
	scanf("%d",&n);
	//number�����ݴ����ݣ���Ԫ���ݴ���number�� 
	for(int i=0;i<n;i++){
		scanf("%d",&number[i]);
	}
	sort(number.number+n);
	//��1�Žڵ㿪ʼ���б��� 
	MidOrder(1);
	for(int i=1;i<=n;i++) {
		printf("%d",CBT[i]);
		if(i<n) printf(" ");
	}
	return 0;
}

//˼·һ;��ȡ���ݣ��������������б���������
//˼·������ȡ���ݣ�ֱ�ӱ��������ڶ��������԰������˳����ȷ���İ� 
