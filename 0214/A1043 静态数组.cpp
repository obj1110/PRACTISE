#include<iostream> 
#include<vector>
using namespace std;

bool isMirror = false;
vector<int> pre,post;
//获得一个序列的后序序列 
void getpost(int root,int tail){
	if(root > tail)  return;
	//两个工作指针 
	int i =root +1, j = tail;
	if( !isMirror) {
		//对二叉排序树的做法 
		while(i <= tail && pre[root] > pre[i]) i++;
		while(j > root && pre[root] <= pre[j]) j--;
	}//对镜像树的做法
	else{
		while( i<= tail && pre[root] <= pre[i]) i++;
		while( j> root && pre[root] > pre[j] ) j--;
	} 
	//将一个序列分解成为两部分，进而确定根节点
	//就是说，也是一个递归的过程， 
	if(i-j != 1) return;
	//处理左子树 
	getpost(root+1 ,j);
	//处理右子树 
	getpost(i,tail);
	//增加到后续序序列里面去 
	post.push_back(pre[root]);
}

int main() {
	int n;
	cin >> n;
	pre.resize(n);
	for(int i=0; i<n;i++){
		cin>>pre[i];
	}
	getpost(0,n-1);
	if(post.size() != n){
		isMirror = true;
		post.clear();
		getpost(0,n-1);
	}
	if(post.size() == n){
		printf("YES\n%d",post[i]);
		for(int i =1;i<n;i++){
			printf(" %d",post[i]);
		}
		else{
			printf("NO");
		}
	}
	return 0;
}

