#include<iostream> 
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

const int inf = 0x3fffffff;
const int maxn = 1010;

int G[maxn][maxn];
bool vis[maxn] = {false};
int n,L,k,query,t;
set<int> st;

void init(){

	scanf("%d %d",&n,&L);
	fill(G[0],G[0]+n*n,0);
	//i��ʾ�����û��ı�ţ����������followers 
	for(int i = 1;i<=n;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&t);
			//��ʾ��i��t����Ϣ�������
			//i��t�����ڣ�ע�����⣡������ 
			G[t][i]  = 1;
		}
	}
}

void DFS_func(int s,int cur_level){
	if(cur_level > L+2){
		return;
	}
	//ֻ�к��ʵĲ���ҲŻ����insert��������� 
	if(cur_level <= L+1){
		st.insert(s);
	} 
	vis[s] == true;
	for(int i=1;i<=n;i++){
		//i��s��һ������ 
		if(vis[i] == false && G[s][i] == 1){
			DFS_func(i,cur_level+1);
//			cout<<"one time"<<endl;
		}
	} 
} 

int main(){
	init();
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&query);
		fill(vis,vis+n,false);
		st.clear();
		DFS_func(query,1); 
		printf("%d\n",st.size()-1);
	}
}
