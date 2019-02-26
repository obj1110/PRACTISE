#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1010;

int n,k,h;
int father[maxn];        //这人的人群的领袖是谁 
int isRoot[maxn] = {0};  //这个人是不是这些人的领袖 
int course[maxn] = {0};  //这个爱好有谁喜欢
 
//也就是说这里面存在两组编号，一组编号是人，另外一组编号是爱好。
//但是由于都是数字所以容易让人混淆  

//course:key 爱好 value：人的编号
//isRoot：key人的编号 value:是不是根节点，不是根节点代表是一个爱好群
//father:key 人的编号 value：人的编号？？？
 
//路径压缩 
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
//union是关键字，容易出错的 
void Union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb){
		father[fa] = fb; 
	}
}
void init(){
	scanf("%d",&n); 
	for(int i= 1 ;i<=n;i++){
		father[i] = i;
		isRoot[i] = false;
	}
	for(int i =1;i<=n;i++){
		//i就是当前的人的编号 
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			//h就是爱好 
			scanf("%d",&h);
			//输入的是某一个人喜欢的一堆爱好
			//为0就是说当前喜欢这个爱好的人还未知 
			if(course[h] == 0){
				//随机指向某个爱好为h的人 
				//爱好是h，然后这个人的编号是i 
				course[h] = i;
			}
			//第一次的union毫无意义，但是无妨
			//第二次的union将喜欢某一个爱好的人，和喜欢这个爱好的人群进行合并
			//但是你会发现，一个人会喜欢很多的爱好，我怎么确定说他会不会同时属于好几个人群
			//本题不会那么复杂。。。。但是一个人群会喜欢好几个爱好 
			Union(i,findFather(course[h]));
		}
	}
}
bool cmp(int a,int b) {
	return a>b; 
} 

int main(){
	init();
	//isRoot的初始化数值都是false,后来越来越大 
	//isRoot不为0的个数就是最终的人群的个数 
	//这个循环就是赋值isRoot数组，方式不是true或者false，而是说这个领袖级别的人物
	//到底是多少人的爸爸。。。。。 
	for(int i= 1 ;i<=n;i++){
		//对于每一个节点，找到它的爸爸，然后让它爸爸+1; 
		isRoot[findFather(i)]++;
	}
	//开始统计领袖到底有几个 
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(isRoot[i] != 0 ){
			ans++;
		}
	}
	printf("%d\n",ans);
	//根据输出调整格式 
	sort(isRoot +1, isRoot+n+1,cmp);
	//降序排列 
	for(int i =1;i<= ans;i++){
		printf("%d",isRoot[i]);
		//打印每个族群的爱好的人数 
		if(i <ans) printf(" ");
	}
	return 0;
}
