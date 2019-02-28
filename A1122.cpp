#include<iostream> 
#include<vector>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
const int maxn = 210;
const int inf = 0x3ffffff;
int G[maxn][maxn];
vector<int> path;
//注意顶点从1开始，到N结束 

bool check(vector<int> vc){
	//cut
	if(vc.front() != vc.back()){
		return false;
	}
	bool flag = true;
	int size = vc.size();
	for(int i=0;i<size-1;i++){
		int cur = i;
		int next = i+1;
		if(G[cur][next] == 1){
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}

int main(){
	fill(G[0],G[0]+maxn*maxn,inf);
	int n,m,a,b,k,t,temp;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		G[a][b] =G[b][a] = 1;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		path.clear();
		scanf("%d",&t);
		for(int j=0;j<t;j++){
			scanf("%d",&temp);
			path.push_back(temp);
		}
		//进行判断操作 
		if(check(path)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
