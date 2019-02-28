#include<iostream> 
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
const int maxn = 1010;
int n,m,k,a,b,c;
int v[maxn][maxn];
int visit[maxn];

//特别注意：本题的点从1开始，而不是从0开始 

//整个DFS函数将每一个遍历到的节点设置为true的状态 
void DFS(int index) {
	//首先将当前的点设置为已经被遍历的状态 
	visit[index] = 1;
	for(int i =1;i<=n;i++){
		//对当前当前节点可以遍历到的点逐一进行遍历 
		if(visit[i] == false && v[index][i] ==1){
			DFS(i);
		}
		//两种DFS方法，一种是你DFS之后就把原来的连接断掉
		//另外一种DFS方法，就是你 
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		v[a][b] = v[b][a] = 1;
	} 
	for(int i = 0 ; i < k ; i++){
		scanf("%d",&c);
		memset(visit , 0 , maxn);
		//输出的就是联通子图的数目减去1
		int cnt = 0;
		//注意 
		visit[c] = 1;
		for(int j=1;j<=n;j++) {
			//一旦是false，代表一个新的联通分量 已经出现 
			if(visit[j] == 0 ){
				DFS(j);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}

