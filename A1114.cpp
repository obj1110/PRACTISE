//一个人的id，一个人的父母的id（存在死亡情况），一个人的孩子的数目（存在0的情况），一个人的孩子的id，以及登记在这个id下面的房产的数目和房产的总面积 
#include<iostream>
#include<algorithm> 
#include<cstring>
#include<cstdlib>
#include<set>

using namespace std;

//代表一条输入数据 
struct data{
	//num是房产的数目
	//area是房产的总面积 
	int id,fid,mid,num,area;
	int cid[10];	
	//cid就是一个人名下的孩子的id序号 
}data[1010];

//代表家族，因为id的情况是最大9999，所以10000个数据肯定是够了 
struct node{
	int id,people;
	double num,area;
	bool flag = false;
}ans[10000];


int father[10000];
bool visit[10000];
//n是记录的总个数，k是孩子的总个数（为0），cnt是家族计数用的变量 
int n,k,cnt = 0; 


int find(int x){
	if(x == father[x]){
		return x;
	}
	else{
		int ax = find(father[x]);
		father[x] = ax; 
		return ax;	
	}
}

void Union(int a,int b){
	int fa = find(a);
	int fb = find(b);
	if(fa != fb){
		father[fa] = fb;
	}
}

//人均面积的降序，如果平局，就是id的增序 
int cmp1(node a,node b){
	if(a.area != b.area){
		return a.area > b.area;
	}
	else{
		return a.id < b.id;
	}
}

void init(){
	scanf("%d",&n);
	for(int i=0;i<10000;i++){
		father[i] = i;
	}
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&data[i].id,&data[i].fid,&data[i].mid,&k);
		visit[data[i].id] = true;
		if(data[i].fid != -1){
			visit[data[i].fid] = true;
			Union(data[i].fid,data[i].id);
		}
		if(data[i].mid != -1) {
			visit[data[i].mid] = true;
			Union(data[i].mid,data[i].id);
		}
		for(int j = 0;j<k;j++){
			scanf("%d",&data[i].cid[j]);
			visit[data[i].cid[j]] = true;
			Union(data[i].cid[i],data[i].id);
		}
		scanf("%d %d",&data[i].num,&data[i].area);
	}
} 

void pre_process(){
	for(int i=0;i<n;i++){
		//对于输入的数据一条一条进行处理
		//首先要做的就是把输入数据整理到一个家族里面
		//也就是统一加到爸爸的数据库中 
		int id = find(data[i].id);
		ans[id].id = id;
		ans[id].num += data[i].num;
		ans[id].area += data[i].area;
		ans[id].flag = true;
	}
}

void process(){
	for(int i=0;i<10000;i++){
		//统计每一个家族的人数 
		if(visit[i]){
			ans[find(i)].people++;
		}
		//cnt统计的是家族的数目 
		if(ans[i].flag){
			cnt++;
		}
	} 
}

void calculate() {
	for(int i=0;i<10000;i++){
		if(ans[i].flag){
			ans[i].num = (double)(ans[i].num*1.0/ans[i].people);
			ans[i].area = (double)(ans[i].area*1.0/ans[i].people);
		}
	}
}

void print(){
	sort(ans,ans+10000,cmp1);
	printf("%d\n",cnt); 
	for(int i=0;i<cnt;i++){
		printf("%04d %d %0.3f %0.3f\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area);
	}
}

int main(){
	//输出的格式，输出的id是整个家族里面id最小的，然后输出的是家族成员个数
	//然后输出的是每个人平均的房产数目和每个人平均的面积
	init();	
	pre_process();
	process();
	calculate();
	print();
}
