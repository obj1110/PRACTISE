#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,m,l,k;
struct node{
	int id;
	int layer;
};
vector<vector<int> >v;
int BFS(node tnode) {
	bool inq[maxn] = {false };
	queue<node> q;
	q.push(tnode);
	//
	inq[tnode.id] = true;
	//计数变量  
	int cnt = 0;
	while(!q.empty())){
		node top = q.front();
		q.pop();
		int topid = top.id;
		for(int i=0;i<v[topid].size();i++){
			int nextid = v[topid][i];
			if(inq[nextid] == false && top.layer  < l){
				node next;
				next.id = nextid;
				next.layer = top.layer + 1;
				q.push(next);
				inq[next.id] = true;
				cnt++;			
			}
		}
	}
	return cnt;
}
int main() {
    scanf("%d %d", &n, &l);
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            //相当于是一种邻接表的感觉 
            v[temp].push_back(i);
        }
    }
    scanf("%d", &k);
    int tid;
    for(int i = 0; i < k; i++) {
        scanf("%d", &tid);
        //注意这个top id 初始话的方式  
        node tnode;
        tnode.id = tid;
        tnode.layer = 0;
        // ans也是一种方式之一 
        int ans = bfs(tnode);
        printf("%d\n", ans);
    }
    return 0;
}
