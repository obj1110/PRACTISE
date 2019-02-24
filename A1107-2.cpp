#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring> 
using namespace std;
const int maxn = 1010;
int father[maxn];
int isRoot[maxn] = {0};
int course[maxn] = {0};

int findFather(int x){
	if(x == father[x]){
		return x;
	}
	else{
		int X = findFather(father[x]);
		father[x] = X;
		return X;
	}
}

void union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb){
		father[fa] = fb;
	}
}
void init(int n){
	for(int i=1;i<=n;i++){
		father[i] = i;
		isRoot[i] = false;
	}
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int n,k,h;
	scanf("%d",&n);
	init(n);
	for(int i = 1;i<=n;i++){
		scanf("%d:",&k);
		for(int j = 0;j<k;j++){
			scanf("%d",&h);
			if(course[h] == 0){
				course[h] = i;
			}
			//�ϲ�����������Ⱥ�ļ��ϣ��ϲ�֮�������Ⱥ�ļ��� 
			union(i,findFather(course[h]));
		}
	}
	for(int i = 1;i<=n;i++) {
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	//isRoot��Ϊ0�ĸ����������յ���Ⱥ�ĸ��� 
	for(int i =1;i<=n;i++){
		if(isRoot[i] != 0){
			ans++;
		}
	}
	printf("%d\n",ans);
	//isRoot���������Ŀ�ģ������� 
	sort(isRoot +1,isRoot +n+1,cmp);
	for(int i=1;i<=ans;i++){
		printf("%d",isRoot[i]);
		if( i <ans )printf(" ");
	}
	return 0;
}
