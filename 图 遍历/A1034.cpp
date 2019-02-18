#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;
const int maxn = 2010;
const int inf = 0xffffff;

map<int,string> int2str;
map<string,int> str2int; 
map<string,int> ans; 

int n,k,a;
string str1,str2;
int weight[maxn] ={0};
bool vis[maxn] = {false};

int idNumber = 1;
int stoifunc(string s){
	//如果没有建立过这个键值关系 
	if(str2int[s] ==0)	{
		str2int[s] = idNumber;
		idNumber++;
		return idNumber-1;
	}
	//如果存在这一对键值关系 
	else{
		return str2int[s];
	}
}

//遍历当前子图，并且选出最高点权重，并计算总权重 
void dfs(int u,int &head,int& numMember,int& totalWeight){
	vis[u]  = true;
	numMember++; 
	// 
	if(weight[u] > weight[head]) head = u;
	// 
	for(int v =1;v<idNumber;v++){
		//可选的是 是否便利过 
		if(G[u][v] >0 ){
			totalweight += G[u][v];
			//这句话的目的就是为了防止出现无向图的重复计算
			//其实如果没有这句话就要在上面的判断中加上是否便利过 
			G[u][v] = G[v][u] = 0;
			if(vis[v] == false){
				dfs(v,head,numMember,totalweight);
			}
		}
	}
} 

//实际上的参数是图 
void dfst(){
	//idNumber就是图中的节点总数+1 
	//从1开始 
	for(int i=1;i<idNumber;i++)	{
		if(vis[i] == false) {
			//对每一个点，当做是头目进行遍历 
			int head = i;
			int numMember = 0;
			int totalWeight = 0;
			dfs(i,head,numMember,totalWeight) ;
			//判断结果是不是要最终输出 
			if(numMember>2 && totalweight > k){
				ans[int2str[head]] = numMember;
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		//其实就是输入数据  
		cin>>str1>>str2>>a;
		getchar();
		int id1 = str2int(str1);
		int id2 = str2int(str2);
		int2str[id1] = str1;
		int2str[id2] = str2;
		G[id1][id2] = a;
		G[id2][id1] = a;
		//也就是建立键值关系 
		weight[id1] += a;
		weight[id2] += a;
		//一个是点的权重，一个是边的权重 
	}
	//这时候，已经是一个图，包括点权重和边的权重了
	//遍历联通分量，计算这个联通分量中的边权之和 
	dfst();
	cout<<ans.size();
	//最后输出两个东西，帮派数目，头目和人数 
	for(auto it = ans.begin();it!=ans.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
