#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n,m;
	int coin[n];
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d",&coin[i]);		
//		cout<<"here"<<endl;
	}
	sort(coin,coin+n);

	for(int left =0;left <n;left++){
		//右界 
		int right = lower_bound(coin,coin+n,m-coin[left]) - coin;
		//一种是没找到，一种是找的不对 
		if(right == n) continue;
		else if(coin[left] + coin[right] > m) continue;
		else if(right== left) {
			if(right<n-1 && coin[right+1] + coin[left] == m){
				printf("%d %d",coin[left],coin[right+1]);
				return 0;	
			} 
			else continue;
		}
		else if( coin[right] + coin[left] == m ){
			printf("%d %d",coin[left],coin[right]);
			return 0;
		}
	} 
	//到底出了什么问题了？ 
	printf("No solution");
	return 0; 
} 
