#include<iostream> 
using namespace std;
const int maxn =11;
int n,P[maxn],hasht[maxn] = {false};

void gen(int index){
	//���ȴ��������������Ѿ����������
	//Ҳ������Ҫ������� 
	if(index == n+1) {
		for(int i=1;i<=n;i++){
			printf("%d",P[i]);
		}
		printf("\n");
		return;
	}
	for(int x= 1;x<=n;x++) {
		if(hasht[x]==false){
			P[index] = x;
			hasht[x] = true;
			gen(index +1);
			hasht[x] =false;
		}
	}
} 


int main(){
	n=3;
	gen(1);
	return 0;
}
