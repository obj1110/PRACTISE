//post��pre�ظ�������������������һ����������

//����ǰ����������������
//���������������ɶ���������������Ƿ�Ψһ�������������һ�߲�����������Ψһ���������Ϊ�������������ϣ���
//����������ɵĶ���������¼���������
//������ĿҪ����������������ֵ��

#include<iostream> 
#include<vector>
#include<stack>

using namespace std;

const int maxn = 35;
int n;
int pre[maxn],post[maxn],mid[maxn];

void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",mid[i]);
	}
}

//�۲�pre��post�Ľ����֪
//pre�ĵ�һ��Ԫ����post�����һ��Ԫ�أ����߶������ĸ��ڵ�
//pre�ĵڶ���Ԫ��һ��Ҳ��ĳһ�������ĸ��ڵ㣬�ں����������ҵ�����㣬�����֮ǰ�Ķ���һ����������������� 

int main(){
	init();
	
}
