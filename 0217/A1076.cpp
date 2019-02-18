///1076 ����ͼ�Ĺ�����ȱ��� 
//һ���˿���ָ����ˣ�����Ҳ����ָ���Լ� 

//��ĳһ��������������̶�����ȣ����漰���������أ��������� 

//ע�⣺����ĵ����Ŵ�1��ʼ 

//˼·��������ȱ�������ÿһ�������������ȣ���󵥶�ͳ��
//˼·���ڱ�����ͬʱ������ȣ�����һ�������֮��ֱ�ӷ���
//ͬʱ���һ��ȫ�ֱ���ͳ�Ƹ��� 
#include<iostream> 
#include<vector>
#include<algorithm> 
#include<queue> 

using namespace std;
const int maxn = 1010;
//ע�⣬����������ͼ��Ҳ����˵[a][b]��ʾ���Ǵ�a��b 

int v[maxn][maxn] = {0};
int N,L,M,K,index; 

int BFS(int index,int depth) {
	
	int vis[maxn] = {0};
	int cnt = 0;
	queue<int> q1;
	queue<int> q2; 
	
	q1.push(index);
	vis[index] = 1;
	while((!q1.empty() || !q2.empty()) && depth <= L){
		while(!q1.empty()){
			int id = q1.front();
			q1.pop();	
			cnt++; 
			for(int i = 1;i<=N;i++){
				if(v[id][i] == 1 && vis[i] == 0) {
					q2.push(i);
					vis[i] = 1;
				}
			}	 
		}
		depth++;
		if(depth >L ) return cnt;
		while(!q2.empty()){
			int id = q2.front();
			q2.pop();
			cnt++; 
			for(int i = 1;i<=N;i++){
				if(v[id][i] == 1 && vis[i] == 0) {
					q1.push(i);
					vis[i] = 1;
				}
			}	
		}
		depth++;
	}
	return cnt;
}

int main(){
	scanf("%d%d",&N,&L);
	//i�ǵ� 
	int temp;
	for(int i=1 ;i<=N;i++) {
		scanf("%d",&M);
		//j�Ǽ������� 
		for(int j=0;j<M;j++){
			scanf("%d",&temp);
			//��i��temp��ͨ��  
			v[i][temp] = 1;
		}
	}
	//��ѯ�� 
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d",&index);
		printf("%d\n",BFS(index,0)-1 );
	}
	return 0;
}
