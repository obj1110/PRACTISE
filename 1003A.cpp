//���Ľ��һ����Ҫͳ��һ���м����ȳ������·��
//һ����Ҫͳ�����ҵ�����������

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
	//���ȳ���ʹ��Floyd�㷨��ʵ��
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
	printf("���·��Ϊ: %d",edges[C1][C2]);
	//��ʼDijstra�㷨 
	return 0;
}
