#include<iostream>
#include<vector> 
using namespace std;
 
int main(){
	const int SIZE = 520;
	const int inf = 0xFF; 
	int N,M,C1,C2,a,b,c,d;
	//数据的输入 
	scanf("%d %d %d %d",&N,&M,&C1,&C2);
	int vertex[SIZE];
	int edge[SIZE][3];
	int vis[SIZE];
	for(int i=0;i<N;i++){
		scanf("%d",&a);
		vertex[i] = a;
		}
	for(int j=0;i<M;j++) {
		scanf("%d %d %d",&a,&b,&c);
		edge[a][b] = edge[b][a] = c;
	}
	for(int i=0;i<SIZE;i++){
		vis[i] = 0;
	}
	
	return 0;
}
