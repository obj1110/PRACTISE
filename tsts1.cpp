#include<iostream>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;
const int maxn = 25;
const int inf = 0xffffff;

struct node{
	int l,r;
	string data;
}a[maxn];

string dfs(int index){
	if( a[index].l == -1 && a[index].r == -1 ) return a[index].data;
	if( a[index].l != -1 && a[index].r == -1 ) return "(" + dfs(a[index].l) + a[index].data + ")";
	if( a[index].l == -1 && a[index].r != -1 ) return "(" + a[index].data + dfs (a[index].r) + ")" ;
	if( a[index].l != -1 && a[index].r != -1 ) return "(" + dfs(a[index].l) + a[index].data + dfs(a[index].r) +")";
}

int main(){
	int n;
	int have[maxn] = {0};
	scanf("%d",&n);
	for(int i=1 ; i <= n ; i++){
		cin>> a[i].data;
		getchar();
		scanf("%d %d",&a[i].l,&a[i].r);
		if(a[i].l != -1 ) have[a[i].l] = 1;
		if(a[i].r != -1 ) have[a[i].r] = 1;
	}
	
	int root = 1;
	while(have[root] != 0) root++;
	
	string ans = dfs(root);
	if(ans[0] == '(') ans = ans.substr( 1  ,  ans.size()-2 );
//	if(strcmp(ans[0],"(")) ans = ans.substr( 1  ,  ans.size()-2 );
//	if(ans[0] == "(") ans = ans.substr( 1  ,  ans.size()-2 );
	cout<<ans;
	return 0;
}
