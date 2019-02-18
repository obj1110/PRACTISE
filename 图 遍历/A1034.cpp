#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;
const int maxn = 2010;
const int inf = 0xffffff;

map<int,string> int2str;
map<string,int> str2int; 
map<string,int> ans; 

int n,k,a;
string str1,str2;
int weight[maxn] ={0};
bool vis[maxn] = {false};

int idNumber = 1;
int stoifunc(string s){
	//���û�н����������ֵ��ϵ 
	if(str2int[s] ==0)	{
		str2int[s] = idNumber;
		idNumber++;
		return idNumber-1;
	}
	//���������һ�Լ�ֵ��ϵ 
	else{
		return str2int[s];
	}
}

//������ǰ��ͼ������ѡ����ߵ�Ȩ�أ���������Ȩ�� 
void dfs(int u,int &head,int& numMember,int& totalWeight){
	vis[u]  = true;
	numMember++; 
	// 
	if(weight[u] > weight[head]) head = u;
	// 
	for(int v =1;v<idNumber;v++){
		//��ѡ���� �Ƿ������ 
		if(G[u][v] >0 ){
			totalweight += G[u][v];
			//��仰��Ŀ�ľ���Ϊ�˷�ֹ��������ͼ���ظ�����
			//��ʵ���û����仰��Ҫ��������ж��м����Ƿ������ 
			G[u][v] = G[v][u] = 0;
			if(vis[v] == false){
				dfs(v,head,numMember,totalweight);
			}
		}
	}
} 

//ʵ���ϵĲ�����ͼ 
void dfst(){
	//idNumber����ͼ�еĽڵ�����+1 
	//��1��ʼ 
	for(int i=1;i<idNumber;i++)	{
		if(vis[i] == false) {
			//��ÿһ���㣬������ͷĿ���б��� 
			int head = i;
			int numMember = 0;
			int totalWeight = 0;
			dfs(i,head,numMember,totalWeight) ;
			//�жϽ���ǲ���Ҫ������� 
			if(numMember>2 && totalweight > k){
				ans[int2str[head]] = numMember;
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		//��ʵ������������  
		cin>>str1>>str2>>a;
		getchar();
		int id1 = str2int(str1);
		int id2 = str2int(str2);
		int2str[id1] = str1;
		int2str[id2] = str2;
		G[id1][id2] = a;
		G[id2][id1] = a;
		//Ҳ���ǽ�����ֵ��ϵ 
		weight[id1] += a;
		weight[id2] += a;
		//һ���ǵ��Ȩ�أ�һ���Ǳߵ�Ȩ�� 
	}
	//��ʱ���Ѿ���һ��ͼ��������Ȩ�غͱߵ�Ȩ����
	//������ͨ���������������ͨ�����еı�Ȩ֮�� 
	dfst();
	cout<<ans.size();
	//����������������������Ŀ��ͷĿ������ 
	for(auto it = ans.begin();it!=ans.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
