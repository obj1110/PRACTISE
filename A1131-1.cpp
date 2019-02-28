#include<cstdlib>
#include<vector>
#include<iostream>
using namespace std;

//v表示的是站和站之间的关系，而line表示的是站和站之间的线路是哪一个 

//v[u]表示和u相连接的所有的车站情况，因为不止一个所以用二维数组 
vector<vector<int> >v(10000);

//一次DIJ直接到位，然后line表示的是相邻两站之间的线路
//visit是用于dij算法的数据结构 
int line[10000][10000],visit[10000];
vector<int> path,temppath;
//根据路线，计算换乘的次数 
int tsfcnt(vector<int> a){  
	int cnt = -1;
	int preLine = 0;
	for(int i=1;i<a.size();i++){
		//就是a中记录了你经过的线路是那一条
		//然后如果当前的线路和上一次的线路是不一样的话就说明你换线了 
		if(line[a[i-1]][a[i]] != preLine) cnt++;
		preLine = line[a[i-1]][a[i]] ;
	}
	return cnt;
}
//mincnt代表的是最小的经过站数
//mintransfer代表的是最小的换乘次数 
//cnt表示的是经过的车站数目 
void dfs(int node,int end,int cnt,int&mincnt,int&mintsf) {
	//三大死胡同，到终点了，有更短的路径了，路径相同换乘更少了 
	if(node==end && (cnt < mincnt) || (cnt ==mincnt && tsfcnt(temppath) <mintsf)){
		mincnt = cnt;
		mintsf = tsfcnt(temppath);
		path = temppath;
	}
	//????? 
	if(node == end) return;
	//岔路口的情况，继续向下进行遍历，注意对跟node相连的每一个车站进行DFS，注意参数的变化 
	for(int i=0;i<v[node].size();i++){
		if(visit[v[node][i]] == 0){
			visit[v[node][i]] = 1;
			temppath.push_back(v[node][i]);
			dfs(v[node][i],end,cnt+1,mincnt,mintsf);
			visit[v[node][i]] = 0;
			temppath.pop_back();
		}
	}
}

int main() {
	int n,m,k,pre,temp,a,b;
	scanf("%d",&n);
	for(int cur_line=1 ; cur_line<= n ; cur_line++){
		scanf("%d%d",&m,&pre);
		for(int j=1;j<m;j++){
			scanf("%d",&temp);
			v[pre].push_back(temp);
			v[temp].push_back(pre);
			line[temp][pre] = line[pre][temp] = cur_line;
			pre = temp;
		}
	}
	//输入的是一对查询关系 
	scanf("%d",&k);
	for(int i=0 ; i<k ; i++) {
		//a是起始车站，b是终点车站 
		scanf("%d%d",&a,&b);
		int mincnt = 99999;
		int mintsf = 99999;
		temppath.clear();
		temppath.push_back(a);
		visit[a] = 1;
		dfs(a,b,0,mincnt,mintsf);
		///?????? 
		visit[a] = 0;
		//下面开始打印 
		printf("%d\n",mincnt);
		int preline = 0;
		int pretsf = a;
		for(int j = 1;j<path.size();j++){
			//对路径进行遍历
			//如果说发生了线路的变化说明是发生了换线操作 
			if(line[path[j-1]][path[j]] != preline){
				if(preline != 0 ) printf("Take Line#%d from %04d to %04d.\n", preline, pretsf, path[j-1]);
				preline = line[path[j-1]][path[j]];
				pretsf = path[j-1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preline, pretsf, b);
	}
}
