#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 110;

vector<int> node[maxn] ;
int w[maxn]  = {0};
//���ڵ��0��n-1 ,m�Ƿ�Ҷ�ڵ�ĸ�����tw��Ŀ��Ȩ�� 
int n,m,tw;

bool cmp(int a,int  b) {
	return w[a] > w[b];
}

void init(){
	int id,k,num;
	scanf("%d%d%d",&n,&m,&tw);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&id,&k);
		for(int j = 0;j<k;j++){
			scanf("%d",&num);
			node[id].push_back(num);
		}
		//���������Ե�ʣ����ȱ�����Ȩ�صĽڵ㣬����Ҫ��vector���б���
	}
	//��Ԫ�ؽ������� 
	for(int i=0; i<n;i++) {
		//�ر�ע�������д������������ 
		sort(node[i].begin(),node[i].end(),cmp);
	}
}

//����ֻ�����������
//���������һ�������ô�С���������pop
//һ����С���Ǿ�pop
//һ���Ǵ��Ǿ�push 
vector<int> temp; 
void DFS(int index,int remain){
	if(remain==0){
		for(int i=0;i<temp.size();i++){
			cout<<temp[i];
			if(i != temp.size()-1) cout<<" " ;
		}
		cout<<endl;
		temp.pop_back(); 
		return;
	}
	//ʣ��Ķ���������Ľڵ�Ȩ�ػ�С 
	else if(remain < w[index]){
		temp.pop_back();
		return; 
	}
	else if(remain >= w[index]){
		temp.push_back(index);
		remain -= w[index];
		//�Ե�ǰ�ڵ�����е��ӽڵ���б������� 
		for(int j=0;j<node[index].size();j++){
			DFS(node[index][j],remain);
		}
	}
}

int main(){
	init();
//	for(int i=0;i<n;i++){
//		cout<<node[i].size()<<" ";
//		for(int j=0;j<node[i].size();j++){
//			cout<<node[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	//0�Žڵ㣬ʣ��24 
	DFS(0,24);
}
