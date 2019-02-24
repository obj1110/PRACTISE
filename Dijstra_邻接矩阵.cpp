#include<iostream> 
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;

const int maxn = 100100;
const int inf = 0x3fffff;

void Dijstra(){
	
}

void Dij(int start){
	fill(d,d+maxn,INF);
	d[start] = 0;
	for(int i=0;i<n;i++) {
		int u = -1;
		int MIN = INF;
		for(int j = 0;j<n;j++){
			u = j;
			MIN = d[j];
		}
		if( u== -1) return;
		vis[u] = true;
		for(int v= 0;v<n;v++){
			if(vis[v] == false && G[u][v] != INF && d[u]+ G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
			}
		} 
	}
}

void DijAdv(int start){
	//���Ȼ��ǰ������������ȫ������ΪINF 
	fill(d,d+maxn,INF);
	//Ȼ����ǰ�һ��pre������г�ʼ��������ָ��ľ����Լ����� 
	for(int i=0;i<n;i++){
		pre[i] = i;
	}
	//Ȼ����Ƕ��ھ������飬��ǰ�ڵ�ĳ�ʼ����ʵ�����Ǳ���v0 
	d[s] = 0;
	//Ȼ�����ʣ��ڵ�һ��һ���ӽ��� 
	for(int i=0;i<n;i++) {
		//����Ѱ����̵ľ��� 
		int u = -1;
		int MIN = INF;
		//��̵ľ������d[j]��Ҳ��������Ѱ����̵ľ�������һ��Ԫ�� 
		for(int j = 0;j<n;j++){
			if(vis[j] == false && d[j] <MIN){
				u = j;
				MIN = d[j];
			}
		}
		//��֦ 
		if(u == -1) {
			return;
		}
		//
		vis[u] = true;
		//���ں�u����С���룩������ÿһ���ڵ� 
		for(int v =0;v<n;v++) {
			if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] <d[v]){
				d[v] = d[u] + G[u][v];
				//����漰������ĸ��£���Ҫ���ǵ����ǵ�֮���ǰ���ϵ 
				pre[v] = u;
			} 
		}
	}
}
