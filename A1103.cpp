//DFS
//��������ѡ��ѡ��ǰԪ�ص����⣬��Ϊ���Ľ�����ܳ�����ͬ��Ԫ��
//����Ӧ�ð��մ�����ֽ�ΪС����ķ��������о���Ҳ���ǵݹ麯�� 

#include<iostream> 
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstdlib> 
#include<cstring>
#include<algorithm> 
#include<vector>
#include<cmath>

using namespace std;

const int maxn = 1000100;
//4�����
//����������������ʾΪK������P�η��ĺͣ�Ȼ����K�������յݼ���˳���������.��K�������Դ�Сһ�� 
//����𰸲�ֹһ������Ҫ����k�ĺͣ����k�ĺ��������
//�����ʹ��k�ĺ�Ҳһ���󣬾�Ҫ����������������
//��������ھ����impossible

//��Ȼ�Ǵ�����ֽ�ΪС���⣬������Ҫʹ��һ�����ݽṹ����ǰ�洢С����Ľ�� 
int n,k,p; 
int k_max = 0; 

//vec��ǰ�洢������Ĵ� 
//temp�洢�����õ���Ԫ��,
//ans�����յ���� 
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
//facsum��������ӵĺ� 
//N�ǵ�ǰ�������е�Ԫ�صĸ��� 
void DFS(int current,int sum,int depth,int facsum) {
	int i;
	if(sum > N) {
		return;
	}
	if(depth==K) {
		
	}
}

int main(){
	Init();
	for(auto it= vec.begin();it!=vec.end();it++){
		cout<<*it<<endl;
	}
	//Ҳ����n�ֽ�Ϊk������p�η��ĺ�
	
	return 0;
}
