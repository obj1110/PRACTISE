//�����൱���Ƕ�������ͬ��ͼ��������dij�㷨���������ϴ� 
//���ԣ��Ͱ���DIJ+DFS���б������������ʱ����̵�·����·����̵�·�� 

//����ĳһ���ڵ��ʱ�򣬾����Ľڵ���� �ǿ��Ա����õ���  
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 520;
const int inf = 0x3fffffff;
//n�ǵ�ĸ�����m�ǽֵ��ĸ��� 
int n,m,v1,v2,one_way,length,time,st,des;
int optvaluel= inf,optvaluet= inf ;

int t[maxn][maxn];
int l[maxn][maxn];
int dl[maxn] = {0};
int dt[maxn] = {0};

vector<int> prel[maxn];
vector<int> pret[maxn];
bool visl[maxn] = {false};
bool vist[maxn] = {false};

vector<int> pathl;
vector<int> patht;
vector<int> templ;
vector<int> tempt;

void init(){
	fill(t[0],t[0]+maxn*maxn,inf);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		scanf("%d %d %d %d %d",&v1,&v2,&one_way,&length,&time);
		if(one_way == 1){
			l[v1][v2] = length;
			t[v1][v2] = time;
		}
		else{
			l[v1][v2] = l[v2][v1] = length;
			t[v1][v2] = t[v2][v1] = time;
		}
	}
	scanf("%d%d",&st,&des);
}

void dijl(int s){
	fill(dl,dl+maxn,inf);
	dl[s] =0;
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j=0;j<n;j++){
			if(visl[j]== false &&min > dl[j]){
				min = dl[j];
				u = j ;
			}
		}
		if(u == -1) return ;
		visl[u] = true;
		for(int v= 0;v<n;v++) {
			if(l[u][v] != inf && visl[v] == false){
				if(dl[u] + l[u][v] < dl[v]){
					dl[v] = dl[u] + l[u][v];
					prel[v].clear();
					prel[v].push_back(u);
				}
				else if(dl[i] + l[u][v] == dl[v]){
					prel[v].push_back(u);
				}
			}
		}
	}
}

void dijt(int s){
	fill(dt,dt+maxn,inf);
	dt[s] =0;
	for(int i=0;i<n;i++){
		int u = -1;
		int min = inf;
		for(int j=0;j<n;j++){
			if(vist[j]== false &&min > dt[j]){
				min = dt[j];
				u = j ;
			}
		}
		if(u == -1) return ;
		vist[u] = true;
		for(int v= 0;v<n;v++) {
			if(t[u][v] != inf && vist[v] == false){
				if(dt[u] + t[u][v] < dt[v]){
					dt[v] = dt[u] + t[u][v];
					pret[v].clear();
					pret[v].push_back(u);
				}
				else if(dt[i] + t[u][v] == dt[v]){
					pret[v].push_back(u);
				}
			}
		}
	}
}

void DFSl(int v){
	if(v != st){
		templ.push_back(v);
		int value = 0 ;
		//�������·�� 
		for(int i=0;i < templ.size()-1;i++){
			int id = i;
			int idnext =i+1;
			value += t[id][idnext];
		} 
		//����value
		//����ǰ·�������·����Ƚ�,��ע��Ƚϵ���ʱ�� 
		if(value < optvaluel ){
			optvaluel = value;
			pathl = templ;
		} 
		templ.pop_back();
		return;
	} 
	templ.push_back(v);
	for(int i=0;i<prel[v].size();i++){
		DFSl(prel[v][i]);	
	}
	templ.pop_back();
}

void DFSt(int v){
	if(v != st){
		tempt.push_back(v);
		int value = tempt.size();
		//����value
		//����ǰ·�������·����Ƚϣ���ע��Ƚϵ��ǽڵ�ĸ��� 
		if(value < optvaluet ){
			optvaluet = value;
			patht = tempt;
		} 
		tempt.pop_back();
		return;
	} 
	tempt.push_back(v);
	for(int i=0;i<pret[v].size();i++){
		DFSt(pret[v][i]);	
	}
	tempt.pop_back();
}

void print() {
	for(int i=0;i<pathl.size();i++) {
		cout<<pathl[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<patht.size();i++){
		cout<<patht[i]<<" ";
	}
}

int main() {
	init();
	/////////////////////
	//������֣�������̺�ʱ�����
	//���·����̵Ĳ�Ψһ����������ģ�---1 
	//�������Ҳ��Ψһ������������ڵ������ٵ� ---2 
	//�������·����ʱ��·����һ���ϵģ����������� ---1,2 
	dijl(st);
	dijt(st);
	DFSl(des);
	DFSt(des);
	print();
	return 0;
}
