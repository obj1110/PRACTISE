//��ʼ���洢������ͼ����Ϣ��
//���������ж����Ƿ���ĳ��ͨ�����У�
//ʹ�ù�����ȱ�������ȫͼ����������ͨ��Ĵ�С��
//ɸѡ�������������ݲ���������
//��������������ֵ��


//˼·���Ǳ���ÿһ���㣬������ֵΪ1�Ľ���BFS����ֵΪ1�ĵ��¼������û�� 
#include<iostream> 
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//return sum; 
//t�������ֵ����������ֵ��2����Ҳ����˵��ĺ�������ҲҪ�������� 
int m,n,l,t,sum = 0;
//G��Ҫ�Ǽ�¼0������1��inq 
int G[1288][130][62],inq[1288][130][62];
//6��������ʵ��6������ 
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

//�����Ǽ����ֵ�ǲ���1 
int check(int x,int y,int z) {
//	Խ�� 
	if(x<0||x>=M||y<0||y>=N||z<0||z>=L){
        return 0;
    }
//    ��0�����Ѿ������� 
	if(G[x][y][z]==0||inq[x][y][z]==1){
        return 0;
    }
    return 1; 
} 

void BFS(int x,int y ,int z) {

}

int main() {
	init();
	//��ÿһ����Ԫ���б��� 
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
