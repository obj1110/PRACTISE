#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 110;
int father[maxn];
bool isRoot[maxn];

//���ȱ��������ڵ㣬Ȼ��Ӹ��ڵ���� 
int findFather(int x){
	if(x == father[x]) return x;
	else{
		int X = findFather(father[x]);
		father[x] = X;
		return X;
	}
}

void union(int x,int y) {
	int fa = findFather(x);
	int fb = findFather(y);
	
}

int main(){
	
	return 0;
} 

