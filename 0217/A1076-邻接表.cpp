#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 1010;

//��׼���ڽӱ������������int���͵Ļ���˵��vector<int>���͵�
//Ȼ�󣬾ͻ��� 
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
		//�൱���Ǳ����ڽӱ��е����еĵ� 
		for(int i =0;i<Adj[topNode.id].size();i++){
			Node next =  Adj[topNode.id][i];
			next.layer = topNode.layer+1;
		}
	}
}

int main(){
	
}
