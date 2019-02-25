#include<iostream> 
#include<vector>
#include<cstring>
#include<cstdlib>
#include<algorithm> 

using namespace std;

const int maxn = 100100;
const int inf = 0x3fffff;

//����ڽӱ�ÿһ���ڵ��е�v����Ķ���һ����
//����Adj[v].size() ��ʵ��ʾ�ľ��Ǹ�v����ͨ�ĵ�ĸ���
//Adj[v].size() Ҳ���Ǹ�v���������еĵ� 
struct node{
	int v;
	int dis;
}; 
//��ʵ��һ��Node���͵Ķ�ά���� 
vector<Node> Adj[maxn];
int n;
int d[maxn];
bool vis[maxn] = {false};
void Dijstra(int s){
	fill(d,d+maxn,INF);
	d[s] = 0;
	//�ܹ�Ҫ���ж��ٴ�  
	for(int i=0;i<n;i++){
		//ÿ�ζ�������Ѱ����С 
		int u = -1; 
		int MIN = INF;
		for(int j = 0;j<n;j++) {
			if(vis[j] ==false && d[j] <MIN){
				u = j;
				MIN = d[j];
			}
		}
		if( u == -1) return;
		vis[u] = true;
		for(int j=0;j<Adj[u].size();j++) {
			//Ҳ��������ͨ�Ľڵ� 
			int v = Adj[u][j].v;
			//�ڽӱ��ʾ���Ǿ��� 
			//һ����û�з��ʹ��Ľڵ㼯�ϲ��и��µļ�ֵ����ѡ
			//һ����Ҫ��ͨ�����ٽ���в���Ҫ ����ѡ 
			//һ���Ǿ���Ĺ�ϵ ����ѡ 
			if(vis[v] == false && d[u]+Adj[u][j].dis < d[v]){
				d[v] = d[u] + Adj[u][j].dis; 
			}
		}
	}
}

struct node{
	int v;
	int dis;
};
vector<node> adj[maxn];
int n;
int d[maxn];
bool vis[maxn] = {false};

void dijstra(int s){
	fill(d,d+maxn,INF);
	d[s] = 0;
	for(int i = 0 ;i< n;i++){
		//u��¼���ǵ�ǰ�Ľڵ�����һ��
		//dis��¼���ǵ�ǰ����С���� 
		int u = -1;
		int MIN = INF;
		for(int j = 0;j< n;j++) {
			if (vis[j] == false && d[j] <MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1 ) return;
		vis[u] = true;
		for(int j = 0;j<Adj[u].size;j++){
			//���ҿ������ĸ��ڵ� 
			//u�ǵ�ǰ��С����Ľڵ㣬���Զ����к�u��ͨ�Ľڵ���и��� 
			int v = Adj[u][v].v;
			if(vis[v] == false && d[u] + Adj[u][v].dis < d[v]){
				d[v] = d[u] + Adj[u][v].dis;
			}
		}
	}
}




int main(){
	
}
