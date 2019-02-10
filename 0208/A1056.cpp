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
	
//	vector<int> seq;//初始比赛顺序 

	vector<int> group; // 分组次数  
	vector<int> level; // 参赛次数 
	
	for(int i=0;i<np;i++){
		scanf("%d",&node[i].w);
	}
	for(int i=0;i<np;i++){
		int temp;
		scanf("%d",&temp);
//		seq.push_back(temp);
		temp = temp/ng;
		//分组 
		group.push_back(temp);
		//大家都参加了第一次的比赛 
		level.push_back(0);
	}
	//统计比赛老鼠的个数 
	int cts = np;
	while(cts > 1){
		int game_time;
		//统计比赛次数  
		if(cts%ng==0) {
			game_time = cts/ng; 
		}
		else if(cts%ng != 0){
			game_time = cts/ng+1;
		} 
		//进行比赛 
		for(int i=0;i<)	
	
	}
	return 0;
}
//一个是出现平局，哪怕是两个人的平局你该怎么做的问题。
 
