#include<cstdlib>
#include<vector>
#include<iostream>
using namespace std;

//v��ʾ����վ��վ֮��Ĺ�ϵ����line��ʾ����վ��վ֮�����·����һ�� 

//v[u]��ʾ��u�����ӵ����еĳ�վ�������Ϊ��ֹһ�������ö�ά���� 
vector<vector<int> >v(10000);

//һ��DIJֱ�ӵ�λ��Ȼ��line��ʾ����������վ֮�����·
//visit������dij�㷨�����ݽṹ 
int line[10000][10000],visit[10000];
vector<int> path,temppath;
//����·�ߣ����㻻�˵Ĵ��� 
int tsfcnt(vector<int> a){  
	int cnt = -1;
	int preLine = 0;
	for(int i=1;i<a.size();i++){
		//����a�м�¼���㾭������·����һ��
		//Ȼ�������ǰ����·����һ�ε���·�ǲ�һ���Ļ���˵���㻻���� 
		if(line[a[i-1]][a[i]] != preLine) cnt++;
		preLine = line[a[i-1]][a[i]] ;
	}
	return cnt;
}
//mincnt���������С�ľ���վ��
//mintransfer���������С�Ļ��˴��� 
//cnt��ʾ���Ǿ����ĳ�վ��Ŀ 
void dfs(int node,int end,int cnt,int&mincnt,int&mintsf) {
	//��������ͬ�����յ��ˣ��и��̵�·���ˣ�·����ͬ���˸����� 
	if(node==end && (cnt < mincnt) || (cnt ==mincnt && tsfcnt(temppath) <mintsf)){
		mincnt = cnt;
		mintsf = tsfcnt(temppath);
		path = temppath;
	}
	//????? 
	if(node == end) return;
	//��·�ڵ�������������½��б�����ע��Ը�node������ÿһ����վ����DFS��ע������ı仯 
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
	//�������һ�Բ�ѯ��ϵ 
	scanf("%d",&k);
	for(int i=0 ; i<k ; i++) {
		//a����ʼ��վ��b���յ㳵վ 
		scanf("%d%d",&a,&b);
		int mincnt = 99999;
		int mintsf = 99999;
		temppath.clear();
		temppath.push_back(a);
		visit[a] = 1;
		dfs(a,b,0,mincnt,mintsf);
		///?????? 
		visit[a] = 0;
		//���濪ʼ��ӡ 
		printf("%d\n",mincnt);
		int preline = 0;
		int pretsf = a;
		for(int j = 1;j<path.size();j++){
			//��·�����б���
			//���˵��������·�ı仯˵���Ƿ����˻��߲��� 
			if(line[path[j-1]][path[j]] != preline){
				if(preline != 0 ) printf("Take Line#%d from %04d to %04d.\n", preline, pretsf, path[j-1]);
				preline = line[path[j-1]][path[j]];
				pretsf = path[j-1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preline, pretsf, b);
	}
}
