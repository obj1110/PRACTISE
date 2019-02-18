//有向无环图
//树的高度取决于你选择的树根是哪一个
//本题要输出，树的高度最高的时候对应的树根是哪一个？？？
//这种树根叫做 the deeepest root  
#include<iostream> 
#include<algorithm> 
#include<cstring>
//主要是输出的要求是从小打大 
#include<set>

using namespace std;
const int maxn = 10010;
//本题的顶点从1开始
int v[maxn][maxn];//记录连通性 
//cnt专门是用来计算联通分量的个数的 
int n,a,b,cnt = 0;
bool isTree = false;
//每次更新 
int d[maxn]; //记录当前节点对图进行遍历得到的图每一个节点的深度 
int visit[maxn];//记录当前点的一个深度的情况 
//不更新 
int result[maxn]; //深度记录数组，key是当前节点，value是深度 


void dfs(int index,int depth){
	//当前节点已经被遍历过了 
	visit[index] = 1;
	//对这个点的所有的关系进行遍历
	for(int i=1;i<=n;i++) {
		if( v[index][i]==1 && visit[index] == 0){
			dfs(i,depth+1);
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b); 
		v[a][b] = v[b][a] = 1;
	}
	//
	for(int i=1;i<=n;i++){
		memset(d,-1,maxn);
		memset(visit,0,maxn);
		dfs(i,1);
		//
		int max_depth = 0; 
		for(int j=1;j<=n;j++) {
			if(d[j] == -1){
				isTree = false;
				//单独去计算联通分量的个数 
				cnt = 2;
				printf("Error: %d components",cnt);
				return 0;
			}
			if(d[j] > max_depth){
				max_depth = d[j];
			}
		}
		result[i] = max_depth;
	}
	//
	//	对result数组进行处理
 	for(int i=1;i<=n;i++) {
 		cout<<result[i]<<" ";
	 }
	return 0;
}
//对每一个顶点，开始进行遍历 
//还是很基础的图的递归遍历，只不过强制性使用DFS，因为要同时对深度井赋值 
