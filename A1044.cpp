#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn  = 100100;
int sum[maxn];

//����ҿ����� 
int upper_bound(int L,int R,int x){
	int left = L;
	int right = R;
	while(left<right){
		mid = (left + right)/2;
		if(sum[mid] > x) right = mid;
		else left = mid + 1;
	}
	return left;
}
//����key��Ԫ����ʵ��һ�����䣬��Ҫ���ľ��Ƿ�����������е�һ��ֵ��Ҳ�����½� 
int main(){
	memset(sum,sum+maxn,0);
	
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%d",&sum[0]);
	
	for(int i=1;i<n;i++){
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	
	for(int i=1 ; i<=n ; i++){
		int j = upper_bound(i , n , sum[i-1] +S ); 
	} 
	
	
	return 0;
}
