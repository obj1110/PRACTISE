//DFS
//不单纯是选不选当前元素的问题，因为最后的结果可能出现相同的元素
//而是应该按照大问题分解为小问题的方法进行研究，也就是递归函数 

#include<iostream> 
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstdlib> 
#include<cstring>
#include<algorithm> 
#include<vector>
#include<cmath>

using namespace std;

const int maxn = 1000100;
//4大情况
//将给定的正整数表示为K个数的P次方的和，然后这K个数按照递减的顺序进行排列.这K个数可以大小一样 
//如果答案不止一个，就要计算k的和，输出k的和最大的情况
//如果即使是k的和也一样大，就要按照数字序进行输出
//如果不存在就输出impossible

//既然是大问题分解为小问题，就难免要使用一个数据结构来提前存储小问题的结果 
int n,k,p; 
int k_max = 0; 

//vec提前存储子问题的答案 
//temp存储的是用到的元素,
//ans是最终的输出 
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
//facsum是诸多因子的和 
//N是当前的序列中的元素的个数 
void DFS(int current,int sum,int depth,int facsum) {
	int i;
	if(sum > N) {
		return;
	}
	if(depth==K) {
		
	}
}

int main(){
	Init();
	for(auto it= vec.begin();it!=vec.end();it++){
		cout<<*it<<endl;
	}
	//也就是n分解为k个数的p次方的和
	
	return 0;
}
