#include<iostream>
using namespace std;
const int maxn = 1000100;

int sum[maxn];
int n,S,nearS = 0x7fffffff;

//左闭右开的区间,其实直接用Algorithm的upper_bound就可以了， 
int upper_bound(int L,int R,int x){
	int left = L;
	int right = R;
	int mid;
	while(left <right){
		//mid = left +(right - left)/2;也是可以的啊。 
		mid = (left + right)/2;
		//如果需要去找右边的区间	
		if(sum[mid]>x){
			right = mid; 
		}
		//如果需要去找左边的区间 
		else {
			left = mid + 1;
		} 
	}
	return left;
}

int main(){
	scanf("%d%d",&n,&S);
	sum[0] = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	
	for(int i=1;i<=n;i++){
		//左闭右开的upper——bound 
		//寻找sum[j] - sum[i-1] >S的第一个元素 
		int j = upper_bound(i,n+1,sum[i-1]+S);
		if(sum[j-1] - sum[i-1] == S) {
			nearS = S;
			break;
		}
		else if(j <= n && sum[j] - sum[i-1] <nearS){
			nearS = sum[j] - sum[i-1];
		}
	}
//	cout<<"nearS:"<<nearS<<endl;
	
	for(int i=1;i<=n;i++){
		int j = upper_bound(i,n+1,sum[i-1] + nearS);
		if(sum[j-1] - sum[i-1] == nearS){
			printf("%d-%d\n",i,j-1);
		}
	}
	return 0;
}
