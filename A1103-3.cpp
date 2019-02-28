#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> vec,temp,ans;
int n,k,p,facmax = 0;
void init(){
	scanf("%d%d%d",&n,&k,&p);
	int index = 0;
	int number = pow(index,p);
	while(number <= n){
		vec.push_back(number);
		index++;
		number = pow(index,p);
	}
}
//������ص� 
void DFS(int index,int cts,int facsum,int sum){
	//�Ե�����ͬ 
	if(cts == k && sum ==n){
		if(facsum > facmax) {
			facmax = facsum;
			ans = temp;
		}
	}
	//���������Ǵӵ�һ��������ģ����Կ϶�������˫�ȵ���� 
	else if(cts >=k || sum >=n){
		return; 
	}
	else{
		if(index >= 1){
			temp.push_back(index);
			DFS(index,cts+1,facsum+index,sum+vec[index]);
			temp.pop_back();
			DFS(index-1,cts,facsum+index,sum+vec[index]);
		}
	}
}

int main(){
	Init();
	//����n Ϊ 169��DFS������13��ʼ����
	//�����ǲ���-1���Լ����� 
	DFS(vec.size()-1,0,0,0);
	//
	if(facmax == 0) {
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
