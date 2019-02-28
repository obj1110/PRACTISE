//post和pre回复二叉树，并且随便输出一个中序序列

//读入前序遍历及后序遍历；
//根据两个遍历生成二叉树，并标记其是否唯一（如果左右子树一边不存在内容则不唯一，将其假设为出现在左子树上）；
//中序遍历生成的二叉树并记录中序遍历；
//根据题目要求输出结果并返回零值。

#include<iostream> 
#include<vector>
#include<stack>

using namespace std;

const int maxn = 35;
int n;
int pre[maxn],post[maxn],mid[maxn];

void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",mid[i]);
	}
}

//观察pre和post的结果可知
//pre的第一个元素是post的最后一个元素，二者都是树的根节点
//pre的第二个元素一定也是某一个子树的根节点，在后序序列中找到这个点，这个点之前的东西一定都是这个树的子树 

int main(){
	init();
	
}
