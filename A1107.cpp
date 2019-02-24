#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1010;
int father[maxn];
int isRoot[maxn] = {0};
int course[maxn] = {0};
//Ҳ����˵��������������ţ�һ�������ˣ�����һ�����ǰ��á��������ڶ������������������˻���  
//course�����е�keyֵ�ĺ����father�����е�keyֵ�ĺ�������ȫ��һ����
//course���鱾�����ϲ��������һ���h���˵ı��
//isRoot���鱾���¼���ǵ�ǰkeyֵ�ǲ��Ǹ��ڵ㣿������ 
// father�����¼����ĳһ����ϲ���İ���

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
			//course����ָ�����ϲ��������õ������һ���ˣ�
			//�����˵ı�Ŵ�1��ʼ
			//����Ĭ�ϵ�course[i]��ֵΪ0��ʱ�����˵�������û���κε�ָ�����˼ 
			if(course[h] == 0){
				//���ָ��ĳ������Ϊh���� 
				//������h��Ȼ������˵ı����i 
				course[h] = i;
			}
			Union(i,findFather(course[h]));
		}
	}
	//isRoot��Ϊ0�ĸ����������յ���Ⱥ�ĸ��� 
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
