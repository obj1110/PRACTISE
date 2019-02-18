//本身是树，树给你搞成一个邻接表的形式 

#include<iostream> 
#include<cstring>

using namespace std;
const int maxn = 25;
const int inf = 0xffffff; 

struct node{
	string data;
	int l,r;
}a[maxn];

//因为深度优先遍历，本身就是涉及到了一个栈 
string dfs(int root){
	//如果已经遍历到了叶子节点 
	if(a[root].l == -1 && a[root].r == -1){
		return a[root].data;
	}
	//如果右子树不是空的 
	if(a[root].l == -1 && a[root].r != -1){
		//时刻注意，你要构造的是一个中缀表达式 ，所以左子树先遍历，然后是中间，然后是右子树 
		return "(" + a[root].data + dfs(a[root].r) +")";
	}
	if(a[root].l != -1 && a[root].r == -1){
		return "(" + dfs(a[root].l) + a[root].data + ")";
	}
	if(a[root].l != -1 && a[root].r == -1){
		return "(" + dfs(a[root].l) + a[root].data + dfs(a[root].r) + ")";
	}
}

int n;
int main(){
	// 本题没有指明根节点，所以have数组是要用 
	int have[maxn] = {0};
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		//scanf对于string类型的读取是有问题的 
		cin >> a[i].data;
		getchar();
		scanf("%d %d",&a[i].l,&a[i].r);
		if(a[i].l != -1) have[a[i].l] = 1;
		if(a[i].r != -1) have[a[i].r] = 1;
	}
	
	int root=1;
	while(have[root] == 1 ) root++;
	
//	for(int i=1;i<=n ;i++){
//		cout<<"i :"<<i<<" "<< a[i].data <<" "<<a[i].l <<" "<<a[i].r<<endl;
//	}
	
	
	string ans = dfs(root);
	
	cout << ans;	
	return 0;
	
	
	// have数组的作用就是用来确定根节点的位置
	// 本题的输入就是按照数据 左孩子 右孩子的顺序进行的
	// 如果没有出现在左孩子或者右孩子中的节点，一定是根节点 
 
 	// 如果左子树不是空的 
	if(ans[0] == '(') {
		//一个是开始的位置，一个是截取的长度 
		ans = ans.substr(1,ans.size() -2 ) ;
	}

}
