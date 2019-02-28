//���ȱ��ⲻ�Ƕ���������һ������� 
//1090 ����Ҫʹ��ʲôstruct������������Ҫʹ�ýṹ�壬����˵�����������ʲô�����ϵĲ�𣬶���˵��������Ľڵ㲻ͬ
//1090�Ľڵ�û���κεĸ�����Ϣ����1079�Ľڵ�����Ŵ����ĸ�����Ϣ 
#include<iostream> 
#include<algorithm>
#include<queue>
#include<stack> 
#include<cmath> 
#include<vector>

using namespace std;

const int maxn = 100010;

//���ľ�̬д����������
//���Ķ�̬д�������������ָ�� 
struct node{
	double data;
	vector<int> child;
}Node[maxn]; 

int father,root;

double p,r,ans;//p�Ǽ۸�r��ratio����,ans���ܼ�ֵ 

// ȫ�ֱ��������ڼ��������� 
//numf���������ȵĽڵ����  
int n,maxDepth,num,k,child; 


//�������ľ�̬����洢��ʽ����ʽ��ž���һ����ά���飬��һ��ά�ȴ���ڵ�
//�ڶ���ά�ȴ�������ڵ���ӽڵ����� 
void DFS(int index,int depth){
	//�����Ҷ�ڵ� 
	if(Node[index].child.size() == 0 ) {
		ans += Node[index].data * pow(1+r,depth);
		//һ�������ӽڵ��Ҫ������ 
		return ;
	} 
	//�������Ҷ�ڵ� 
	else if( Node[index].child.size() != 0 ) {
		for(int i = 0;i < Node[index].child.size();i++) {
			DFS(Node[index].child[i],depth+1);
		}
	}
}


//����Ĳ���
//0�Žڵ�̶���root
//���ȸ����ӽڵ�ĸ���������ӽڵ�ĸ�����0 ����ô��������־����ӽڵ�Ļ�����
//����ӽڵ�ĸ�������0, �Ǻ���Ķ��������ӽڵ��id�ţ�����Щid�ŷ��ڶ�ά����ĵڶ���ά����
//�������ľ�̬����
 
void init(){
	//ע��double��Ӧ��������lf������f 
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100.0;
	for(int i=0 ; i<n ; i++){
		scanf("%d",&k);
		if( k ==0){
			scanf("%lf",&Node[i].data);
		}
		else{
			for(int j = 0;j<k;j++){
				scanf("%d",&child);
				Node[i].child.push_back(child);
			}
		}
	}
}

int main(){
	init();
	DFS(0,0);//0�Žڵ㣬�����0
	printf("%0.1f\n",p*ans);
	return 0;
}
