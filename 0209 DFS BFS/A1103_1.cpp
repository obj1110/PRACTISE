#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> 

using namespace std;
int n,k,p,facmax = 0;

//vec存在index的p次方
//temp存放临时的结果
//ans存放的是最终的结果，输出结果 
vector<int> vec,temp,ans;

void Init(){
	scanf("%d %d %d",&n,&k,&p);
	//
	int index =0;
	int num= pow(index,p);
	while(num <= n){
		vec.push_back(num);
		index++;
		num = pow(index,p);
	}
	//
	temp.resize(k);
	//
//	ans.resize(k);
}

//cts是当前选中的底数的个数
//sum是当前底数的p次方的和
//facsum是当前的底数的和 
//index表示当前访问的是vec[index] 
void DFS(int index,int cts,int sum,int facsum){
	//死胡同不忘了写return
	if(sum == n && cts ==k){
		if(facsum > facmax) {
			facmax = facsum;
			ans = temp; //底数序列同时更新 
		}
		return; 
	}
	//岔路口不忘return，一般都是两种情况 
	else{
		//剪枝 
		if(sum > n || cts > k) return;
		//两种情况 
		if(index >= 1 ){
			temp.push_back(index);
			DFS(index,cts+1,sum+vec[index],facsum+index);
			temp.pop_back();
			DFS(index-1,cts,sum,facsum);
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
