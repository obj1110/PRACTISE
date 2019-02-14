#include<iostream> 
#include<algorithm>
#include<vector> 
#include<cmath> 

using namespace std;

const int maxn = 100100;
int n,k,child;
double p,r;
vector<int> node[maxn];
int cts[maxn] = {0};

void init(){
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	//注意r是百分之1 
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if( k==0){
			continue;
		}
		else if(k!=0){
			for(int j=0;j<k;j++) {
				scanf("%d",&child);
				node[i].push_back(child);
			}
		}
	}
}

int max_Level = 0;
int min_Level = maxn;
void DFS(int index,int level){
	if(node[index].size() ==0){
		cts[level]++;
		if(max_Level < level){
			max_Level = level;
		}
		if(min_Level > level){
			min_Level = level;
		}
	}
	else{
		for(int i=0;i<node[index].size();i++){
			DFS(node[index][i] , level+1 );
		}
	}
}

int main(){
	init();
	DFS(0,0);
//	cout<<cts[min_Level]<<endl;
	printf("%0.4lf %d\n",p*pow(1+r,min_Level),cts[min_Level]);
}
