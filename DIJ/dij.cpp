#include<iostream> 
#include<vector>
#include<cstring> 
#include<cstdlib>
using namespace std;

const int INF = 0x3fffff;

//����ȫ�����INF���� 
int G[maxn][maxn];
//��ʾ��v0��ÿһ����ľ������ 
int d[maxn];
//��ʾ�������DIJ�㷨����û�б�����ĳЩ�� 
bool vis[maxn] = {false};
int pre[maxn];

void Dij(int s) {
	for(int i=0;i<maxn;i++) {
		pre[i] = i;
		d[i] = INF;
	}
	fill(d,d+maxn,INF);
	d[s] = 0;
	for(int i=0 ; i<n ; i++) {
		int u = -1;
		int MIN = INF;
		//Ҳ���Ƕ����еĽڵ���Ѱ����С����ĵ� 
		for(int j=0;j<n;j++){
			if(vis[j]== false && d[j]< MIN) {
				//�Ծ��뾡�ĸ��� 
				MIN = d[j];
				u = j;
			}
		}
		if(u == -1 ) return ;
		vis[u] = true;
		for(int v = 0;v<n;v++){
			if(vis[v] == false && G[u][v] != INF && d[u]+ G[u][v] < d[v]){
				d[v]  =d[u] +G[u][v];
				pre[v] = u;
			}
		}
	}
}

//���v��������ڵ� 
void Dij_sequence(int s){
	if (v == s) {
		printf("%d\n",s);
		return;
	}
	DFS(s,pre[v]);
	printf("%d\n",v);
}
 
void DFS_Sequence(int start,int end){
	if(end == start){
		//��ӡ��� 
		printf("%d\n",start);
		return;
	}
	DFS_Sequence(start,pre[end]);
	//�ݹ���д�ӡ�����ȴ�ӡ�������Ǹ�start����ĵ� 
	printf("%d\n",end);
}



int main(){
	return 0;
}
