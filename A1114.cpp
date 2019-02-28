//һ���˵�id��һ���˵ĸ�ĸ��id�����������������һ���˵ĺ��ӵ���Ŀ������0���������һ���˵ĺ��ӵ�id���Լ��Ǽ������id����ķ�������Ŀ�ͷ���������� 
#include<iostream>
#include<algorithm> 
#include<cstring>
#include<cstdlib>
#include<set>

using namespace std;

//����һ���������� 
struct data{
	//num�Ƿ�������Ŀ
	//area�Ƿ���������� 
	int id,fid,mid,num,area;
	int cid[10];	
	//cid����һ�������µĺ��ӵ�id��� 
}data[1010];

//������壬��Ϊid����������9999������10000�����ݿ϶��ǹ��� 
struct node{
	int id,people;
	double num,area;
	bool flag = false;
}ans[10000];


int father[10000];
bool visit[10000];
//n�Ǽ�¼���ܸ�����k�Ǻ��ӵ��ܸ�����Ϊ0����cnt�Ǽ�������õı��� 
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

//�˾�����Ľ������ƽ�֣�����id������ 
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
		//�������������һ��һ�����д���
		//����Ҫ���ľ��ǰ�������������һ����������
		//Ҳ����ͳһ�ӵ��ְֵ����ݿ��� 
		int id = find(data[i].id);
		ans[id].id = id;
		ans[id].num += data[i].num;
		ans[id].area += data[i].area;
		ans[id].flag = true;
	}
}

void process(){
	for(int i=0;i<10000;i++){
		//ͳ��ÿһ����������� 
		if(visit[i]){
			ans[find(i)].people++;
		}
		//cntͳ�Ƶ��Ǽ������Ŀ 
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
	//����ĸ�ʽ�������id��������������id��С�ģ�Ȼ��������Ǽ����Ա����
	//Ȼ���������ÿ����ƽ���ķ�����Ŀ��ÿ����ƽ�������
	init();	
	pre_process();
	process();
	calculate();
	print();
}
