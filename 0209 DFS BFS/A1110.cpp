//判断是不是一个完全二叉树
#include<iostream> 
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;

struct node{
	int l,r; 
}a[100];

int n,root = 0
int have[100] = {0};
int maxn = -1,ans;
char l_tree,r_tree;

void dfs(int root,int index){
	if(index > maxn ){
		maxn = index;
		ans = root;
	}
	//如果左子树不是空的 
	if(a[root].l != -1) dfs(a[root].l,index*2) ;
	//如果右子树不是空的 
	if(a[root].r != -1) dfs(a[root].r,index*2+1);
}

void init(){
	scanf("%d",&n);
	for(int i =0;i<n ;i++) {
		scanf("%c %c",&l_tree,&r_tree);
		if(r == "-"){
			a[i].r = -1;
		}
		else{
			a[i].r  = r - '0';
			have[r - '0'] = 1;
		}
		if(l =="-"){
			a[i].l = - 1;
		}
		else{
			a[i].l  = l - '0';
			have[l - '0'] = 1;
		}
	}
	
	//
	while(have[root] != 0) root++;
	dfs(root,1);
	if(maxn == n){
		cout<<"YES "<<ans;
	}
	else{
		cout<<"NO "<<root;
	}
	return 0;
}

int main(){
		 
	return 0;
} 
