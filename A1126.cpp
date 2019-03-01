#include<iostream> 
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

const int inf = 0x3fffffff;
const int maxn = 520;
int n,m,a,b;
//n是点数，m是边数
int G[maxn][maxn];
int indice[maxn] = {0};

void init() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		G[a][b] = G[b][a] = 1;
	}
	fill(indice,indice+maxn,0);
}
//注意点的indce从1开始
void traverse() {
	
	for(int u = 1;u<=n;u++){
		int count = 0;
		for(int v=1;v<=n;v++){
			if(G[u][v] == 1){
				count++;
			}
		}
		indice[u] = count;
	}
}
int main(){
	init();
	traverse();
	int cnt = 0;
	int odd = 0;
//	int zero = 0;
	for(int i=1;i<=n;i++) {
//		if(indice[i]==0){
//			zero++;
//		}
		if(indice[i]%2 == 1){
			odd++;
		}
		cout<<indice[i];
		if(cnt < n-1){
			cout<<" ";
			cnt++;
		}
	}
	cout<<endl;
	if(odd == 2 ){
		cout<<"Semi-Eulerian"<<endl;
	}
	else if(odd == 0){
		cout<<"Eulerian" <<endl;
	}
	else{
		cout<<"Non-Eulerian" <<endl;
	}
	return 0;
}
