//��������ָ���һ����������ʹ�þ�̬��ʽ����һ�������� 
//�����1064��������Ƕ�����ȫ�������������������͵�������Ǳ��⻹���Ƽ����� 
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn  = 105;
int n,int data[maxn];
vector<int> tree[maxn];
bool isLeaf[maxn] = {false};
int level[maxn];

void init() {
	scanf("%d",&n);
	int a,b;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(a == -1 && b==-1){
			isLeaf[i] = true;
		}
		vector[i].push_back(a);
		vector[i].push_back(b);
	}
	for(int i=0;i<n;i++) {
		scanf("%d",data[i]);
	}
}

int root =0 ; 
int index = 0; 
// root�ǵ�ǰ�����ĸ��ڵ�
//index��˳�����еĵ�ǰ����Ԫ�� 
void InOrder(int root) {
	if(root >= n) return;
	InOrder(root*2+1);
	level[root] =  data[index++];
	InOrder(root*2+2);
}

int main(){
	init();
	//����������洢Ϊ-1 
	memset(data,-1,maxn);
	// 
	return 0;
}
