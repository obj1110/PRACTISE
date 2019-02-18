#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 1010;

//标准的邻接表的数据类型是int类型的或者说是vector<int>类型的
//然后，就会是 
struct Node{
	int id;
	int layer;
};

vector<Node> Adj[maxn];
bool inq[maxn] = {false};

int BFS(int s,int L){
	int numF = 0 ;
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0 ;
	q.push(start);
	inq[start.id] = true;
	while(!q.empty()){
		Node topNode = q.front();
		q.pop();
		//相当于是遍历邻接表中的所有的点 
		for(int i =0;i<Adj[topNode.id].size();i++){
			Node next =  Adj[topNode.id][i];
			next.layer = topNode.layer+1;
		}
	}
}

int main(){
	
}
