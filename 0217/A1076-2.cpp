#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1010;
struct Node{
	int id;
	int layer;
};
vector<Node> Adj[maxn];
bool inq[maxn] = {false};

//s是邻接表中的一个节点 
int BFS(int s,int l){
	int numForward = 0;
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0; 
	q.push(start);
	inq[start.id] = true;
	while(!q.empty()){
		Node topNode = q.front();
		q.pop();
		for(int i=0;i<Adj[topNode].size();i++){
			//遍历所有能够达到的节点 
			Node next = Adj[topNode][i];
			next.layer = topNode.layer + 1;
			//如果这个点点是能够到达的，并且是没有被遍历过得
			//此外要求是符合层数的范围的，就可以作为Forward的元素进行计算 
			if(inq[next.id] == false && next.layer <= L) {
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
}
