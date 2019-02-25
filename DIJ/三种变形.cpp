#include<iostream> 
#include<algorithm> 
#include<vector>
using namespace std;

const int INF = 0X3ffffff;
const int maxn = 0xff;

int n;   //n���ǽڵ���Ŀ 
int G[maxn][maxn];
int pre[maxn]; //��ʼ����������µ�ʱ���޸� 
bool vis[maxn] = {false};//ֻ�ܽ���һ�γ�ʼ�� 
int d[maxn]; //��ʾ���ǵ㵽��ľ������ 

// 1
void DIJ0(int s){
	fill(d,d+maxn,INF);
	vis[s] = 1;
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1;
		int MIN = INF;
		for(int j = 0 ; j < n ; j++){
			if(vis[j] == false && MIN > d[j]){
				MIN = d[j];
				u = j;
			}
		}
		if( u == -1 ) return;
		vis[u] = true;
		//���ҵ��ľ���ڵ���о���ĸ��� 
		for(int v = 0; v<n;v++){
			//d[u]������d[v]���Ǵ�v0������ֱ�ӵ�u������v�ľ������ 
			if(vis[v] == false && G[u][v] + d[u] < d[v]){
				d[v] = G[u][v] + d[u] ;
				///���¾����ʱ��˳�����ǰ�� 
				pre[v] = u;
			}
		}
	}
} 
// 1
//��v0�������ڵ�ľ��� 
int c[maxn];
//�����ڵ�֮���cost������� 
int cost[maxn][maxn];

void DIJ1(int s){
	fill(d,d+maxn,INF);
	vis[s] = 1;
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1;
		int MIN = INF;
		for(int j = 0 ; j < n ; j++){
			if(vis[j] == false && MIN > d[j]){
				MIN = d[j];
				u = j;
			}
		}
		if( u == -1 ) return;
		vis[u] = true;
		//���ҵ��ľ���ڵ���о���ĸ��� 
		for(int v = 0; v<n;v++){
			if(vis[v]==false && G[u][v] !=INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
				}
				else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
					c[v] = c[u] + cost[u][v];
				}
			}
		}
	}
} 
// 2
// ĳ������������ 
int weight[maxn];
// ��V0��ĳ����Ŀ����ռ�������������� 
int w[maxn];
void DIJ2(int s){
	for(int i=0;i<n;i++){
		//�������黹����Ҫ�� 
		pre[i] = i;
		w[i] = 0;
	}
	fill(d,d+maxn,INF);
	d[i] = 0;
	vis[i] = 1 ;
	w[s] = weight[s];
	for(int i=0;i<n;i++){
		int u = -1;
		int MIN = inf;
		for(int j=1;j<=n;j++){
			if( MIN > d[j] && vis[j]== false) {
				u = j;
				MIN = d[j];
			}
			if(u == -1) return;5
			vis[u] = 1;
			for(int v= 0;v<n;v++){
				if(vis[v] == false && G[u][v] != INF){
					if(d[u] + G[u][v] <d[v]){
						d[v] = d[u] + G[u][v];
						//v������u������ͨ���ĵ�ļ������ 
						w[v] = w[u] + weight[v];
					}
					//������ȣ����Ǿ��������Ҳ������ռ������������ 
					else if(d[u] + G[u][v] == d[v] && w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					} 
				}
			}
		}
	}
} 
// 3  
int n;
int G[maxn][maxn];
int d[maxn] = {0};
int pre[maxn];
int num[maxn] ={0};
bool vis[maxn] = {false};

void DIJ3(int s){
	fill(d,d+maxn,INF);
	for(int i =1 ;i<=n;i++){
		pre[i] = i;
	}
	for(int i=0;i<n;i++){
		int u = -1;
		int MIN =INF;
		//�ӵ�u����Χ�ĸ������һ��������� 
		for(int j = 1;j<=n;j++){
			//�������û�б�����ĳһ���� 
			if(vis[v]== false && MIN > d[j]){
				u = j;
				MIN = d[j];
			}
		}
		if( u == -1 )  return;
		vis[u] = true;
		for(int v = 1; v <= n;v++){
			if(vis[v]== false && G[u][v] != INF) {
				if(d[u]+ G[u][v] <d[v] ){
					d[v] = d[u] + G[u][v];
					num[v] = num[u];
				}
				else if(d[u]+G[u][v] == d[v]) {
					//���·��+num[u]
					//����u�����·�� �� ����v�����·�� 
					num[v] += num[u];
				}
			}
		}
	}

} 
//ʹ�õݹ�ķ�ʽ�����ؽ����� 
void DIJ_sequence(int start,int end){
	if(start == end){
		printf("%d\n",start);
		return;
	}
	DIJ_sequence(start,pre[end]); 
	printf("%d\n",end);
}
//
 
int main(){
	
	return 0;
}
