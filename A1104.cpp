#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
	int n;
	float ans =0.0;
	float sum[n+1];
	scanf("%d",&n);
	sum[0] =0.0;
	for(int i=1;i<=n;i++){
		//首先统计进来当前的数字 
		cin>>sum[i];
		//然后加上之前的元素的值 
		sum[i] += sum[i-1];
	}
//	sum[n] 表示n之前不包括n的所有的元素的和 
	
	int left;
	int right;
	for(left = 1;left < n;left++){
		for(right = n;right>left;right--){
			//right减去left 
			ans += (sum[right] - sum[left]);
		}
	}
	
	printf("%0.2f",ans);
	return 0;
}
