#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

//���鼯����ʼ���������е�Ԫ�ؽ����Լ���һ�����ϡ�
struct Node{
	int data;
	int rank;
	int father;//������һ��ָ�룬ָ����� 
}node[maxn]; 
//ע������node 
//���鼯Ҳ����ʹ���������ʽ�����о�
int set[maxn];
int rank[maxn];
int data[maxn];
void make_set(int i){
	
}


//�ж������ڵ��ǲ�������ͬһ������ ��father��������ж� 
//�������ڵ���кϲ� ��union���� 
int father[maxn];


//ע����ڵ�ĸ��׽ڵ������Լ� 
int findF(int x){
	while(x != father[x]){
		x = father[x];
	}
	//�˳�ѭ����ʱ��϶���	 
	return x;
}

//·��ѹ��,����·������·���ϵ�ÿһ���㶼�����޸� 
int findFather(int v){
	if(v == father[v]) return v;
	else{
		int F =findFather(father[v]);
		//��仰������·���ϵ����е�ֱ�����������յĸ��ڵ�λ�� 
		father[v] = F;
		return F;
	}
}

//���鼯�ĺϲ������ǡ������Ȳ���һ�����ڵ� 
//���������ڵ�Ĺ�ϵָ��Ϊfather�Ĺ�ϵ 
void union(int a,int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	//���a��b����һ������ 
	if(faA != faB)  {
		father[faA] = faB;
		father[faB]	= faA;
	}
}

int main(){
	
}
