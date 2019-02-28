#include<iostream> 
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
const int maxn = 1010;
int n,m,k,a,b,c;
int v[maxn][maxn];
int visit[maxn];

//�ر�ע�⣺����ĵ��1��ʼ�������Ǵ�0��ʼ 

//����DFS������ÿһ���������Ľڵ�����Ϊtrue��״̬ 
void DFS(int index) {
	//���Ƚ���ǰ�ĵ�����Ϊ�Ѿ���������״̬ 
	visit[index] = 1;
	for(int i =1;i<=n;i++){
		//�Ե�ǰ��ǰ�ڵ���Ա������ĵ���һ���б��� 
		if(visit[i] == false && v[index][i] ==1){
			DFS(i);
		}
		//����DFS������һ������DFS֮��Ͱ�ԭ�������Ӷϵ�
		//����һ��DFS������������ 
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		v[a][b] = v[b][a] = 1;
	} 
	for(int i = 0 ; i < k ; i++){
		scanf("%d",&c);
		memset(visit , 0 , maxn);
		//����ľ�����ͨ��ͼ����Ŀ��ȥ1
		int cnt = 0;
		//ע�� 
		visit[c] = 1;
		for(int j=1;j<=n;j++) {
			//һ����false������һ���µ���ͨ���� �Ѿ����� 
			if(visit[j] == 0 ){
				DFS(j);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}

