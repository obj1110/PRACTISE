#include<iostream> 
#include<algorithm>
#include<vector>
#include<set> 
using namespace std;
const int maxn = 10010;
int n,k,b,id,temp;
//ע���Ŵ�1��ʼ��
int father[maxn] ={0};
int isRoot[maxn] ={0};
//int course[maxn] ={0};
set<int> birds; 
int exist[maxn] = {0};

//������ǲ�ͬ�İ���
int findFather(int x) {
	if(x == father[x]){
		return x;
	}
	int ax = findFather(father[x]);
	father[x] = ax;
	return ax;
}
void union_func(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb){
		//ֻ����һ�����У���Ҫ�������У���Ϊһ����Ⱥ�в��������������� 
		father[fa] = fb;
//		father[fa] = fa;
	}
}
void init(){
	scanf("%d",&n);
	//nֻ�������������������δ֪ 
	for(int i=1;i<=maxn;i++) {
		father[i] = i;
	}
//	for(int i=1;i<=n;i++){
//		scanf("%d",&k);
//		for(int j=0;j<k;j++){
//			scanf("%d",&b);
//			birds.insert(b);
//			if(course[b]==0){
//				course[b] = i;
//			}
//			union_func(i,findFather(course[b]));
//		} A1107
	for(int i=0;i<n;i++){
		scanf("%d%d",&k,&id);
		birds.insert(id);
		exist[id] =1;
		for(int j=1 ;j<k;j++){
			scanf("%d",&temp);
			birds.insert(temp);
			exist[temp] = 1;
			union_func(id,temp);
		}
		//A1118
	}
}

int main(){
	init();
	//��ӡ���ĸ���	 && ��ӡ��ĸ���
	//ע�⣬�����Ƕ����е������еĲ��� 
	for(int i=1;i<=maxn;i++){
		//������ı�Ž��б���  
		if(exist[i] == 1){
			isRoot[findFather(i)]++;
		}
	}
	//��Ⱥ����Ŀ��ͨ���ж�����ĸ��� ��������Ⱥ�ĸ���
	//ͬʱͨ��isRoot�����ж�ÿһ����Ⱥ�е���ĸ��������Ƕ��� 
	int numTrees = 0; 
	for(int i=1;i<=maxn;i++){
		//���������Ǵ��ڵģ������������� 
		if(isRoot[i] != 0 && exist[i] == 1) numTrees++;
	}
	printf("%d %d\n",numTrees,birds.size());
	//��ѯ 
	int q,ta,tb;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&ta,&tb);
		(findFather(ta) == findFather(tb))?printf("Yes\n"):printf("No\n");
	}
}
