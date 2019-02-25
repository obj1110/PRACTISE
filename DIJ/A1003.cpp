#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1010;
const int inf = 0x3ffffff;
 
int n,c1,c2,m;
//��̾���+����Ȩ
int G[maxn][maxn]; 
int d[maxn] ;
bool vis[maxn] = {false};
int pre[maxn];
//p �Ǵ���㵽ĳһ����ĵ�Ȩ֮�� 
int p[maxn];
//point�ǵ�Ȩ 
int point[maxn];
//����ĳһ�����ʱ������·���ĸ��� 
int num[maxn]; 

void dij(int s){
	fill(d,d+maxn,inf);
	vis[s] = true;
	for(int i=0;i<n;i++){
//		��仰��Ӧ��������inf�������޷�������ȥ 
//		d[i] = inf;
		pre[i] = i;
	}
	d[s] = 0;
	//
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		//ͼ�е�Ԫ�ص�����Ǵ�0��ʼ��
		//�����Ǵ�1��ʼ�� 
		for(int j =0;j<n;j++){
			if(min > d[j] && vis[j] == false) {
				min = d[j];
				u = j;
			}
		}
		if(u = -1) return;
		vis[u] = true;
		for(int v=0;v<n;v++){
			if(vis[v] == false && G[u][v] != inf){
				if(d[u] + G[u][v] < d[v]) {
					//�漰��u��Ϊ�м�ڵ����� 
					d[u] = d[v] + G[u][v];
					pre[v] = u;	
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}
				else if(d[v]+G[u][v] == d[u]){
					//����·����̣���Ҫ���Ȩ��� 
					if(w[u] + weight[v] > w[v]){
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];	
				}
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&c1,&c2,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&point[i]);
	}
	int a,b,c;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			G[i][j] = G[j][i] = inf;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c); 
		G[a][b] = G[b][a] = c;
	}
	//���벿�����
	dij(c1);
	//������·���ĸ��� + ��Ȩ����Ƕ��� 
	printf("%d %d\n",num[c2],w[c2]);
	return 0;
}
