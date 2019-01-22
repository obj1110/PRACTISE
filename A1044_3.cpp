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
		//����ҿ�ֱ���� 
		int j = upper_bound(sum+x,sum+n,sum[x]+S)-sum ;
		//����ע�⣬��������ܿ��ܳ���Խ�������һ��Խ�磬������Ǵ��
		//��˵�ľ���upper_bound������� 
		if(j==n){
			continue;
			//���ﲻ��break����Ϊ��ʹһ���ط�������Խ�磬���������һ����Խ�磿���ƺ��� 
		}
		//����upper_bound������������� 
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
			//�������index�����Ǳ�� 
			printf("%d-%d",k,j);
		}
	}
	return 0;
}
