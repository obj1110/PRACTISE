#include<iostream>
#include<cmath>

//1000�ӣ�10�ˣ�100��
//����ɼ���ߵĶ��� 
using namespace std;

const int maxsize = 1010;
int score[maxsize]={0};

int main(){
	int n;
	scanf("%d",&n);	
	int a,b,c;
	int maxscore = -1;
	int bestteam = -1; 
	for(int i=0;i<n;i++){
		scanf("%d-%d %d",&a,&b,&c);
		score[a] += c;
		if(score[a] >maxscore){
			bestteam = a;
			maxscore = score[a];
		}
	}
	printf("%d %d",bestteam,maxscore);
}
