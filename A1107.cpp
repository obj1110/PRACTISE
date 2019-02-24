#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1010;
int father[maxn];
int isRoot[maxn] = {0};
int course[maxn] = {0};
//也就是说这里面存在两组编号，一组编号是人，另外一组编号是爱好。但是由于都是数字所以容易让人混淆  
//course数组中的key值的含义和father数组中的key值的含义是完全不一样的
//course数组本身就是喜欢任意以一个活动h的人的编号
//isRoot数组本身记录的是当前key值是不是根节点？？？？ 
// father数组记录的是某一个人喜欢的爱好

int findFather(int x){
	if(x == father[x]){
		return x ;
	} 
	else{
		int X = findFather(father[x]);
		father[x] = X;
		return X;
	}
}
void Union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb){
		father[fa] = fb; 
	}
}
void init(int n){
	for(int i= 1 ;i<=n;i++){
		father[i] = i;
		isRoot[i] = false;
	}
}
bool cmp(int a,int b) {
	return a>b; 
} 

int main(){
	int n,k,h;
	scanf("%d",&n); 
	init(n);
	for(int i =1;i<=n;i++){
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&h);
			//course数组指向的是喜欢这个爱好的随机的一个人，
			//由于人的编号从1开始
			//所以默认的course[i]的值为0的时候就是说这个数组没有任何的指向的意思 
			if(course[h] == 0){
				//随机指向某个爱好为h的人 
				//爱好是h，然后这个人的编号是i 
				course[h] = i;
			}
			Union(i,findFather(course[h]));
		}
	}
	//isRoot不为0的个数就是最终的人群的个数 
	for(int i= 1 ;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(isRoot[i] != 0 ){
			ans++;
		}
	}
	printf("%d\n",ans);
	sort(isRoot +1, isRoot+n+1,cmp);
	for(int i =1;i<= ans;i++){
		printf("%d",isRoot[i]);
		if(i <ans) printf(" ");
	}
	return 0;
}
