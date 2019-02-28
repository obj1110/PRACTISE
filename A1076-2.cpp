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

//s���ڽӱ��е�һ���ڵ� 
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
			//���������ܹ��ﵽ�Ľڵ� 
			Node next = Adj[topNode][i];
			next.layer = topNode.layer + 1;
			//������������ܹ�����ģ�������û�б���������
			//����Ҫ���Ƿ��ϲ����ķ�Χ�ģ��Ϳ�����ΪForward��Ԫ�ؽ��м��� 
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
