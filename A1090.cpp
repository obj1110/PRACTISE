//���ȱ��ⲻ�Ƕ���������һ������� 

#include<iostream> 
#include<algorithm>
#include<queue>
#include<stack> 
#include<cmath> 
#include<vector>

using namespace std;

const int maxn = 100010;
int father,root;
	
//child�����ŵ���ÿһ���ڵ���ӽڵ����ʲô 
vector<int> child[maxn] ;
double p,r;//p�Ǽ۸�r��ratio����
// ȫ�ֱ��������ڼ��������� 
//numf���������ȵĽڵ����  
int n,maxDepth,num; 


//�������ľ�̬����洢��ʽ����ʽ��ž���һ����ά���飬��һ��ά�ȴ���ڵ�
//�ڶ���ά�ȴ�������ڵ���ӽڵ����� 
void DFS(int index,int depth){
	//�����Ҷ�ڵ� 
	if(child[index].size() == 0 ) {
		if(depth > maxDepth) {
			maxDepth  = depth;
			num = 1;
		}
		else if(depth == maxDepth){
			num++;
		}
		//һ�������ӽڵ��Ҫ������ 
		return ;
	} 
	//�������Ҷ�ڵ� 
	else if(child[index].size() != 0) {
		for(int i = 0;i<child[index].size();i++) {
			DFS(child[index][i],depth+1);
		}
	}
}

void init(){
	//ע��double��Ӧ��������lf������f 
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100.0;
	for(int i=0;i<n;i++){
		scanf("%d",&father);
		if(father != -1){
			child[father].push_back(i);
		}
		else{
			root = i;
		}
	}
}

int main(){
	init();
	
	//���ڵ����� 
	DFS(root,0);	
	printf("%.2f %d\n", p*pow(1+r , maxDepth),num);
	return 0;
}
