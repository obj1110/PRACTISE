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
	//��������  
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
            //�൱����һ���ڽӱ�ĸо� 
            v[temp].push_back(i);
        }
    }
    scanf("%d", &k);
    int tid;
    for(int i = 0; i < k; i++) {
        scanf("%d", &tid);
        //ע�����top id ��ʼ���ķ�ʽ  
        node tnode;
        tnode.id = tid;
        tnode.layer = 0;
        // ansҲ��һ�ַ�ʽ֮һ 
        int ans = bfs(tnode);
        printf("%d\n", ans);
    }
    return 0;
}
