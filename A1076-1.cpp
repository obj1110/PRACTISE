#include<iostream>
#include<vector> 
#include<cstring> 
#include<queue> 
using namespace std;
struct Node{
	int id;
	int layer;
};
vector<Node> Adj[maxn];
bool inq[maxn] = {false};
//s�ǵ�ǰ�����Ľڵ�ı�� 
//l�ǲ������� 
int BFS(int s,int L){
	int numForward = 0;
	queue<node> q;
	node start;
	start.id = s;
	start.layer = 0 ;
	q.push(start);
	inq[start.id] = false;
	while(!q.empty()){
		Node topNode = q.front();
	}
}
