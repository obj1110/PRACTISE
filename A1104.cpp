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
		//����ͳ�ƽ�����ǰ������ 
		cin>>sum[i];
		//Ȼ�����֮ǰ��Ԫ�ص�ֵ 
		sum[i] += sum[i-1];
	}
//	sum[n] ��ʾn֮ǰ������n�����е�Ԫ�صĺ� 
	
	int left;
	int right;
	for(left = 1;left < n;left++){
		for(right = n;right>left;right--){
			//right��ȥleft 
			ans += (sum[right] - sum[left]);
		}
	}
	
	printf("%0.2f",ans);
	return 0;
}
