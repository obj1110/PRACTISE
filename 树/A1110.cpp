//这里面有两套系统，一个是节点的编号系统，一个是数组存储空间的编号系统
//由于节点编号没有啥意义，所以要额外的记录这个树的最大占用空间，也就是maxnum和index 


#include<iostream> 
#include<algorithm>
using namespace std;

const int maxn = 25;
int n;
char a[5];
char b[5];
int adj[maxn][2];
int isRoot[maxn]={0};

void init(){
	//要考虑输入的是不是字母，
	//所以首先要用字符串的形式进行输入，确定不是字符串之后，再进行数字的转化 
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%s %s",a,b); 
		if(a[0] == '-'){
			adj[i][0] = -1;	
		} 
		else{
			int ans = stoi(a);
			adj[i][0] = ans;
			isRoot[ans]++;
		}
		if(b[0] == '-'){
			adj[i][1] = -1;
		}
		else{
			int ans = stoi(b);
			adj[i][1] = ans;
			isRoot[ans]++;
		}
	} 	
}

int findRoot(){
	int i=0;
	while(isRoot[i] != 0) i++;
	return i;
}
//index和maxnum都是数组空间上面的东西
//index就是你当前在数组的哪一个空间
//至于说ans，那就是顺便找一找最后的节点 
int maxnum = -1;
int ans;

void InOrder(int root,int index){
//	cout<<index<<endl;
	if(index > maxnum){
		maxnum = index;
		ans = root;
	}
	if(adj[root][0] !=-1) InOrder(adj[root][0],index*2+1); 
//	cout<<root<<endl;
	if(adj[root][1] !=-1) InOrder(adj[root][1],index*2+2);
}
int main(){
	init();
	int root = findRoot();	
	
	InOrder(root,0);
	
	//maxnum线就是你所涉及到的磁盘的大小情况
	//而和maxnum搭配的就是节点个数
	//在遍历的过程中，不断的考虑当前所涉及到的空间最大值
	//如果遍历的空间的最大值 和 节点数相等，说明是完全二叉树 
	if(maxnum >= n){
		cout<<"NO "<<root;
	}
	else if(maxnum +1 ==  n){
		cout<<"YES "<<ans;	
	}
	return 0;
} 
