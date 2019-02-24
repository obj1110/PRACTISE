#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 110;
int father[maxn];
bool isRoot[maxn];

//首先遍历到根节点，然后从根节点回来 
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

