//最后的结果一个是要统计一共有几条等长的最短路径
//一个是要统计能找到的最多的人手

#include<iostream>
using namespace std;
const int INF = 0xfff;

int main(){
	int N,M,C1,C2,temp,a,b,c;
	int num[N];
	int edges[N][N];
	int path[N][N];
	scanf("%d %d %d %d",&N,&M,&C1,&C2); 
	for(int i=0;i<N;i++){
		scanf("%d",&temp);
		num[i] = temp; 
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			edges[i][j] = edges[j][i] = INF;
			if(i==j){
				edges[i][j] = edges[j][i] = 0;
			}
		}
	}
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&a,&b,&c);
		edges[a][b] = c;
		edges[b][a] = c;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			path[i][j] =-1;
			path[j][i] =-1;
		}
	}
	//首先尝试使用Floyd算法来实现
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if(i==j) continue;
				if(edges[i][k] + edges[k][j] < edges[i][j]){
					edges[i][j] = edges[i][k] + edges[k][j];
					edges[i][j] = edges[j][i];
					path[i][j] = path[j][i]=k; 
				}
			}
		}
	}
	printf("最短路径为: %d",edges[C1][C2]);
	//开始Dijstra算法 
	return 0;
}
