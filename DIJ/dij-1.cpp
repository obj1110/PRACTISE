#include<iostream>

int d[maxn]
int G[maxn][maxn];
bool vis[maxn] = {false};

int pre[maxn];
//���·������ 
int num[maxn];
//���������ٵ�Ȩ 
int weight[maxn];
int w[maxn];
//���������ٻ��� 
int cost[maxn];
int c[maxn];

//////////////////ԭ���dij�㷨������һҪ�غ͵ڶ�Ҫ�ع�ͬ�����ж� 
void init() {
	fill(G[0],G[0]+maxn*maxn,inf);
	for(int i=0;i<n;i++){
		pre[i] = i;
		num[i] = 0;
		w[i] = 0 ;
		c[i] = 0 ;
	}
	fill(d,d+maxn,inf);
}
void dij(int s){
	fill(d,d+maxn,inf);
	d[s] = 0;
	w[s] = weight[s];
	c[s] = 0;
	num[s] = 1;
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j= 0;j<n;j++){
			if(vis[j]== false  && min > d[j]) {
				min = d[j];
				u = j;
			}
		} 
		if(u == -1) return;
		//////ֻ����һ���ط�����������visԪ�ص�ֵ������������vis������ 
		vis[u] = 1;
		/////////////////////////////////////////////////
		for(int v= 0;v<n;v++){
			if(vis[j]==false && G[u][v] != inf){
				if(d[u] + G[u][v] < d[v]){
					d[v] = G[u][v] + d[u];
					pre[v] = u;
					num[v] = num[u];
					w[v] = w[u] + weight[u][v];
				}
				else if(d[u] + G[u][v] == d[v]){
					if(w[u] + weight[v] > w[v]){
						w[v] = w[u] + weight[u];
					}
					num[v] += num[u];
				}
			}
		}
	}
}
void DFS_traverse(int start ,int end ){
	
	
	if(start == end) {
		printf("%d\n",start);
		return;
	}
	else{
		DFS_Traverse(start,pre[end]) ;
		printf("%d\n",end); 
	} 
}

//////////////////�İ��dij�㷨�����Ⱦ������·��������Ҫ��¼ǰ������� 
vector<int> pre[maxn] ;
void dij(int a){
	fill(d,d+maxn,inf);
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1;
		int MIN = inf;
		for(int j =0;j<n;j++){
			if(vis[j]== false && d[j] < MIN){
				u = j;
				MIN =d[j];
			}
		}
		if( u== -1) return;
		vis[u] = true;
		for(int v =0;v<n;v++){
			if(vis[v]== false && G[u][v] != inf){
				if(G[u][v] + d[u] < d[v])	{
					d[v] = G[u][v] +d[u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(G[u][v] + d[u] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
///////////////////////////֮����ǻָ�һ��ԭ������ѵ�·��
int optvalue;//Ҳ�������ֵ 
vector<int> pre[maxn] ;///pre���飬������������һ���ڽ�������һ����ά���� 
vector<int> path,tempPath;//ȫ�����Ž�͵�ǰ�ľֲ��� 
void DFS(int end) {
	//����ͬ������Ѿ��ݹ鵽��һ������ͼ�Ŀ�ʼV0 
	if(end == start) {
		tempPath.push_back(end);
		int value;
		//�������·����������value 
		if(value > optvalue){
			optvalue = value;
			path = temppath;
		}
		temppath.pop_back();
		//�����յ㣬Ӧ�÷����� 
		return;
	}
	//Ҳ����һ��ķ�֧�����ǲ�·�� 
	else{
		temppath.push_back(end);
		for(int i=0;i<pre[end].size();i++){
			//��ÿһ��·�����еݹ���� 
			DFS(pre[end][i]);
		}
		//������ϵ�ǰ�Ľڵ�ͽ���ǰ�Ľڵ�ɾ���������� 
		temppath.pop_back();
	} 
}
