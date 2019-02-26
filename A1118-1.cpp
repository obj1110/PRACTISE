#include<iostream> 
#include<algorithm>
#include<vector>
#include<set> 
using namespace std;
const int maxn = 10010;
int n,k,b;
//ע���Ŵ�1��ʼ��
int father[maxn];
int isRoot[maxn] ={0};
int course[maxn] ={0};
set<int> birds; 
//�������ı�ţ�������ǲ�ͬ�İ���
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
	for(int i=1;i<=n;i++) {
		father[i] = i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&b);
			birds.insert(b);
			if(course[b]==0){
				course[b] = i;
			}
			union_func(i,findFather(course[b]));
		}
	}
}

int main(){
	init();
	//��ӡ���ĸ���	 && ��ӡ��ĸ���
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(isRoot[i] != 0) ans++;
	}
	printf("%d %d\n",ans,birds.size());
	//��ѯ 
	int q,ta,tb;
	scanf("%d",&q);
	int cts =0;
	for(int i=0;i<q;i++){
		scanf("%d %d",&ta,&tb);
		if(findFather(ta) == findFather(tb)){
			printf("Yes");
		}
		else{
			printf("No");
		}
		cts++;
		if(cts != q){
			printf("\n");
		}
	}
}
