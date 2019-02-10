#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> 

using namespace std;
int n,k,p,facmax = 0;

//vec����index��p�η�
//temp�����ʱ�Ľ��
//ans��ŵ������յĽ���������� 
vector<int> vec,temp,ans;

void Init(){
	scanf("%d %d %d",&n,&k,&p);
	//
	int index =0;
	int num= pow(index,p);
	while(num <= n){
		vec.push_back(num);
		index++;
		num = pow(index,p);
	}
	//
	temp.resize(k);
	//
//	ans.resize(k);
}

//cts�ǵ�ǰѡ�еĵ����ĸ���
//sum�ǵ�ǰ������p�η��ĺ�
//facsum�ǵ�ǰ�ĵ����ĺ� 
//index��ʾ��ǰ���ʵ���vec[index] 
void DFS(int index,int cts,int sum,int facsum){
	//����ͬ������дreturn
	if(sum == n && cts ==k){
		if(facsum > facmax) {
			facmax = facsum;
			ans = temp; //��������ͬʱ���� 
		}
		return; 
	}
	//��·�ڲ���return��һ�㶼��������� 
	else{
		//��֦ 
		if(sum > n || cts > k) return;
		//������� 
		if(index >= 1 ){
			temp.push_back(index);
			DFS(index,cts+1,sum+vec[index],facsum+index);
			temp.pop_back();
			DFS(index-1,cts,sum,facsum);
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
