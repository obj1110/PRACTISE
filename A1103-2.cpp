#include<iostream>
#include<vector> 
#include<algorithm>
#include<cmath>

using namespace std;

int n,p,k,facmax = 0;
vector<int> vec,ans,temp;

void Init(){
	scanf("%d %d %d",&n,&k,&p);
	
	int index  =0;
	int number = pow(index,p);
	while(number <= n){
		vec.push_back(number);
		index++;
		number = pow(index,p);
	}
	//temp�Ĵ�С����ν������ans�Ĵ�С������k 
//	temp.resize(k);
//	ans.resize(k);
	
}

//��ǰԪ�صĺ�
//��ǰԪ�ص�p�η��ĺ� 
//��ǰԪ�صĸ���
//��ǰԪ�ص���� 
void DFS(int index,int cts,int facsum,int sum) {
	//����ͬ mk1 
	if(sum ==n && cts == k){
		if(facsum > facmax){
			facmax = facsum;
			ans = temp;
		}
		return;
	}
	//��·�� 
	else{
		//����ͬ mk2
		if(sum > n || cts>k){
			return;
		}
		if(index>= 1) {
			temp.push_back(index);
			DFS(index, cts+1 , facsum+index , sum + vec[index]);
			temp.pop_back();
			DFS(index-1,cts,facsum,sum);			
		}
	}
}

int main(){
	Init();
	
	DFS(vec.size()-1,0,0,0);
	if(facmax ==0){
		printf("Impossible\n");
		return 0;
	}
	else{
		printf("%d = ",n);
		int count = ans.size();
		for(int i=0;i<count;i++){
			if(ans[i] == 0) continue;
			printf("%d^%d",ans[i],p);
			if(i != count-1){
				printf(" + ");
			}
		}
	}
	return 0;
}
