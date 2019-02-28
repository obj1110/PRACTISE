//初始化存储并读入图像信息；
//建立程序判断其是否在某联通区域中；
//使用广度优先遍历遍历全图，并计算连通域的大小；
//筛选符合条件的数据并加入结果；
//输出结果并返回零值。


//思路就是遍历每一个点，对于数值为1的进行BFS，数值为1的点记录遍历过没有 
#include<iostream> 
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//return sum; 
//t是体积阈值，如果你的阈值是2，那也就是说你的核心最少也要有两个点 
int m,n,l,t,sum = 0;
//G主要是记录0或者是1，inq 
int G[1288][130][62],inq[1288][130][62];
//6个方向，其实是6组增量 
int X[6]={-1,1,0,0,0,0},Y[6]={0,0,-1,1,0,0},Z[6]={0,0,0,0,-1,1};
struct Node{
	int x,y,z;
};

void init(){
	int i,j,k;
	scanf("%d %d %d %d",&m,&n,&l,&t);
	for(int k =0 ;k<l;k++){
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++){
				scanf("%d",&G[i][j][k]);
			}
		}
	}
}

//作用是检查点的值是不是1 
int check(int x,int y,int z) {
//	越界 
	if(x<0||x>=M||y<0||y>=N||z<0||z>=L){
        return 0;
    }
//    是0或者已经便利过 
	if(G[x][y][z]==0||inq[x][y][z]==1){
        return 0;
    }
    return 1; 
} 

void BFS(int x,int y ,int z) {

}

int main() {
	init();
	//对每一个像元进行遍历 
    for(int k=0;k<L;k++){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(check(i,j,k)){
                    BFS(i,j,k);
                }
            }
        }
    }
    printf("%d\n",sum);
}
