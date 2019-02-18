#include<iostream> 
#include<queue>
#include<vector>
#include <algorithm>

using namespace std;
int n,l,m,k;

struct node{
	int id,layer;
};

//采用的是邻接表，是最方便的。 
vector<Node> Adj[MAXV];
bool inq[MAXV] = {false};

int BFS(int s,int L){
	int numForward = 0;
	queue<Node> q;
	Node start;
	start.id  = s ;
	start.layer = 0 ;
	q.push(start);
	inq[start.id] = true;
	while(!q.empty()){
		Node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for(int i=0;i<Adj[u].size();i++){
			Node next = Adj[u][i];
			next.layer = topLayer.layer +1;
			if(inq[next.id] == false && next.layer <=L){
				q.push(next);
				inq[next.id] = true;
				numForward++;
			}
		}
	}
	return numForward;
}

int main(){
	Node user;
	int n,L,numFollow,idFollow;
	scanf();
	return 0;
}		
