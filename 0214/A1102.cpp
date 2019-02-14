#include<iostream> 
#include<vector>
#include<string>
#include<cstring>
using namespace std;

//0~~n-1进行节点的编号 
int n;

struct node{
	node* lchild;
	node* rchild;
	int data ;
	int vis;
};

void init(){
	scanf("%d",&n);
	char a,b;
	for(int i=0;i<n;i++){
		scanf("%c %c",&a,&b);
	}
} 




int main(){
	
	return 0;
}
