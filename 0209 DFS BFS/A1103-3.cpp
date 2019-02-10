#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> vec,temp,ans;
int n,k,p,facmax = 0;
void init(){
	scanf("%d%d%d",&n,&k,&p);
	int index = 0;
	int number = pow(index,p);
	while(number <= n){
		vec.push_back(number);
		index++;
		number = pow(index,p);
	}
}
//这个是重点 
void DFS(int index,int cts,int facsum,int sum){
	//对的死胡同 
	if(cts == k && sum ==n){
		if(facsum > facmax) {
			facmax = facsum;
			ans = temp;
		}
	}
	//由于我们是从第一种情况来的，所以肯定不包括双等的情况 
	else if(cts >=k || sum >=n){
		return; 
	}
	else{
		if(index >= 1){
			temp.push_back(index);
			DFS(index,cts+1,facsum+index,sum+vec[index]);
			temp.pop_back();
			DFS(index-1,cts,facsum+index,sum+vec[index]);
		}
	}
}

int main(){
	Init();
	//对于n 为 169，DFS函数从13开始做起
	//到底是不是-1，自己尝试 
	DFS(vec.size()-1,0,0,0);
	//
	if(facmax == 0) {
		printf("Impossible\n");
		return 0;
	}
	else{
		printf("%d = ",n);
		int count = ans.size();
		for(int i=0;i<count;i++){
			if(ans[i] == 0) continue;
			printf("%d^%d",ans[i],p);
			if(i != count-1){
				printf(" + ");
			}
		}
	}
	return 0;
}
