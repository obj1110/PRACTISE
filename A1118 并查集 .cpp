//���鼯 
#include<iostream> 
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
const int maxn = 10010; 
const int inf = 10010; 
int n,k,q,t,a,b;
set<int> birds;
set<int> trees[maxn];
set<int> temp;
set<int> ftrees[maxn];
//��һ����Ƭ�г��ֵ�������ͬһ����
//������ɭ������������Ŀ + �����������ֻ�������ǲ�������ͬһ����

void init(){
	scanf("%d",&n);
	//n����Ƭ��Ŀ 
	for(int i=0;i<n;i++){
		//k��Ҫ����ĸ��� 
		scanf("%d",&k);
		bool isexist = true;
		for(int j=0;j<k;j++){
			//�������������Ƭ�г��ֵ������Ŷ�����ʲô 
			scanf("%d",&t);
			trees[i].insert(t);
			birds.insert(t);
		}
	}
	int count = 0;
	// set�ļ�飬�����ӷ��ͼ���֮�� 
	for(int i=0 ; i<n ; i++) {
		for(int j=i+1 ; j<n ; j++){
			bool isOne = false;
			//��ʼ�оټ���1�е�Ԫ���ǲ����ڼ���2�г�����
			for(auto ite = set[i].begin();ite != set[i].end();ite++) {
				//��һ���������û�ҵ� 
				if(set[j].find(*ite) == set[j].end()){
					continue;
					//������һ��Ԫ�صıȽ� 
				}
				//�ڶ�����������ҵ��� 
				else{
					isOne = true;
					break;
				}
			}
			//�������ϵĺϲ� 
			if(isOne == true){
				
			}
			//��Ҫֹͣ����Ϊi���Ͽ��ܺ�����ļ���Ҳ����һ���� 
		}
		if(!isOne ){
			ftrees[count++] = trees[i];
		}
	} 
};
int main(){
	init();
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&a,&b);
	}
}
