#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<utility>
#include<cstring>
#include<queue> 

using namespace std;

const int maxn = 1010;

struct Node{
	int w;
	int r;
}node[maxn];

int main(){
	int np,ng;
	cin>>np>>ng;
	
//	vector<int> seq;//��ʼ����˳�� 

	vector<int> group; // �������  
	vector<int> level; // �������� 
	
	for(int i=0;i<np;i++){
		scanf("%d",&node[i].w);
	}
	for(int i=0;i<np;i++){
		int temp;
		scanf("%d",&temp);
//		seq.push_back(temp);
		temp = temp/ng;
		//���� 
		group.push_back(temp);
		//��Ҷ��μ��˵�һ�εı��� 
		level.push_back(0);
	}
	//ͳ�Ʊ�������ĸ��� 
	int cts = np;
	while(cts > 1){
		int game_time;
		//ͳ�Ʊ�������  
		if(cts%ng==0) {
			game_time = cts/ng; 
		}
		else if(cts%ng != 0){
			game_time = cts/ng+1;
		} 
		//���б��� 
		for(int i=0;i<)	
	
	}
	return 0;
}
//һ���ǳ���ƽ�֣������������˵�ƽ�������ô�������⡣
 
