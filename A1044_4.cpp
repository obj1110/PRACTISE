#include<iostream> 
#include<algorithm> 
using namespace std;
const int maxn = 1001000;

int sum[maxn];
int n,S,nearS = 0x7fffffff;

//不自定义upper_bound，而是用县城的upper_hound 
int main(){
	scanf("%d%d",&n,&S);
	sum[0] = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	for(int i=1;i<=n;i++){
		int j  = upper_bound(sum+i,sum+n+1,sum[i-1]+S)-sum;
		if(sum[j-1] - sum[i-1] == S) {
			nearS = S;
			break;
		}
		else if(j <= n && sum[j] - sum[i-1] <nearS){
			nearS = sum[j] - sum[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		int j = upper_bound(sum+i,sum+n+1,sum[i-1] + nearS)-sum;
		if(sum[j-1] - sum[i-1] == nearS){
			printf("%d-%d\n",i,j-1);
		}
	}
}
