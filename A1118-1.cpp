#include<iostream> 
#include<algorithm>
#include<vector>
#include<set> 
using namespace std;
const int maxn = 10010;
int n,k,b;
//注意编号从1开始的
int father[maxn];
int isRoot[maxn] ={0};
int course[maxn] ={0};
set<int> birds; 
//人是树的编号，而鸟就是不同的爱好
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
		//只出现一个就行，不要两个都有，因为一个人群中不可能有两个领袖 
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
	//打印树的个数	 && 打印鸟的个数
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(isRoot[i] != 0) ans++;
	}
	printf("%d %d\n",ans,birds.size());
	//查询 
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
