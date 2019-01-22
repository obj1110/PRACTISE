#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 1000100;
const int inf = 0x7fffffff;
int sum[maxn];

int main(){
	memset(sum,0,maxn);
	int n,S,nearS=inf;
	scanf("%d %d",&n,&S);
	
	scanf("%d",&sum[0]);
	for(int i=1;i<n;i++){
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	
	for(int x=0;x<n;x++){
		//左闭右开直接用 
		int j = upper_bound(sum+x,sum+n,sum[x]+S)-sum ;
		//但是注意，这个东西很可能出现越界情况，一旦越界，结果就是错的
		//我说的就是upper_bound这个东西 
		if(j==n){
			continue;
			//这里不是break，因为即使一个地方出现了越界，不代表后面一样会越界？？似乎？ 
		}
		//对于upper_bound的特殊情况处理 
		if(sum[j] - sum[x] == S){
			nearS = S;
			break;
		}
		else if(sum[j] - sum[x] <= nearS){
			nearS = sum[j] - sum[x];
		}
	}
	
//	cout<<endl<<"nearS:"<<nearS<<endl;
	
	for(int k=0;k<n;k++){
		int j = upper_bound(sum+k,sum+n,sum[k]+nearS) - sum;
		if(j==n) {
			continue;
		}
		if((sum[j] - sum[k]) == nearS){
			//输出的是index而不是别的 
			printf("%d-%d",k,j);
		}
	}
	return 0;
}
