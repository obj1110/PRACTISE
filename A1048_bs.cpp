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
		//�ҽ� 
		int right = lower_bound(coin,coin+n,m-coin[left]) - coin;
		//һ����û�ҵ���һ�����ҵĲ��� 
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
	//���׳���ʲô�����ˣ� 
	printf("No solution");
	return 0; 
} 
