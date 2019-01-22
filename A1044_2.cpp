#include<iostream>
using namespace std;
const int maxn = 1000100;

int sum[maxn];
int n,S,nearS = 0x7fffffff;

//����ҿ�������,��ʵֱ����Algorithm��upper_bound�Ϳ����ˣ� 
int upper_bound(int L,int R,int x){
	int left = L;
	int right = R;
	int mid;
	while(left <right){
		//mid = left +(right - left)/2;Ҳ�ǿ��Եİ��� 
		mid = (left + right)/2;
		//�����Ҫȥ���ұߵ�����	
		if(sum[mid]>x){
			right = mid; 
		}
		//�����Ҫȥ����ߵ����� 
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
		//����ҿ���upper����bound 
		//Ѱ��sum[j] - sum[i-1] >S�ĵ�һ��Ԫ�� 
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
