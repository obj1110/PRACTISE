//�����޻�ͼ
//���ĸ߶�ȡ������ѡ�����������һ��
//����Ҫ��������ĸ߶���ߵ�ʱ���Ӧ����������һ��������
//������������ the deeepest root  
#include<iostream> 
#include<algorithm> 
#include<cstring>
//��Ҫ�������Ҫ���Ǵ�С��� 
#include<set>

using namespace std;
const int maxn = 10010;
//����Ķ����1��ʼ
int v[maxn][maxn];//��¼��ͨ�� 
//cntר��������������ͨ�����ĸ����� 
int n,a,b,cnt = 0;
bool isTree = false;
//ÿ�θ��� 
int d[maxn]; //��¼��ǰ�ڵ��ͼ���б����õ���ͼÿһ���ڵ����� 
int visit[maxn];//��¼��ǰ���һ����ȵ���� 
//������ 
int result[maxn]; //��ȼ�¼���飬key�ǵ�ǰ�ڵ㣬value����� 


void dfs(int index,int depth){
	//��ǰ�ڵ��Ѿ����������� 
	visit[index] = 1;
	//�����������еĹ�ϵ���б���
	for(int i=1;i<=n;i++) {
		if( v[index][i]==1 && visit[index] == 0){
			dfs(i,depth+1);
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b); 
		v[a][b] = v[b][a] = 1;
	}
	//
	for(int i=1;i<=n;i++){
		memset(d,-1,maxn);
		memset(visit,0,maxn);
		dfs(i,1);
		//
		int max_depth = 0; 
		for(int j=1;j<=n;j++) {
			if(d[j] == -1){
				isTree = false;
				//����ȥ������ͨ�����ĸ��� 
				cnt = 2;
				printf("Error: %d components",cnt);
				return 0;
			}
			if(d[j] > max_depth){
				max_depth = d[j];
			}
		}
		result[i] = max_depth;
	}
	//
	//	��result������д���
 	for(int i=1;i<=n;i++) {
 		cout<<result[i]<<" ";
	 }
	return 0;
}
//��ÿһ�����㣬��ʼ���б��� 
//���Ǻܻ�����ͼ�ĵݹ������ֻ����ǿ����ʹ��DFS����ΪҪͬʱ����Ⱦ���ֵ 
