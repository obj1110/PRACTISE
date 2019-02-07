#include<iostream> 
#include<algorithm>
#include<vector> 
#include<cstring> 

using namespace std;
const int inf = 0x7fffffff;

int C[510];
struct Node{
	int v;//���� 
	int w;//Ȩ�� 
	//���캯�� 
	Node(){};
	//���캯�� 
	Node(int a,int b):v(a),w(b){};
};
vector<Node> adj[510];

//��PMBC����涨��վ�����·��
//���·����ѡ���ͳ����ٵ��Ǹ�
//pmbc�Լ�û������

int main(){
	int Cmax; //ż�� ,��վ������� 
	int N; //��1��ʼ�������Ǵ�0��ʼ ,��վ�ĸ��� 
	int M;//��·�ĸ���
	int S; //���⳵վ����ţ�Ҳ�����յ� 
	scanf("%d%d%d%d",&Cmax,&S,&N,&M);
	//���ð�PMBC����0�����洢 

	memset(C,-1,sizeof(C));
	
	//��ǰ��վ����Ŀ 
	for(int i=0;i<N;i++) {
		scanf("%d",&C[i]);
	}
	//
	 
	//��·�����
	int a,b,c;
	for(int i=0;i<M;i++) {
		//v��Ŀ�궥�㣬w��Ȩ�� 
		scanf("%d%d%d",&a,&b,&c);
		adj[a].push_back(Node(b,c));
		adj[b].push_back(Node(a,c));
	}
	//
	 
	//
	for(int i =0;i <= N;i++){
		for(int j =0;j<adj[i].size();j++){
			cout<<adj[i][j].v<<" "<<adj[i][j].w<<endl;	
		}
		cout<<endl;
	}
}
