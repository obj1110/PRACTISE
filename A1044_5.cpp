#include<iostream> 
#include<algorithm> 
#include<cstring>

using namespace std;
const int maxn = 1000100;
const int inf = 0x7fffffff;

int main(){
	int n;
	int S;
	scanf("%d%d",&n,&S);
	for(int i=1;i<=n;i++){
		int j = upper_bound(sum+i,sum+n+1,sum[i-1]+S);
		if(sum[j-1]-sum[i-1] == S){
			nearS = S;
			break;
		}
		else if(j<=n && sum[j]-sum[i-1] <nearS){
			nearS = sum[j] - sum[i-1];
		}
	}
	for(int i=i;i<=n;i++){
		int j = upper_bound(sum+i,sum+n+i,sum[i-1]+nearS) -sum;
		if(sum[j-1] - sum[i-1] == nearS){
			printf("%d-%d\n",i,j-1);
		}
	}
	return 0;
}
