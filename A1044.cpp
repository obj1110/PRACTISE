#include<iostream>
#include<algorithm>
#include<cstring> 

using namespace std;

const int maxn = 100100;
int sum[maxn];
 
int upper_bound(int left,int right,int key){
	int l = left;
	int r = right;
	while(l<r){
		int mid = l + (r-l)/2;
		if(sum[mid] > key) r= mid;
		else l =  mid + 1; 
	}
	return left;
}

int main(){
	//n是元素的数目，s是价格，mins是最小的价格。 
	int n,s,mins=0xffffff;
	scanf("%d %d",&n,&s);
	scanf("%d",&sum[0]);	
	for(int i=1;i<n;i++){
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	for(int left = 0;left<n;left++){
		int right = upper_bound(left,n,sum[left]+s);
		if(sum[right+1] - sum[left] ==s){
			mins = s; 
			break;	
		} 
		else if(right <n && sum[right] - sum[left] < mins){
			mins = sum[right+1] - sum[left];
		}
	}
	
	cout<<"mins:"<<mins<<endl;
	
	for(int left = 0;left<n;left++){
		int right = upper_bound(left,n,sum[left]+mins);
		if(sum[right] - sum[left] == mins){
			printf("%d-%d\n",left,right);
		}
	} 
	return 0;
} 



