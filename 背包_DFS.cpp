#include<iostream> 
#include<queue>
#include<stack>
using namespace std;

const int maxn  = 30;
//N������Ʒ����Ŀ��W���������� 
//W�����������������������ÿһ����Ʒ�������͵�ǰ��������
//V�����ֵ������ÿһ����Ʒ�ļ�ֵ����ǰ���ܼ�ֵ 

//index����ǰλ�ڵĲ�·�� 
int N,maxW,index =  0;
int w[maxn],v[maxn];
//����ͬ�Ƚ��� 
int maxValue=0;

//ʵʱ���µ�ǰ����ֵ 
//���Կ�����һ���ߣ���Ȼ�ǲ��ϵķ�֧�����Ǿ���һ���߲��ϵ���ƫ��ƫ 
void DFS(int index,int sumW,int sumV) {
	//��������ͬ 
	if(index ==N) {
		//�����Ŀ����ѡ��һ����ǰ��������ͬ 
		if(sumW <= maxW && sumV > maxValue) {
			maxValue = sumV;
		}
		return;
	} 
	//��·�� 
	DFS(index+1, sumW, sumV) ; //��ѡ 
	DFS(index+1,sumW+w[index],sumV +v[index]); //ѡ 
}

void DFS_1(int index , int sumW , int sumV ){
	if(index == N){
		if( sumW <= maxW && sumV > maxValue ){
			maxValue = sumV;
		}
		return;
	}
	DFS( index+1 , sumW , sumV );
	//��֦ 
	if(( sumw  + w[index] ) <= maxW ){
		DFS( index+1 , sumW+w[index] , sumV+v[index] );
	}
	//����ǧ��Ҫ�����κε�return 
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
