#include<iostream>
#include<vector> 
#include<algorithm>
#include<cmath>

using namespace std;

int n,p,k,facmax = 0;
vector<int> vec,ans,temp;

void Init(){
	scanf("%d %d %d",&n,&k,&p);
	
	int index  =0;
	int number = pow(index,p);
	while(number <= n){
		vec.push_back(number);
		index++;
		number = pow(index,p);
	}
	//temp的大小无所谓，但是ans的大小必须是k 
//	temp.resize(k);
//	ans.resize(k);
	
}

//当前元素的和
//当前元素的p次方的和 
//当前元素的个数
//当前元素的情况 
void DFS(int index,int cts,int facsum,int sum) {
	//死胡同 mk1 
	if(sum ==n && cts == k){
		if(facsum > facmax){
			facmax = facsum;
			ans = temp;
		}
		return;
	}
	//岔路口 
	else{
		//死胡同 mk2
		if(sum > n || cts>k){
			return;
		}
		if(index>= 1) {
			temp.push_back(index);
			DFS(index, cts+1 , facsum+index , sum + vec[index]);
			temp.pop_back();
			DFS(index-1,cts,facsum,sum);			
		}
	}
}

int main(){
	Init();
	
	DFS(vec.size()-1,0,0,0);
	if(facmax ==0){
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
