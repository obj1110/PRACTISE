#include<iostream> 
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<time.h>

using namespace std;

const int size = 1000100;

int main() {
	//�������ʹ��һ����Ҫָ�������������
	//��һ��������һ�����ɺ��� 
	srand((unsigned)time(NULL));
	int n = 10;
	for(int i =0;i<n;i++){
		printf("%d\n",rand());
	}
	int a = 10;
	int b = 99;
	//ָ�����ɶ�λ�������
	int rand_number = rand()%(b-a+1) + a;
	cout<<rand_number; 
	
	//
	a = 0;
	b = 1;
	for(int i =0;i<10;i++) {
		printf("%d ",rand()%(b- a+1) +a);
	}
	//
	for(int i=0;i<10;i++){
		printf("%d",rand()%(b-a+1 )+a);
	} 
	//
	for (int i=0;i<10;i++){
		//��סRAND_MAX 
		printf("%d",(int)(round(1.0*rand()/RAND_MAX*50000 + 10000)));
	}
	return 0;
}
