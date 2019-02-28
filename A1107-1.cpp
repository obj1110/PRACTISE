#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn];
int isRoot[maxn] ={0}; // ͳ�������õ� 
int course[maxn] ={0}; // ϲ��������õ�����һ���� 

int findfather(int x){
	if(father[x] == x ) return x;
	else{
		int X = father[x];
		father[x] = X;
		return X;
	}
}

void union(int x,int y){
	int fa = findfather(x);
	int fb = findfather(y);
	if(fa != fb){
		return father[fa] = fb;
	}
}

void init(){
	for(int i = 1;i<=n;i++) {
		father[i] = i;
		isRoot[i] = false;
	}
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
		
	return 0;
}
