#include<iostream> 
#include<algorithm>
#include<vector>
#include<set> 
using namespace std;
const int maxn = 10010;
int n,k,b,id,temp;
//注意编号从1开始的
int father[maxn] ={0};
int isRoot[maxn] ={0};
//int course[maxn] ={0};
set<int> birds; 
int exist[maxn] = {0};

//而鸟就是不同的爱好
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
	//n只是树的情况，鸟的情况还未知 
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
	//打印树的个数	 && 打印鸟的个数
	//注意，这里是对所有的树进行的操作 
	for(int i=1;i<=maxn;i++){
		//根据鸟的编号进行遍历  
		if(exist[i] == 1){
			isRoot[findFather(i)]++;
		}
	}
	//鸟群的数目，通过判断领袖的个数 来计算鸟群的个数
	//同时通过isRoot可以判断每一个鸟群中的鸟的个数到底是多少 
	int numTrees = 0; 
	for(int i=1;i<=maxn;i++){
		//如果这个鸟是存在的，并且是领袖鸟 
		if(isRoot[i] != 0 && exist[i] == 1) numTrees++;
	}
	printf("%d %d\n",numTrees,birds.size());
	//查询 
	int q,ta,tb;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&ta,&tb);
		(findFather(ta) == findFather(tb))?printf("Yes\n"):printf("No\n");
	}
}
