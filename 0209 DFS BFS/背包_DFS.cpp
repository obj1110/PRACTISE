#include<iostream> 
#include<queue>
#include<stack>
using namespace std;

const int maxn  = 30;
//N代表物品的数目，W代表背包容量 
//W代表重量，包括最大重量，每一个物品的重量和当前的总重量
//V代表价值，包括每一个物品的价值，当前的总价值 

//index代表当前位于的岔路口 
int N,maxW,index =  0;
int w[maxn],v[maxn];
//死胡同比较器 
int maxValue=0;

//实时更新当前最大价值 
//可以看做是一根线，虽然是不断的分支，但是就是一条线不断的左偏右偏 
void DFS(int index,int sumW,int sumV) {
	//到达死胡同 
	if(index ==N) {
		//这里的目的是选择一个当前最大的死胡同 
		if(sumW <= maxW && sumV > maxValue) {
			maxValue = sumV;
		}
		return;
	} 
	//岔路口 
	DFS(index+1, sumW, sumV) ; //不选 
	DFS(index+1,sumW+w[index],sumV +v[index]); //选 
}

void DFS_1(int index , int sumW , int sumV ){
	if(index == N){
		if( sumW <= maxW && sumV > maxValue ){
			maxValue = sumV;
		}
		return;
	}
	DFS( index+1 , sumW , sumV );
	//剪枝 
	if(( sumw  + w[index] ) <= maxW ){
		DFS( index+1 , sumW+w[index] , sumV+v[index] );
	}
	//这里千万不要加上任何的return 
}

int main (){
	cin >> N >> maxW; 
	for(int i=0;i<N;i++) {
		scanf("%d",&w[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
	}
	DFS(0,0,0);
	printf("%d\n",maxValue);
	return 0;
}

//5 8
//3 5 1 2 2
//4 5 2 1 3
